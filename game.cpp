#include"game.h"
#include<cstdio>

    Game::Game(const vector<string>& playerNames) : board(), currentPlayerIndex(0), isPaused(false) {
        gameId = generateGameId();
        cout << "Here game id  is : " << gameId << endl;
        for (const string& name : playerNames) {
            players.push_back(Player(name));
        }
    }

    Game::~Game() { cout << "Game object with ID " << gameId << " is being destroyed.\n"; }

    string Game::generateGameId()
    {   
        ifstream in("GameID.txt");
        int idCounter;
        in >> idCounter;
        in.close();
        stringstream ss;
        ss << "Game-" << idCounter;
        idCounter++;
        ofstream out("GameID.txt");
        out << idCounter;
        out.close();

        return ss.str();
    }

    int Game::rollDice()
    {
        return rand() % 6 + 1;
    }

    void Game::playTurn()
    {
        Player& currentPlayer = players[currentPlayerIndex];
        bool canRollAgain = true;

        while (canRollAgain) {
            int diceRoll = rollDice();
            currentPlayer.move(diceRoll);
            currentPlayer.position = board.applySnakeOrLadder(currentPlayer.position);

            board.displayBoard(players);

            cout << endl;
            int color = currentPlayer.player_number + 40;

            cout << "\033[" << color << "m";

            cout <<  currentPlayer.name;

            cout << "\033[0m";
            cout << " rolled a " << diceRoll << endl;

            cout << "Current position: " << currentPlayer.position << endl;

            if(currentPlayer.position == 100){
                cout << "\033[" << color << "m";
                cout << currentPlayer.name;
                cout << "\033[0m";
                cout << " wins the game!" << endl;

                const string d = gameId+".txt";
                
                int res = remove(d.c_str());
                if(res){
                    cout << "Not handling" << endl;
                }
                else{
                    cout << "File removed" << endl;
                }
                
                isPaused = true;
                return;
            }

            cout << "Press '1' to continue to the next turn or '2' to pause and return to menu: ";
            string input;
            getline(cin, input);

            if (input == "2") {
                saveGame();
                cout << "Game paused. Returning to the menu...\n";
                isPaused = true;
                return;
            }

            canRollAgain = currentPlayer.handleConsecutiveSixes(diceRoll);
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    void Game::saveGame()
    {
        try {
            ofstream outFile(gameId + ".txt");
            if (!outFile) {
                throw runtime_error("Error: Unable to open the file for saving.");
            }

            outFile << gameId << endl;
            outFile << players.size() << endl;

            for (const auto& player : players) {
                outFile << player.serialize() << endl;
            }

            outFile << board.serialize();
            outFile.close();
            cout << "Game saved as " << gameId << ".txt\n";
            Player::count = 1;
        } catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }

    void Game::loadGame(const string &gameFile)
    {
        try {
            ifstream inFile(gameFile);
            if (!inFile) {
                throw runtime_error("Error: Could not load the game file.");
            }

            string loadedGameId;
            int numPlayers;
            inFile >> loadedGameId;
            inFile >> numPlayers;
            players.clear();

            string playerData;
            getline(inFile, playerData);
            cout << "Check player Data1  : ";
            cout << playerData << endl;

            for (int i = 0; i < numPlayers; ++i) {
                getline(inFile, playerData);
                cout << "Check player Data  : ";
                cout << playerData << endl;
                players.push_back(Player::deserialize(playerData));
            }

            string boardData;
            stringstream boardStream;
            while (getline(inFile, boardData)) {
                boardStream << boardData << endl;
            }
            board.deserialize(boardStream.str());

            inFile.close();
            gameId = loadedGameId;
            cout << "Game loaded: " << gameId << endl;
            board.displayBoard(players);
            isPaused = false;
        } catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }

    void Game::startGame()
    {
        cout << "Starting game with ID: " << gameId << endl;
        while (!isPaused) {
            playTurn();
        }
        
    }

    // void Game::displayMenu()
    // {
    //     string input;
    //     while (true) {
    //         cout << "1. Start New Game\n";
    //         cout << "2. Load Saved Game\n";
    //         cout << "3. Quit\n";
    //         cout << "Enter your choice: ";
    //         getline(cin, input);

    //         if (input == "1") {
    //             int numPlayers;
    //             cout << "Enter the number of players (2 to 4): ";
    //             cin >> numPlayers;
    //             cin.ignore();
    //             if (numPlayers < 2 || numPlayers > 4) {
    //                 cout << "Please enter a valid number of players (2 to 4).\n";
    //                 continue;
    //             }

    //             vector<string> playerNames;
    //             for (int i = 0; i < numPlayers; ++i) {
    //                 string name;
    //                 cout << "Enter player " << i + 1 << " name: ";
    //                 getline(cin, name);
    //                 playerNames.push_back(name);
    //             }

    //             Game* newGame;
    //             newGame = new Game(playerNames);
    //             newGame->startGame();
    //             delete newGame;
    //             cout << "deleted" << endl;
    //             if(newGame == NULL){
    //                 cout << "NULL" << endl;
    //             }
    //         } else if (input == "2") {
    //             string gameFile;
    //             cout << "Enter the game ID to load (e.g., Game-1.txt): ";
    //             getline(cin, gameFile);
    //             loadGame(gameFile);
    //             startGame();
    //         } else if (input == "3") {
    //             cout << "Goodbye!\n";
    //             break;
    //         } else {
    //             cout << "Invalid input, try again.\n";
    //         }
    //     }
    // }

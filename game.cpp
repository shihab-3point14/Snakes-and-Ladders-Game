#include"game.h"

    Game::Game(const vector<string>& playerNames) : board(), currentPlayerIndex(0), isPaused(false) {
        gameId = generateGameId();
        for (const string& name : playerNames) {
            players.push_back(Player(name));
        }
    }

    Game::~Game() { }

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
        return (rand()%6) + 1;
    }

    void Game::playTurn()
    {
        Player& currentPlayer = players[currentPlayerIndex];
        bool canRollAgain = true;

        while (canRollAgain) {
            int diceRoll = rollDice();
            if(currentPlayer.position == 0){
                if(diceRoll == 1){
                    currentPlayer.move(diceRoll);
                }
                
            }
            else{
                currentPlayer.move(diceRoll);
                
            }
            if(diceRoll != 6)
            currentPlayer.position = board.applySnakeOrLadder(currentPlayer.position);

            board.displayBoard(players);

            cout << endl;
            int color = currentPlayer.player_number + 40;

            cout << "\033[" << color << "m";

            cout <<  currentPlayer.name;

            cout << "\033[0m";
            cout << " rolled a " << diceRoll << endl;

            canRollAgain = currentPlayer.handleConsecutiveSixes(diceRoll);

            cout << "Current position: " << currentPlayer.position << endl;


            if(currentPlayer.position == 100){
                cout << endl << endl;
                cout << "\033[" << color << "m";
                cout << currentPlayer.name;
                cout << "\033[0m";
                cout << " wins the game!" << endl;
                cout << endl << endl;

                const string d = gameId+".txt";
                
                int res = remove(d.c_str());

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

            if(currentPlayer.position == 0){
                canRollAgain = false;
            }

            
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

            for (int i = 0; i < numPlayers; i++) {
                getline(inFile, playerData);
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


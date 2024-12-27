#include"menu.h"

void menu::show(){
    string input;
    while (true)
    {
        cout << "1. Start New Game" << endl;
        cout << "2. Load Saved Game" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        getline(cin, input);

        if (input == "1")
        {
            string numPlayers;
            cout << "Enter the number of players (2 to 4): ";
            cin >> numPlayers;
            cin.ignore();

            if(numPlayers != "2" && numPlayers != "4" && numPlayers != "3")
            {
                cout << "Please enter a valid number of players (2 to 4).\n";
                continue;
            }
            int num = stoi(numPlayers);
            vector<string> playerNames;
            for (int i = 0; i < num; ++i)
            {
                string name;
                cout << "Enter player " << i + 1 << " name: ";
                getline(cin, name);
                playerNames.push_back(name);
            }

            Game *newGame;
            newGame = new Game(playerNames);
            newGame->startGame();
            delete newGame;
            
        }
        else if (input == "2")
        {
            string gameFile;
            cout << "Enter the game ID to load (e.g., Game-1.txt): ";
            getline(cin, gameFile);
            Game *newGame = new Game({});
            newGame->loadGame(gameFile);
            newGame->startGame();
            delete newGame;
        }
        else if (input == "3")
        {   
            cout << endl;
            cout << "Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid input, try again.\n";
        }
    }
}
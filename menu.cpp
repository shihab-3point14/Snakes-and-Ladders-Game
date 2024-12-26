#include"menu.h"

void menu::show(){
    string input;
    while (true)
    {
        cout << "1. Start New Game\n";
        cout << "2. Load Saved Game\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        getline(cin, input);

        if (input == "1")
        {
            int numPlayers;
            cout << "Enter the number of players (2 to 4): ";
            cin >> numPlayers;
            cin.ignore();
            if (numPlayers < 2 || numPlayers > 4)
            {
                cout << "Please enter a valid number of players (2 to 4).\n";
                continue;
            }

            vector<string> playerNames;
            for (int i = 0; i < numPlayers; ++i)
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
            cout << "deleted" << endl;
            if (newGame == NULL)
            {
                cout << "NULL" << endl;
            }
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
            cout << "Game deleted" << endl;
        }
        else if (input == "3")
        {
            cout << "Goodbye!\n";
            break;
        }
        else
        {
            cout << "Invalid input, try again.\n";
        }
    }
}
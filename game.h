#include"SnakesAndLadderBoard.h"

class Game
{
private:
    vector<Player> players;
    SnakesAndLaddersBoard board;
    int currentPlayerIndex;
    string gameId;
    bool isPaused;

public:
    Game(const vector<string> &playerNames);

    string generateGameId();

    int rollDice();

    void playTurn();

    void saveGame();

    void loadGame(const string &gameFile);

    void startGame();

    void displayMenu();
};

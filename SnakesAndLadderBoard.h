
#include"board.h"


class SnakesAndLaddersBoard : public Board
{
private:
    vector<pair<pair<int, int>, char>> snakesAndLadders;
    // vector<pair<int, char>> snakesAndLadders;

public:
    SnakesAndLaddersBoard(int size = 10);
    void displayBoard(vector<Player> &players) override;

    void initializeBoard();
    int applySnakeOrLadder(int position);

    string serialize() const override;

    void deserialize(const string &data) override;
};
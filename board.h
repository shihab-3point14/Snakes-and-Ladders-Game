
#include"player.h"


class Board
{
public:
    vector<vector<int>> grid;


    Board(int size = 10);

    virtual void displayBoard(vector<Player> &players) = 0;

    int getSize() const;

    virtual string serialize() const;

    virtual void deserialize(const string &data){}
};
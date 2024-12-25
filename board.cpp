#include"board.h"




    Board::Board(int size)
    {
        grid.resize(size, vector<int>(size));
    }



    int Board:: getSize() const
    {
        return grid.size();
    }

    string Board::serialize() const
    {
        return "";
    }

    

#include"SnakesAndLadderBoard.h"
//#include<windows.h>

SnakesAndLaddersBoard::SnakesAndLaddersBoard(int size) : Board(size)

{
    initializeBoard();
}

void SnakesAndLaddersBoard::displayBoard(vector<Player> &players)
{   
    //HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int number = 100;
    for (int i = getSize() - 1; i >= 0; --i)
    {
        if ((getSize() - 1 - i) % 2 == 0)
        {
            for (int j = 0; j < getSize(); ++j)
            {
                grid[i][j] = number--;
            }
        }
        else
        {
            for (int j = getSize() - 1; j >= 0; --j)
            {
                grid[i][j] = number--;
            }
        }
    }

    cout << "\n-----------------------------------------------------------\n";
    for (int i = getSize() - 1; i >= 0; --i)
    {
        for (int j = 0; j < getSize(); ++j)
        {
            int currentPos = grid[i][j];
            bool playerFound = false;

            for (const auto &player : players)
            {
                if (player.position == currentPos)
                {   
                    
                    
                    int color = player.player_number + 40;

                    
                    cout << "[";
                    cout << "\033[" << color << "m " << "O" << " ";
                    cout << "\033[0m" << "] ";
                    
                    playerFound = true;
                    break;
                }
            }

            if (!playerFound)
            {
                bool found = false;
                for (auto &sl : snakesAndLadders)
                {
                    if (sl.first.first == currentPos)
                    {
                        cout << "[ " << sl.second << " ] ";
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "[" <<setw(3) << grid[i][j] <<"] ";
                }
            }
        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------\n";
}

void SnakesAndLaddersBoard::initializeBoard()
{
    snakesAndLadders = {{{5, 58}, 'L'}, {{14, 49}, 'L'}, {{38, 20}, 'S'}, {{45, 7}, 'S'},
     {{42, 60}, 'L'}, {{53, 72}, 'L'}, {{51, 10}, 'S'}, {{65, 54}, 'S'}, {{64, 83}, 'L'},
      {{75, 94}, 'L'}, {{97, 61}, 'S'}, {{91, 73}, 'S'}};
}

int SnakesAndLaddersBoard::applySnakeOrLadder(int position)
{
    for (auto &sl : snakesAndLadders)
    {
        if (sl.first.first == position)
        {
            position = sl.first.second;
            if (sl.second == 'S')
            {   
                cout << endl << endl;
                cout << "Oh no! A snake! Moving back to " << position << endl;
                return position;
            }
            else if (sl.second == 'L')
            {
                cout << endl
                     << endl;
                cout << "Great! A ladder! Moving forward to " << position << endl;
                return position;
            }
        }
    }
    return position;
}

string SnakesAndLaddersBoard::serialize() const
{
    string serializedData;
    for (auto &sl : snakesAndLadders)
    {
        serializedData += to_string(sl.first.first) +" "+to_string(sl.first.second) + " " + sl.second + "\n";
    }
    return serializedData;
}

void SnakesAndLaddersBoard::deserialize(const string &data)
{
    stringstream ss(data);
    snakesAndLadders.clear();
    int start,end;
    char type;
    while (ss >> start >> end >> type)
    {
        snakesAndLadders.push_back({{start,end},type});
    }
}

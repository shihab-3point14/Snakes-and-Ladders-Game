#include <bits/stdc++.h>

using namespace std;

class Player
{
public:
    static int count;
    int player_number;
    string name;
    int position;
    int consecutiveSixes;
    friend class SnakesAndLaddersBoard;



    Player(string playerName);

    void move(int diceRoll);

    bool handleConsecutiveSixes(int diceRoll);

    string serialize() const;

    static Player deserialize(const string &data);

    
    
};

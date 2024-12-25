#include <bits/stdc++.h>

using namespace std;

class Player
{
private:
    static int count;
    int player_number;
    string name;
    int position;
    int consecutiveSixes;

public:
    Player(string playerName);

    void move(int diceRoll);

    bool handleConsecutiveSixes(int diceRoll);

    string serialize() const;

    static Player deserialize(const string &data);
    
};

#include "player.h"

Player ::Player(string playerName) : name(playerName), position(1), consecutiveSixes(0) {}

void Player ::move(int diceRoll)
{
    position += diceRoll;
    if (position > 100)position -= diceRoll;
}

bool Player ::handleConsecutiveSixes(int diceRoll)
{
    if (diceRoll == 6)
    {
        consecutiveSixes++;
        if (consecutiveSixes == 3)
        {
            cout << name << " rolled three consecutive 6's! Go back to start.\n";
            position -= 18;
            consecutiveSixes = 0;
            return false;
        }
        return true;
    }
    else
    {
        consecutiveSixes = 0;
        return false;
    }
}

string Player ::serialize() const
{
    return name + " " + to_string(position) + " " + to_string(consecutiveSixes);
}

Player Player ::deserialize(const string &data)
{
    stringstream ss(data);
    string name;
    int position, consecutiveSixes;
    ss >> name >> position >> consecutiveSixes;
    Player p(name);
    p.position = position;
    p.consecutiveSixes = consecutiveSixes;
    return p;
}

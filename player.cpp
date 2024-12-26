#include "player.h"

int Player:: count = 1;

Player ::Player(string playerName) : name(playerName), position(0), consecutiveSixes(0) {
    player_number = count;
    count++;
}

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
    return name + " " + to_string(position) + " " + to_string(consecutiveSixes) + " " + to_string(player_number);
}

Player Player ::deserialize(const string &data)
{
    stringstream ss(data);
    string name;
    int position, consecutiveSixes,number;
    ss >> name >> position >> consecutiveSixes >> number;
    Player p(name);
    p.position = position;
    p.consecutiveSixes = consecutiveSixes;
    p.player_number = number;
    return p;
}



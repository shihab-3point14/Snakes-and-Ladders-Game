#include"player.h"


//check
int main(){
    system("color 75");
    Player p1("shihab");
    p1.move(7);
    p1.handleConsecutiveSixes(6);
    p1.handleConsecutiveSixes(6);
    cout << p1.serialize() << endl;
    Player p2 = p1.deserialize(p1.serialize());
    cout <<"Hello" << endl;
    p2.move(7);
    cout << p2.serialize() << endl;


    return 0;
}
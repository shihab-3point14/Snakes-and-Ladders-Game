#include"SnakesAndLadderBoard.h"
using namespace std;

int main()
{
    Player player1("Alice");
    Player player2("Bob");
    Player player3("Charlie");

    SnakesAndLaddersBoard board;

    vector<Player> players = {player1, player2, player3};

    // Display initial board
    board.displayBoard(players);

    // Move players and display the board again
    player1.move(6);
    player2.move(4);
    player3.move(2);
    players = {player1, player2, player3};

    cout << "After moving players:\n";
    board.displayBoard(players);

    // // Apply snakes or ladders
    // player1.position = board.applySnakeOrLadder(player1.position);
    // player2.position = board.applySnakeOrLadder(player2.position);
    // player3.position = board.applySnakeOrLadder(player3.position);
    // players = {player1, player2, player3};

    // cout << "After applying snakes and ladders:\n";
    // board.displayBoard(players);

    return 0;
}

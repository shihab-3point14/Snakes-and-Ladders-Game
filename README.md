## 1. Introduction

The **Snakes-and-Ladders-Game** project aims to digitally recreate the traditional Bangladeshi Snakes and Ladders board game. Developed in C++ using Object-Oriented Programming (OOP) principles, it offers a structured and engaging approach to programming while modernizing a beloved classic game. The project replicates the charm and excitement of the original game while integrating modern programming techniques.

## 2. Objectives

- **Digital Recreation:** Recreate the traditional Snakes and Ladders game with a focus on authenticity and player engagement.
- **Robust Implementation:** Utilize C++ and OOP principles to develop robust, maintainable, and scalable code.
- **User-Friendly Experience:** Provide an interactive interface that appeals to a broad audience.

## 3. Design and Implementation

### Modules
- **Board Management:**  
  Manages the creation and behavior of the game board, including the placement of snakes and ladders.
- **Player Management:**  
  Tracks player data such as names, positions, turns, and progress.
- **Game Logic:**  
  Implements game rules, random dice rolling, and interactions between players, snakes, and ladders.
- **Menu Interface:**  
  Provides a user-friendly menu for starting new games, navigating options, and viewing instructions.

### Core Components
- Key classes such as `Board`, `Player`, and `Game` encapsulate functionalities, ensuring modularity and reusability.
- The modular design enhances maintainability and sets the stage for future enhancements.

### Languages and Tools
- **Programming Language:** C++
- **Approach:** Object-Oriented Programming (encapsulation, inheritance, polymorphism)

## 4. File Handling

- Uses `GameID.txt` to store unique game identifiers, player statistics, and metadata.
- Implements dynamic file access and updates during gameplay to ensure data persistence.
- Incorporates error handling to prevent data corruption or loss.

## 5. Privacy Maintenance

- **Minimal Data:** Only essential user data is handled, minimizing privacy concerns.
- **Local Storage:** All data is stored locally on the user’s device, with no external data transmission.
- **Restricted Access:** Sensitive game progress data is protected and accessible only to authorized modules with integrity checks.

## 6. Setup

- **Starting Position:** Players place their markers at the starting square (square 1).
- **Dice Roll:** A standard dice determines player movement across the board.

## 7. Gameplay

- **Turn-Based Mechanics:**  
  Players take turns rolling the dice to move their markers forward.
- **Dice Roll Conditions:**  
  - A player can only start playing if they roll a 1.
  - If a dice roll exceeds square 100, the player does not move and must wait for the next turn.
- **Snakes and Ladders Interaction:**  
  - **Ladder:** Landing on the bottom of a ladder allows the player to ascend to its top.
  - **Snake:** Landing on the head of a snake causes the player to slide down to its tail.
- **Extra Turn:**  
  Rolling a 6 grants the player an additional turn.
- **Three Consecutive Sixes Penalty:**  
  If a player rolls a 6 three times in a row, all three sixes are forfeited, and the player must roll the dice again to determine their move.

## 8. Winning Condition

- The game is won by the first player to land exactly on square 100.
- Players must roll the precise number needed to reach the final square.

## 9. Conclusion

The **Snakes-and-Ladders-Game** project is a testament to the effectiveness of OOP in C++. By modernizing a traditional game through a modular and robust design, it offers an engaging user experience and demonstrates best practices in programming. Future updates will focus on enhancing features, improving the user interface, and refining gameplay mechanics.

## 10. Future Enhancements

- **Graphical User Interface (GUI):** Improve interactivity and visual appeal.
- **Multiplayer Functionality:** Introduce networked multiplayer options.
- **Customization:** Allow players to customize the board, choose difficulty levels, and vary game rules.
- **Advanced Statistics:** Track win rates, average game duration, and other performance metrics.
- **Mobile Compatibility:** Expand the game’s reach by supporting mobile platforms.

## 11. Features

- **Start New Game:**  
  Begin a new game session easily.
- **Player Setup:**  
  Enter the number of players and their names.
- **Gameplay Mechanics:**  
  - Dice-based movement with interaction rules for snakes and ladders.
  - Additional turn granted on rolling a 6.
- **File Handling:**  
  Uses `GameID.txt` for tracking game sessions and player statistics.
- **Load/Save Functionality:**  
  Option to load and save game progress using a unique gaming ID.
- **Exit Option:**  
  Allows players to exit the game when desired.

## Download

You can simply download the zip file of the repository from above or clone it using the terminal with the following command:

```fish
https://github.com/shihab-3point14/Snakes-and-Ladders-Game-in-cpp.git
```
After cloning, open the cloned project's directory in your text editor and open the terminal. Then compile the project using:
```fish
g++ *.cpp
```
To run the project on Linux/Mac (any UNIX-based OS), use:
```fish
./a.out
```
To run the project on Windows, use:
```bash
.\a.exe
```

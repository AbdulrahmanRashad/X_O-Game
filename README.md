# X_O-Game
## Overview
The X_O game is a console-based two-player tic-tac-toe game implemented in C++. The game allows two players to take turns marking spaces on a 3x3 grid with their respective symbols ('X' and 'O'). The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is declared the winner.

## Project Structure
### Files:
1. X_O.h: Header file containing class and function declarations, macros, and enumerations.
2. Functions.cpp: Source file containing the implementation of helper and static functions.
3. Main.cpp: Main source file where the game is initialized, and the main loop is executed.

## Classes:
1. Player: Represents a player in the game. Manages player information such as name, team, color, and symbol. Handles player input and displays the winner in case of victory.
2. Game: Manages the game board, player turns, and game flow. Includes functions for game initialization, player greetings, checking for a winner, and handling the end of the game.

## How to Play
1. Run X_O.exe file.
2. Players are prompted to enter their names, select a team ('X' or 'O'), and choose a color.
3. The game board is displayed, and players take turns entering the location from 1 to 9 to place their symbol in the board.
4. The game continues until a player wins, the game ends in a draw.
5. After each game, players can choose to play again or exit the program.

## Future Improvements
1. Implement AI for Single Player Mode.
2. Apply More Concepts of Object-Oriented Programming.
3. Other Enhancements.

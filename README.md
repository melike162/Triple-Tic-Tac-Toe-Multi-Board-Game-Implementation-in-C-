# MULTI-BOARD TIC-TAC-TOE GAME (C++ CONSOLE VERSION)

## Overview
This project is a **multi-board Tic-Tac-Toe game** implemented in C++ for the console.  
The game uses **three separate 3x3 boards**, and two players (`X` and `O`) take turns making moves on all boards.  
The game continues until winners are determined on all boards.  

Key features include:
- Input validation (prevents invalid or occupied tiles)  
- Tracking moves for both players  
- Automatic deletion of old moves after a certain turn  
- Automatic winner check for each board  
- Console output showing all boards side by side  

## Features
- **Three separate game boards** played simultaneously  
- **Two-player mode** (player vs player)  
- **Move tracking** for players  
- **Real-time winner detection**  
- **Side-by-side console board display**  

## How to Play
1. Compile the program with any C++ compiler (e.g., `g++`).  
2. Run the output executable.  
3. The program displays the current state of all three boards.  
4. Players enter the **row (r)** and **column (c)** index (0-2) for each board.  
5. Invalid inputs or occupied tiles are rejected and players must enter again.  
6. From the 6th turn onward, old moves may be deleted, and boards are updated.  
7. The game continues until winners are determined on all boards.  

## Code Structure

### Main File
- **`main.cpp`**: Contains the game loop, input/output handling, and main game logic  

### Functions
- **`tableF`**: Displays the current state of all boards side by side  
- **`getInput2`**: Takes player input, updates the board and move records  
- **`deletePlayer`**: Deletes a player's old move from a board after a specific turn  
- **`checkWinner`**: Checks each board and prints the winner if there is one  

### Data Structures
- **`Pair`** struct: Holds row (`x`) and column (`y`) coordinates of a move  
- **`lx[3][3]` and `ly[3][3]`**: Stores moves of `X` and `O` players  
- **`winners[3]`**: Holds the winner for each board  

## How to Compile
You can compile with a standard C++ compiler:

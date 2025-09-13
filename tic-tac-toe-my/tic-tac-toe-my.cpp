
#include <iostream>

typedef struct {
    int x;
    int y;
} Pair;

void tableF(char board1[3][3], char board2[3][3], char board3[3][3]) {
    std::cout << "   1    \t   2    \t   3" << std::endl;

    for (int row = 0; row < 3; row++) {
        
        std::cout
            << board1[row][0] << " | " << board1[row][1] << "| " << board1[row][2] << "\t"
            << board2[row][0] << " | " << board2[row][1] << "| " << board2[row][2] << "\t"
            << board3[row][0] << " | " << board3[row][1] << "| " << board3[row][2] << std::endl;

        
        if (row < 2) { 
            std::cout
                << "__|__|__\t__|__|__\t__|__|__" << std::endl;
        }
    }
}

void getInput2(char currentPlayer, char board[3][3], Pair l[3][3], int a, int i) {//Applies the currentPlayer's move to the board
    int r;
    int c;
    
    
        std::cout << "Current player is " << currentPlayer << std::endl;
        while (true) {
            std::cout << "Enter r c from 0-2 for row and column for game "<<i<<" :" << std::endl;
            std::cin >> r >> c;
            if (r < 0 || r>2 || c < 0 || c>2) {
                std::cout << "Invalid input, try again." << std::endl;
            }
            else if (board[r][c] != ' ') {
                std::cout << "Tile is full, try again." << std::endl;
            }
            else {
                break;
            }
            //reset
            r = -1;
            c = -1;
            std::cin.clear();//clear error flags
            std::cin.ignore(10000, '\n');//discard values
        }
        l[i-1][a % 3].x = r;
        l[i-1][a % 3].y = c;
        board[r][c] = currentPlayer;
}

void deletePlayer(char board[3][3], Pair l[3][3], int a, int boardn) {

    int idx = a % 3;
    int r = l[boardn][idx].x;
    int c = l[boardn][idx].y;
    
    board[r][c] = ' ';
}

void checkWinner(char winners[3], char (*boards[3])[3]) {
    bool hasWinner = false;
    for (int i = 0; i < 3; i++) {

        if (winners[i] == ' ') {
            hasWinner = false;

            // Rows - horizontal
            for (int r = 0; r < 3; r++) {
                if (boards[i][r][0] != ' ' &&
                    boards[i][r][0] == boards[i][r][1] &&
                    boards[i][r][1] == boards[i][r][2]) {
                    winners[i] = boards[i][r][0];
                    hasWinner = true;
                    break;
                }
            }

            // Columns - vertical
            for (int c = 0; c < 3 && !hasWinner; c++) {
                if (boards[i][0][c] != ' ' &&
                    boards[i][0][c] == boards[i][1][c] &&
                    boards[i][1][c] == boards[i][2][c]) {
                    winners[i] = boards[i][0][c];
                    hasWinner = true;
                    break;
                }
            }

            // Diagonals
            if (!hasWinner && boards[i][0][0] != ' ' &&
                boards[i][0][0] == boards[i][1][1] &&
                boards[i][1][1] == boards[i][2][2]) {
                winners[i] = boards[i][0][0];
                hasWinner = true;
            }
            if (!hasWinner && boards[i][2][0] != ' ' &&
                boards[i][2][0] == boards[i][1][1] &&
                boards[i][1][1] == boards[i][0][2]) {
                winners[i] = boards[i][2][0];
                hasWinner = true;
            }

            // write the winner
            if (hasWinner) {
                std::cout << "Player " << winners[i] << " is the winner of game " << i + 1 << "." << std::endl;
            }
        }
    }
}

int main()
{
    char board1[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    char board2[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    char board3[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    
    int gameNumber = 0;
    char playerX = 'X';
    char playerO = 'O';
    char currentPlayer = playerX;
    Pair lx[3][3] = { 0 };
    Pair ly[3][3] = { 0 };
    int winnerNumber = 0;
    char winners[3] = { ' ', ' ', ' ' };

    while (winnerNumber <3) {//// Game loop: iterate through all boards, take moves sequentially, and check for winners
        winnerNumber = 0;

        Pair(*currentArray)[3] = (currentPlayer == playerX) ? &lx[0] : &ly[0];
        char (*boards[3])[3] = { board1, board2, board3 };
        
        if (gameNumber > 5) {//delete move
            for (int i = 0; i < 3; i++) {
                if (winners[i] == ' ') {
                    deletePlayer(boards[i], currentArray, gameNumber, i);
                }
            }
        }

        tableF(board1, board2, board3);//write screen

        // input
        for (int i = 0; i < 3; i++) {
            if (winners[i] == ' ') {
                getInput2(currentPlayer, boards[i], currentArray, gameNumber, i + 1);
            }
        }

        if (gameNumber > 4) {
            //check winner
            checkWinner(winners, boards);
            
        }

        for (int i = 0; i < 3; i++) {
            if (winners[i] != ' ') {
                winnerNumber++;
            }
            
        }
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
        gameNumber++;
    }

    for (int i = 0; i < 3; i++) {
        std::cout << "Player " << winners[i] << " is the winner of game " << i + 1 << "." << std::endl;
    }

}

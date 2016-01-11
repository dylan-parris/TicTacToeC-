/* 
 * File:   main.cpp
 * Author: Dylan
 *
 * Created on January 9, 2016, 11:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

char player1 = 1;
char player2 = 2;
bool player1Turn = true;

const int size = 3; // in one based notation size 3 has 3 rows and 3 columns
int board[ size ][ size ];

void initializeBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}

void rawBoard(){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << board[i][j];
        }
        std::cout << '\n';
    }
}

void drawBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << ' ';
            switch(board[i][j]){
                case 1: std::cout << 'X';
                break;
                case 2: std::cout << 'Y';
                break;
                default: std::cout << ' ';
                break;
            }
            if (j != size - 1) {
                std::cout << " |";
            }
        }
        if (i != size - 1) {
            std::cout << "\n--- --- ---\n";
        }
    }
    std::cout << "\n";
}

bool checkLinearWins() {
    for (int i = 0; i < size - 1; i++) {
        //Horizontal win
        if (board[i][0] != 0) {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                if (board[i][0] == player1) {
                    std::cout << "PLAYER 1 WINS!!!\n";
                    return true;
                } else {
                    std::cout << "PLAYER 2 WINS!!!\n";
                    return true;
                }
            }
        }
        //Vertical win
        if (board[0][i] != 0) {
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                if (board[0][i] == player1) {
                    std::cout << "PLAYER 1 WINS!!!\n";
                    return true;
                } else {
                    std::cout << "PLAYER 2 WINS!!!\n";
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkDiagWins() {
    //Diagonal win
    switch(board[1][1]){
        case 0: return false;
        case 1: if(board[0][0] == 1 && board[2][2] == 1){
                    std::cout << "PLAYER 1 WINS!!!\n";
                    return true;
                } else if(board[0][2] == 1 && board[2][0] == 1){
                    std::cout << "PLAYER 1 WINS!!!\n";
                    return true;
                } else {return false;}
        case 2: if(board[0][0] == 2 && board[2][2] == 2){
                    std::cout << "PLAYER 2 WINS!!!\n";
                    return true;
                } else if(board[0][2] == 2 && board[2][0] == 2){
                    std::cout << "PLAYER 2 WINS!!!\n";
                    return true;
                } else {return false;}
        default: return false;
    }
}

bool win() {
    return (checkLinearWins() || checkDiagWins());
}

bool validInput(int row, int col) {
    if (row > 2 || col > 2) {
        return false;
    } else if (row < 0 || col < 0) {
        return false;
    } else if (board[row][col] != 0) {
        //TODO: Invalid move do something
        return false;
    }
    return true;
}

void getInput() {
    std::string coor;
    std::cin >> coor;
    std::cout << "\n";
    int row = (int) coor.at(0) - 49;
    int col = (int) coor.at(2) - 49;
    if (validInput(row, col)) {
        std::cout << "input is valid row:" << row << " col:" << col << '\n';
        if (player1Turn) {
            board[row][col] = player1;
            player1Turn = false;
        } else {
            board[row][col] = player2;
            player1Turn = true;
        }
    }
}

void gamePlay() {
    std::cout << "To play enter the coordinates of the square you choose\n";
    std::cout << "For example to select the upper middle square enter 1,2\n";

    while (!win()) {
        if (player1Turn) {
            std::cout << "Player 1's Turn!\n";
        } else {
            std::cout << "Player 2's Turn!\n";
        }
        std::cout << "Select coordinates: ";
        getInput();
        //clearScreen();
        drawBoard();
        
    }
}

int main(int argc, char** argv) {
    std::cout << "Play Todd in Tic-Tac-Toe\n\n";

    initializeBoard();
    drawBoard();
    gamePlay();

    std::cout << "Press Enter to Exit...";
    std::cin.get();
    std::cin.get();

    return 0;
}

/*
 X | O | X
--- --- ---
 O | X | O 
--- --- ---
   |   |   
*/


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

char board[3][3];

void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

bool isMoveValid(int row, int col) {
    return board[row][col] == ' ';
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

void playerMove() {
    int row, col;
    do {
        cout << "Enter row (0-2) and column (0-2) for your move: ";
        cin >> row >> col;
    } while (!isMoveValid(row, col));
    board[row][col] = 'X';
}

void computerMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!isMoveValid(row, col));
    board[row][col] = 'O';
}

int main() {
    //srand(time(0));
    initBoard();
    displayBoard();
    while (true) {
        playerMove();
        displayBoard();
        if (checkWin('X')) {
            cout << "Congratulations! You win!" << endl;
            break;
        }
        if (isBoardFull()) {
            cout << "It's a tie!" << endl;
            break;
        }
        computerMove();
        displayBoard();
        if (checkWin('O')) {
            cout << "Sorry, you lose!" << endl;
            break;
        }
        if (isBoardFull()) {
            cout << "It's a tie!" << endl;
            break;
        }
    }
    return 0;
}

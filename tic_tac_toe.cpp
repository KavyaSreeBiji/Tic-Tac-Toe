#include <iostream>

using namespace std;

class TicTacToe {
private:
    char board[9]; // Using a standard array instead of vector
    char currentPlayer;

public:
    TicTacToe() {
        // Initialize board with spaces
        for (int i = 0; i < 9; i++) {
            board[i] = ' ';
        }
        currentPlayer = 'X';
    }

    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 9; i++) {
            cout << " " << board[i] << " ";
            if ((i + 1) % 3 != 0) cout << "|";
            if ((i + 1) % 3 == 0 && i < 6) cout << "\n-----------\n";
        }
        cout << "\n\n";
    }

    bool makeMove(int slot) {
        // Validation: Must be 1-9 and the spot must be empty
        if (slot < 1 || slot > 9 || board[slot - 1] != ' ') {
            return false;
        }
        board[slot - 1] = currentPlayer;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char checkWinner() {
        // 8 Winning patterns: 3 rows, 3 columns, 2 diagonals
        int wins[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
            {0, 4, 8}, {2, 4, 6}             // Diagonals
        };

        for (int i = 0; i < 8; i++) {
            if (board[wins[i][0]] != ' ' && 
                board[wins[i][0]] == board[wins[i][1]] && 
                board[wins[i][1]] == board[wins[i][2]]) {
                return board[wins[i][0]];
            }
        }
        return ' ';
    }

    bool isFull() {
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') return false;
        }
        return true;
    }

    char getCurrentPlayer() { return currentPlayer; }
};

int main() {
    TicTacToe game;
    int choice;

    cout << "--- Tic-Tac-Toe (C++) ---\n";

    while (true) {
        game.displayBoard();
        cout << "Player " << game.getCurrentPlayer() << ", enter a position (1-9): ";
        
        // Handle non-integer input
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear(); 
            while (cin.get() != '\n'); // Clear buffer
            continue;
        }

        if (game.makeMove(choice)) {
            char winner = game.checkWinner();
            if (winner != ' ') {
                game.displayBoard();
                cout << "Player " << winner << " wins!\n";
                break;
            }
            if (game.isFull()) {
                game.displayBoard();
                cout << "It's a draw!\n";
                break;
            }
            game.switchPlayer();
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
    return 0;
}
#include <iostream>
using namespace std;

class TicTacToe {
private:
    char grid[3][3];
    char turn;

public:
    TicTacToe() {
        initBoard();
        turn = 'X';
    }

    void initBoard() {
        char pos = '1';
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                grid[r][c] = pos++;
            }
        }
    }

    void showBoard() {
        cout << "\n";
        for (int r = 0; r < 3; r++) {
            cout << " " << grid[r][0] << " | " << grid[r][1] << " | " << grid[r][2] << "\n";
            if (r < 2) cout << "---|---|---\n";
        }
        cout << "\n";
    }

    bool inputMove() {
        int cell;
        cout << "Player " << turn << ", choose a cell (1-9): ";
        cin >> cell;

        if (cell < 1 || cell > 9) {
            cout << "Invalid input! Try again.\n";
            return false;
        }

        int row = (cell - 1) / 3;
        int col = (cell - 1) % 3;

        if (grid[row][col] == 'X' || grid[row][col] == 'O') {
            cout << "Cell already filled! Try again.\n";
            return false;
        }

        grid[row][col] = turn;
        return true;
    }

    bool hasWinner() {
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == turn && grid[i][1] == turn && grid[i][2] == turn) return true;
            if (grid[0][i] == turn && grid[1][i] == turn && grid[2][i] == turn) return true;
        }
        if (grid[0][0] == turn && grid[1][1] == turn && grid[2][2] == turn) return true;
        if (grid[0][2] == turn && grid[1][1] == turn && grid[2][0] == turn) return true;

        return false;
    }

    bool isFull() {
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                if (grid[r][c] != 'X' && grid[r][c] != 'O')
                    return false;
        return true;
    }

    void changeTurn() {
        turn = (turn == 'X') ? 'O' : 'X';
    }

    void startGame() {
        while (true) {
            initBoard();
            turn = 'X';
            bool finished = false;

            while (!finished) {
                showBoard();
                if (inputMove()) {
                    if (hasWinner()) {
                        showBoard();
                        cout << "Player " << turn << " wins the game!\n";
                        finished = true;
                    } 
                    else if (isFull()) {
                        showBoard();
                        cout << "Game ends in a draw!\n";
                        finished = true;
                    } 
                    else {
                        changeTurn();
                    }
                }
            }

            char again;
            cout << "Do you want to play again? (y/n): ";
            cin >> again;
            if (again != 'y' && again != 'Y') break;
        }
    }
};

int main() {
    TicTacToe ttt;
    ttt.startGame();
    return 0;
}



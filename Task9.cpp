#include <iostream>
using namespace std;

int grid[4][4] = {
    {1, 0, 0, 4},
    {0, 4, 1, 0},
    {0, 1, 4, 0},
    {4, 0, 0, 1}
};

bool isSafe(int r, int c, int num) {
    for (int i = 0; i < 4; i++) {
        if (grid[r][i] == num || grid[i][c] == num) {
            return false;
        }
    }

    int row = (r / 2) * 2;
    int col = (c / 2) * 2;

    for (int i = row; i < row + 2; i++) {
        for (int j = col; j < col + 2; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) {
                for (int num = 1; num <= 4; num++) {
                    if (isSafe(i, j, num)) {
                        grid[i][j] = num;

                        if (solve()) {
                            return true;
                        }

                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    if (solve()) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No solution exists";
    }

    return 0;
}


#include <iostream>
using namespace std;

char color[3] = {'R', 'G', 'B'};

int graph[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0}
};

int c[4] = {-1, -1, -1, -1};

bool isSafe(int v, int col) {
    for (int i = 0; i < 4; i++) {
        if (graph[v][i] == 1 && c[i] == col) {
            return false;
        }
    }
    return true;
}

bool solve(int v) {
    if (v == 4) {
        return true;
    }
    for (int i = 0; i < 3; i++) {
        if (isSafe(v, i)) {
            c[v] = i;
            if (solve(v + 1)) {
                return true;
            }
            c[v] = -1;
        }
    }
    return false;
}

int main() {
    if (solve(0)) {
        for (int i = 0; i < 4; i++) {
            cout << char('A' + i) << " = " << color[c[i]] << endl;
        }
    else {
        cout << "No valid coloring exists";
    }

    return 0;
}


#include <iostream>
using namespace std;

char grid[3][3] = {
    {'C', 'A', 'T'},
    {'D', 'O', 'G'},
    {'R', 'A', 'T'}
};
bool visited[3][3] = {false};

int rowMove[4] = {-1, 1, 0, 0};
int colMove[4] = {0, 0, -1, 1};

bool search(int r, int c, string word, int index) {
    if (index == word.length()) {
        return true;
    }
    if (r < 0 || r >= 3 || c < 0 || c >= 3) {
        return false;
    }
    if (visited[r][c] || grid[r][c] != word[index]) {
        return false;
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        if (search(r + rowMove[i], c + colMove[i], word, index + 1)) {
            return true;
        }
    }

    visited[r][c] = false;
    return false;
}

int main() {
    string word = "CAT";
    bool found = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (search(i, j, word, 0)) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (found) {
        cout << "Word found";
    }
    else {
        cout << "Word not found";
    }

    return 0;
}


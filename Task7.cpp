#include <iostream>
using namespace std;

int arr[5] = {2, 3, 5, 6, 8};
int subset[5];
int found = 0;

void solve(int i, int sum, int count) {
    if (sum == 9) {
        for (int j = 0; j < count; j++) {
            cout << subset[j] << " ";
        }
        cout << endl;
        found = 1;
        return;
    }

    if (i == 5 || sum > 9) {
        return;
    }
    subset[count] = arr[i];
    solve(i + 1, sum + arr[i], count + 1);
    solve(i + 1, sum, count);
}

int main() {
    solve(0, 0, 0);

    if (found == 0) {
        cout << "No valid subset exists";
    }

    return 0;
}


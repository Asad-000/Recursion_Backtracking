#include <iostream>
using namespace std;

char arr[4] = {'A', 'B', 'C', 'D'};

void permute(int i) {
    if (i == 4) {
        for (int j = 0; j < 4; j++) {
            cout << arr[j];
        }
        cout << endl;
        return;
    }

    for (int j = i; j < 4; j++) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        permute(i + 1);

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    permute(0);
    return 0;
}


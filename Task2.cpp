#include <iostream>
using namespace std;

int search_range(int n) {
	if(n<0) {
		return 0;
	}
	
	cout << n << endl;
	return search_range(n-1);
}

int main() {
	int n;
	cout << "Enter the range: ";
	cin >> n;
	
	search_range(n);
	
	return 0;
}

#include <iostream>
using namespace std;

int sumOfDigits(int num) {
	if(num == 0) {
		return 0;
	}
	return (num % 10) + sumOfDigits(num / 10);
	
}

int main() {
	int num;
	cout << "Enter the positive integer number: ";
	cin >> num;
	
	cout << "Sum of Digits: " << sumOfDigits(num);
	
	return 0;
}

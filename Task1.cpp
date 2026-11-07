#include <iostream>
using namespace std;

int reverseString(string name, int i) {
	if(i<0) {
		return 0;
	}
	cout << name[i];
	return reverseString(name, i-1);
}

int main() {
	string name = "Asad";
	
	reverseString(name, name.length() - 1);
	
	return 0;
}

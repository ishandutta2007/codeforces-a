#include <iostream>
using namespace std;



int main() {
	int n;
	cin >> n;
	if (n > 2)
		cout << n - 2;
	else
		cout << n + 2;
	return 0;
}
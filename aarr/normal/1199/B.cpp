#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


const int N = 100 * 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 7;

int a[N];
int b[N];
bool mark[N];
map <int, int> mp;


int get(int x, int y) {
	return (x >> y) & 1;
}
bool pal(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}
bool lucky(int x) {
	while (x) {
		if (x % 10 != 7 && x % 10 != 4) {
			return false;
		}
		x /= 10;
	}
	return true;
}
int bmm(int x, int y) {
	if (y == 0)
		return x;
	return bmm(y, x % y);
}
int main() {
	double h, l;
	cin >> h >> l;
	cout << fixed << setprecision(7);
	cout << ((l * l) - (h * h)) / 2 / h;
}
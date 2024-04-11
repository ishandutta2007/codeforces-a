#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;


const int N = 100 * 1000 + 5;

int a[N];



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
int main() {
	int n, m, ans = N;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i + n - 1 <= m; i++) {
		ans = min(ans, a[i + n - 1] - a[i]);
	}
	cout << ans;
}
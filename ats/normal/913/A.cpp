#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N;
	cin >> M;
	int a = 1;
	for (int i = 0; i < N; i++) {
		a *= 2;
		if (a > M)break;
	}
	if (a > M) {
		cout << M << endl;
	}
	else {
		cout << (M % a) << endl;
	}
	
}
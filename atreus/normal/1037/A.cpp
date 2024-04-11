#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
const int inf = 1e9;
const int block = 400;

int main () { 
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i <= 30; i++) {
		if (1ll << i > n)
			return cout << i << endl, 0;
	}
}
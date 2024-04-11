#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 1000;

int main()
{
	FAST;
	int t;
	cin >> t;
	int a[N];
	int b[N];
	while (t--)
	{
		int n;
		cin >> n;
		Loop(i, 0, n)
			cin >> a[i];
		Loop(i, 0, n)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		Loop(i, 0, n)
			cout << a[i] << ' ';
		cout << '\n';
		Loop(i, 0, n)
			cout << b[i] << ' ';
		cout << '\n';
	}
}
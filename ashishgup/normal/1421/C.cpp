#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	cin >> s;
	n = s.size();
	cout << 3 << endl;
	cout << "L " << 2 << endl;
	cout << "R " << 2 << endl;
	cout << "R " << 2 * n - 1 << endl;
	return 0;
}

// Problem : A. Fence
// Contest : Codeforces - Codeforces Round #675 (Div. 2)
// URL : https://codeforces.com/contest/1422/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int a, b,c;
		cin >> a >> b >> c;
		cout << max(max(a, b), c) << "\n";
	}
}
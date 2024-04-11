#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7;
int T[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	rep(i, n) {
		char x;
		cin >> x;
		T[i]=x-'a'+1;
		if(i) T[i]+=T[i-1];
	}
	while(q--) {
		int l, r;
		cin >> l >> r; --l; --r;
		cout << T[r]-(l?T[l-1]:0) << '\n';
	}
}
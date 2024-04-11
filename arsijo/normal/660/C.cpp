#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 9;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#endif

	int n, m;
	cin >> n >> m;

	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	int l = 0, sum = 0, l_ans, r_ans, ans = 0, t = 0;

	for(int i = 0; i < n; i++){
		if(ar[i]){
			sum++;
		}else{
			t++;
		}
		while(t > m){
			if(ar[l]){
				sum--;
			}else{
				t--;
			}
			l++;
		}
		int sum = i - l + 1;
		if(sum > ans){
			ans = sum;
			l_ans = l;
			r_ans = i;
		}
	}

	for(int i = l_ans; i <= r_ans; i++)
		ar[i] = 1;

	cout << ans << endl;
	for(int i = 0; i < n; i++)
		cout << ar[i] << " ";
	cout << endl;

}
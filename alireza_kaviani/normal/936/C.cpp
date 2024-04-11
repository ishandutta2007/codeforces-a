/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-10-27 11:21:02
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;
string s , t , ss , tt;
vector<int> ans;

void shift(int x){
	ans.push_back(x);
	string A = s.substr(0 , n - x) , B = s.substr(n - x , x);
	reverse(all(B));
	s = B + A;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> s >> t; ss = s; tt = t;
	sort(all(ss)); sort(all(tt));
	if(ss != tt)	return cout << -1 << endl , 0;
	for(int i = 0 ; i < n ; i++){
		int pos = -1;
		for(int j = 0 ; j < n - i ; j++){
			if(t[i] == s[j]){
				pos = j;
			}
		}
		/*cout << i << sep << pos << endl;
		cout << s << endl << t << endl;
		if(pos == -1){
			cout << "Faild" << endl;
			break;
		}*/
		assert(pos != -1);
		shift(n - pos - 1);
		shift(1);
		shift(n);
	}
	// cout << s << endl << t << endl;
	cout << SZ(ans) << endl;
	for(int i : ans){
		cout << i << sep;
	}

    return 0;
}
/*

*/
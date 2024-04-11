/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: alireza_kaviani
 * Time: 2020-08-26 16:03:01
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

int n , sum , cnt[26];
vector<int> vec;
string s;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> s; n = SZ(s);
	for(int i = 0 ; i < n ; i++)	cnt[s[i] - 97]++;
	for(int i = 0 ; i < 26 ; i++)	if(cnt[i] & 1)	vec.push_back(i);
	for(int i = 0 ; i < SZ(vec) / 2 ; i++){
		//cout << i << sep << vec[i] << sep << vec[i + 1] << endl;
		cnt[vec[i]]++;
		cnt[vec[SZ(vec) - i - 1]]--;
	}
	if(n & 1)	s[n / 2] = vec[SZ(vec) / 2] + 97;
	for(int i = 0 , ptr = 0 ; i < 26 ; i++){
		for(int j = 0 ; j + 1 < cnt[i] ; j += 2){
			s[ptr] = s[n - ptr - 1] = i + 97;
			ptr++;
		}
	}
	cout << s << endl;
    return 0;
}
/*

*/
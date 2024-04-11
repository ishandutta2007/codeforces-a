#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e6 + 1e5;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {    
    ll n;
    cin >> n;
    vector <vector <string>> s(3, vector<string> (n));
    map <string, int> mp;
    vector <ll> ans(3);
    for (int i = 0; i < 3; i++) {
        for (auto &j : s[i]) {
            cin >> j;
            mp[j]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (auto &j : s[i]) {
            if (mp[j] == 1) {
                ans[i] += 3;
            }else if (mp[j] == 2) {
                ans[i]++;
            }
        }
    }
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif         

    cin >> t;   

    while (t--) {
        solve();
    }


    return 0;
}
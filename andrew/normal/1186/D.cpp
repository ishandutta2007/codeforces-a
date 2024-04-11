#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize(-O3)
#pragma GCC optimize(0fast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define sqr(x) (x) * (x)
#define p_b push_back
#define m_p make_pair
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll Val(string s){
    stringstream ss;
    ss << s;
    ll x;
    ss >> x;
    return x;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector <string> a(n + 1);
    vector <ll> c(n + 1);
    vector <bool> f(n + 1);

    ll sc = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        int pos = a[i].find(".");
        c[i] = Val(a[i].substr(0, pos));
        for(int j = pos + 1; j < a[i].size(); j++)if(a[i][j] != '0')f[i] = 1;

        if(a[i][0] == '-'){
            if(f[i])c[i]--;
        }
        sc += c[i];
    }

    for(int i = 1; i <= n; i++)if(sc < 0 && f[i]){
        c[i]++;
        sc++;
    }

    for(int i = 1; i <= n; i++)cout << c[i] << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
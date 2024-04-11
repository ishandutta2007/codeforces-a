#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 1e6 + 200;
//const int N = 100;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve(){
    int n;
    cin >> n;
    vector <int> a;

    map <int, int> mp;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x > n || mp[x]){
            a.p_b((x + 1) / 2 - 1);
        }else{
            mp[x] = 1;
        }
    }
    sort(all(a));

    int ans = 0;

    for(int i = n; i > 0; i--) if(!mp[i]){        
        if(a.empty() || a.back() < i){
            fout(-1);
        }
        ans++;
        a.pop_back();
    }
    cout << ans << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    

    return 0;
}
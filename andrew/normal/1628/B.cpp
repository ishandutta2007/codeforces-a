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
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void solve(){
    int n;
    cin >> n;
    vector <string> s(n);
    for(auto &i : s) cin >> i;
    map <string, bool> mp;
    for(auto &i : s){
        string t = i;
        reverse(all(t));
        if(t == i){
            fout("YES");
        }
        if(mp.find(t) != mp.end()) fout("YES");
        mp[i] = 1;
    }
    mp.clear();
    for(auto &i : s){
        string t = i;
        reverse(all(t));        
        if(i.size() == 3 && mp.find(t.substr(0, 2)) != mp.end()) fout("YES");
        if(i.size() == 2)mp[i] = 1;
    }
    mp.clear();
    for(auto &i : s){
        string t = i;
        reverse(all(t));        
        if(i.size() == 2 && mp.find(t) != mp.end()) fout("YES");
        if(i.size() == 3)mp[i.substr(0, 2)] = 1;
    }
    fout("NO");
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //cin >> t;
    #endif    
    cin >> t;
    
    while(t--){
        solve();
    }


    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll inf = 1e8;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        while(sz(s) && s[sz(s) - 1] == '0')s.erase(sz(s) - 1);
        reverse(all(s));
        while(sz(s) && s[sz(s) - 1] == '0')s.erase(sz(s) - 1);
        ll ans = 0;
        for(auto i : s)if(i == '0')ans++;
        cout << ans << "\n";
    }
    return 0;
}
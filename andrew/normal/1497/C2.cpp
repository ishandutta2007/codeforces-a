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
const ll M = 2e5;
const int N = 1e7;
const int inf = 1e8;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


void solve(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k - 3; i++)cout << "1 ";
    n -= k - 3;

    if(n % 2){
        cout << n / 2 << " " << n / 2 << " 1\n";
    }else{
        if(n % 4 == 0){
            cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
        }else{
            cout << n / 2 - 1 << " " << n / 2 - 1 << " 2\n";
        }
    }
}




int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}
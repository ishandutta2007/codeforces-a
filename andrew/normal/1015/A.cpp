#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n >> m;
    vector <bool> fl(m);
    while(n--){
        ll l, r;
        cin >> l >> r;
        l--;
        for(int i = l; i < r; i++)fl[i] = 1;
    }
    vector <ll> ans;
    for(int i = 0; i < m; i++)if(!fl[i])ans.p_b(i + 1);
    cout << ans.size() << endl;
    for(auto i : ans)cout << i << " ";
    return 0;
}
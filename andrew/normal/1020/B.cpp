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
    ll n;
    cin >> n;
    vector <ll> p(n + 1);
    vector <bool> f(n + 1);
    for(int i = 1; i <= n; i++)cin >> p[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)f[j] = 0;
        ll a = i;
        while(!f[a]){
            f[a] = 1;
            a = p[a];
        }
        cout << a << " ";
    }
    return 0;
}
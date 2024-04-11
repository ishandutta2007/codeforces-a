#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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
    vector <ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    if(n == 1)vout(-1);
    if(n == 2 && a[0] == a[1])vout(-1);
    ll sc = 0;
    for(int j = 0; j < n; j++)sc += a[j];
    for(int i = 0; i < n; i++){
        if(sc - a[i] != a[i]){
            cout << n - 1 << endl;
            for(int j = 0; j < n; j++)if(i != j)cout << j + 1 << " ";
            exit(0);
        }
    }
    vout(-1);
    return 0;
}
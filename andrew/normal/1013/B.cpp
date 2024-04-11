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

map <ll, ll> mp;
map <ll, ll> mp1;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, x;
    cin >> n >> x;
    vector <ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]] > 1)vout(0);
    }
    for(int i = 0; i < n; i++){
        mp[a[i]]--;
        ll msk = a[i] & x;
        if(mp[msk])vout(1);
        mp1[msk]++;
        mp[a[i]]++;
    }
    for(int i = 0; i < n; i++){
        ll msk = a[i] & x;
        if(mp1[msk] > 1)vout(2);
    }
    vout(-1);
    return 0;
}
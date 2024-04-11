#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

ll f(ll x){
    ll pr = 1;

    while(x){
        pr *= x % 10;
        x /= 10;
    }
    return pr;

}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    ll last0, last1;
    last0 = last1 = 1e18;

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        if(x)last1 = i; else last0 = i;
    }
    cout << min(last0, last1) << "\n";

    cerr << "time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
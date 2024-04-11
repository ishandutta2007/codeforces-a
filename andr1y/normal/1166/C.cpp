#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pp(a, b) pb(mp(a, b))
#define get_bit(n, k) n&(1<<k)
#define endl '\n'
#define vl vector<ll>
#define PI 3.1415926535897932384626433832795
#define rad(deg) deg*PI/180
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF LLONG_MAX
#define NINF -INF-1
#define PAIR_OUT_PRE "("
#define PAIR_OUT_BTW ";"
#define PAIR_OUT_PST "), "
#define ARRAY_OUT_PRE "data: "
#define ARRAY_OUT_BTW ", "
#define ARRAY_OUT_PST endl
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << PAIR_OUT_PRE << V.x << PAIR_OUT_BTW << V.y << PAIR_OUT_PST;}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << ARRAY_OUT_PRE; for(auto i:V)os << i << ARRAY_OUT_BTW; return os << ARRAY_OUT_PST;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << ARRAY_OUT_PRE; for(auto i:V)os << i << ARRAY_OUT_BTW; return os << ARRAY_OUT_PST;}
/*--func--*/
template<typename T> ull fast_log(T a){ull c = 0;while((a>>(++c)) > 0);return c-1;}
ll a[N];
ll n;
ll greatest_less_than(ll x){
    ll l = 0, r = n-1;
    while(r-l>1){
        ll m = (l+r)>>1;
        if(a[m] <= x) l = m;
        else r = m;
    }
    if(a[r] <= x) return r;
    else if(a[l] <= x) return l;
    return -1;
}
ll least_bigger_than(ll x){
    ll l = 0, r = n-1;
    while(r-l>1){
        ll m = (l+r)>>1;
        if(a[m] >= x) r = m;
        else l = m;
    }
    if(a[l] >= x) return l;
    else if(a[r] >= x) return r;
    return n;
}
main(){
    FAST;
    cin >> n;
    for(ll i =0;i<n;i++) cin >> a[i];
    sort(a, a+n);
    ll res = 0;
    for(ll i =0;i<n;i++){
        if(a[i] > 0){
            res += greatest_less_than(2*a[i]) - i + greatest_less_than(-1*a[i]) - least_bigger_than(-2*a[i]) + 1;
        }else if(a[i] == 0){
            continue;
        }else if(a[i] < 0){
            res += i-least_bigger_than(2*a[i]) + greatest_less_than(-2*a[i]) - least_bigger_than(-1*a[i]) + 1;
        }
    }
    for(ll i = 0;i<n;i++){
        if(a[i] >= 0) break;
        if(a[greatest_less_than(-1*a[i])] == -1*a[i]) res--;
    }
    cout << res;
}
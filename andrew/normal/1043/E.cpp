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

ll a[MAXN], b[MAXN], new_pos[MAXN];

vector <pll> p[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    ll q = 0;
    cin >> q;
    vector <ll> ans(n + 1);
    vector < pll >  arr(n + 1);
    ll sc = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        arr[i] = {a[i] - b[i], i};
        sc += b[i];
    }

    sort(arr.begin() + 1, arr.end());
    ll uk = 1;
    ll sc1 = 0;
    for(int i = 1; i <= n; i++){
        while(uk <= n && arr[uk].fi <= arr[i].fi){
            sc1 += a[arr[uk].se];
            sc -= b[arr[uk].se];
            uk++;
        }

        ll x = a[arr[i].se], y = b[arr[i].se];
        ans[arr[i].se] += (n - uk + 1) * x + sc;
        ans[arr[i].se] += (uk - 1) * y + sc1;
        ans[arr[i].se] -= x + y;
    }

    while(q--){
        ll x, y;
        cin >> x >> y;
        ll val = min(a[x] + b[y], a[y] + b[x]);
        ans[x] -= val;
        ans[y] -= val;
    }
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
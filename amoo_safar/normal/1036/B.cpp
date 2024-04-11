#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
ll b[MAXN];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll q,a,b,k;
    cin >> q;
    for(int i = 0;i<q;i++){
        cin >> a >> b >> k;
        if(max(a, b) > k){
            cout << -1 << endl;
            continue;
        }
        if(a > b)swap(a,b);
        ll x = b - a;
        ll d = a;
        d += (2 * (x/2));
        x %= 2;
        if(k%2 == d%2) cout << k - x;
        else{
            if(x==1)cout << k - 1;
            else cout << k-2;
        }
        cout << endl;
    }
    return 0;
}

/*
*/
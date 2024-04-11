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

vector <ll> v[MAXN],va;
string s1,s2,s3;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++)cin >> a[i];
    for(i = 2; i <= n; i++)if(a[i] == a[i - 1])vout("NO");
    for(i = 2; i <= n; i++)if(abs(a[i] - a[i - 1]) > 1)s.insert(abs(a[i] - a[i - 1]));
    if(s.size() > 1)vout("NO");
    ll md = 1e9;
    if(s.size() == 0){
        cout << "YES\n";
        cout << md << " " << md << endl;
        return 0;
    }
    set <ll> :: iterator it = s.begin();
    ll k = *it;
    for(i = 2; i <= n; i++)if(abs(a[i] - a[i - 1]) == 1){
        ll l1 = (a[i] + k - 1) / k, l2 = (a[i - 1] + k - 1) / k;
        if(l1 != l2)vout("NO");
    }
    cout << "YES\n";
    cout << md << " " << (*it) << endl;
    return 0;
}
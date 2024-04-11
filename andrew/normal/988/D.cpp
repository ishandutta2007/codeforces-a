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
    for(i = 1; i <= n; i++)cin >> a[i], s.insert(a[i]);
    va.p_b(a[1]);
    for(i = 1; i <= n; i++){
        for(j = 0; j <= 31; j++){
            bool la = s.find(a[i] - (1ll << j)) != s.end();
            bool ra = s.find(a[i] + (1ll << j)) != s.end();
            if(la && ra && va.size() < 3){
                va.clear();
                va.p_b(a[i] - (1ll << j));
                va.p_b(a[i]);
                va.p_b(a[i] + (1ll << j));
            }
            if(la && va.size() < 2){
                va.clear();
                va.p_b(a[i] - (1ll << j));
                va.p_b(a[i]);
            }
            if(ra && va.size() < 2){
                va.clear();
                va.p_b(a[i]);
                va.p_b(a[i] + (1ll << j));
            }
        }
    }
    cout << va.size() << endl;
    for(i = 0; i < va.size(); ++i)cout << va[i] << " ";
    cout << endl;
    return 0;
}
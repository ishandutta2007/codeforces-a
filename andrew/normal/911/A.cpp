#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
ll binpow(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n%2)res*=a;
        a*=a;
        n/=2;
    }
    return res;
}
template <typename T>
T sqr(T x)
{
    return x*x;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
vector <pll> v[MAXN];
set <pll> st;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
pll a[MAXN];
ll c,sc,n,m,i,j,b[MAXN],a1,b1,c1,ans,x,k;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i].fi;
        a[i].se=i;
    }
    sort(a,a+n);
    a1=1e18;
    for(i=1;i<n;i++)
    {
        if(i!=0 && a[i].fi!=a[i-1].fi)break;
        a1=min(a1,abs(a[i].se-a[i-1].se));
    }
    cout << a1 << endl;
    return 0;
}
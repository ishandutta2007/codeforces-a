#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fi first
#define se second
#define pll pair <ll,ll>
#define m_p make_pair
#define p_b push_back
using namespace std;
vector <ll> tt[10000];
void vout(ll x)
{
    cout << x << endl;
    exit(0);
}
multiset <ll> s;
ll a[1000000];
ll a1,b1,c1,stn,x,k,ans,n,m,l,r,b[1000000],j,c[1000000],sc,i,mn=1e18,mx=-1e18;
int main()
{

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("bow.in","r",stdin);
    //freopen("bow.out","w",stdout);
    cin >> n >> k >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        b[i]=a[i];
        b[i]%=m;
        c[b[i]]++;
    }
    for(i=1;i<=n;i++)
    {
        x=b[i];
        sc=x;
        if(c[x]>=k)
        {
            cout << "Yes" << endl;
            cout << a[i] << " ";
            k--;
            for(j=1;j<=n;j++)if(i!=j && k>0 && b[j]==x)
            {
                cout << a[j] << " ";
                k--;
            }
            return 0;
        }
    }
    cout << "No" << endl;
   return 0;
}
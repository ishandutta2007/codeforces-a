#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                           make_pair
#define endt                        '\t'
#define ends

int main()
{
    ll n;
    cin >> n;

    ll sum=0;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    sort(all(a));

    ll ans=0;
    for(ll i=0;i<n-2;i++)
    {
        ans+=a[i]*(n-i-2);
    }
    cout << sum*n-ans << endl;

    return 0;
}
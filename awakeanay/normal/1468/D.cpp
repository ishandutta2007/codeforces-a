#include<bits/stdc++.h>
#include<math.h>
#include<algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const double pi=3.141592653589;
long long int mod = 1e9+7;
long long int mod2 = 1000000009;                    // used for string hashing...
const long long int inf = 1e9;
const long long int inff = 9000000000000000000;
long double eps = 1e-9;
const long long int base1=304933;
const long long int base2=4395853;
#define pry  cout<<"YES\n"
#define prn  cout<<"NO\n"
#define prm cout<<"-1\n"
#define nl cout<<"\n"
#define loop(i,a,b) for(ll i=a;i<b;i+=1)
#define rloop(i,a,b) for(ll i=a;i>=b;i-=1)
#define ll long long int
#define ld long double
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define ft first
#define sd second
#define pii pair<int,int>
#define pll pair<long long int, long long int>
#define mysort(a) sort(a.begin(),a.end())
#define myreverse(a) reverse(a.begin(),a.end())
#define mylb(a,val) lower_bound(a.begin(),a.end(),val)
#define myub(a,val) upper_bound(a.begin(),a.end(),val)
#define mem(a,vall) memset(a, vall, sizeof(a))
#define ordered_set tree< pll, null_type,less< pll >, rb_tree_tag,tree_order_statistics_node_update>
ld power(ll x, ll y, ll p)
{
    ll res = 1;

    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}
ll fac[1];
ll invfac[1];
ll ncr(ll n, ll r, ll p)
{
    if(r>n) return 0;

    if (r==0) return 1;

    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}
ll log(ll a,ll b)
{
    if(a==1)
        return b;
    ll ans = 0;
    while(b)
    {
        ans++;
        b/=a;
    }
    return ans-1;
}
int is_prime[1];
int smallestfactor[1];
void sieve()
{
    for(ll i=2; i<=5000000; i++)
    {
        if(is_prime[i])
        {
            for(ll j=i*i; j<=5000000; j+=i)
            {
                if(is_prime[j]==1)
                {
                    is_prime[j]=0;
                    smallestfactor[j]=i;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int test=1;
    //freopen("dull.in", "r", stdin);       // file open for input
    //freopen("output.txt", "w", stdout);   // file open for output
    cin>>test;                              // comment this when number of testcases = 1

    while(test--)
    {

        ll n,m,a,b;
        cin>>n>>m>>a>>b;

        ll lasttime;

        if(a<b){lasttime=abs(a-b)+a-1;}
        else{lasttime=abs(a-b)+n-a;}

        ll arr[m];
        loop(i,0,m){cin>>arr[i];}
        sort(arr,arr+m);
        ll ans=0,diff=abs(a-b)-1,curtime=1;

        rloop(i,m-1,0)
        {
            if(diff==0){break;}

            if(curtime+arr[i]<=lasttime){ans++; diff--; curtime++;}
        }

        cout<<ans;
        nl;

    }

   return 0;

}
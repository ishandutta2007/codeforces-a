#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e6+5;
const int MOD=1e9+7;

int n, k1, k2;
int a[N], b[N];

int32_t main()
{
    IOS;
    cin>>n>>k1>>k2;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
    	cin>>b[i];
    }
    priority_queue<int> pq;
    for(int i=1;i<=n;i++)
    {
    	pq.push(abs(a[i]-b[i]));
    }
   	int ops=k1+k2;
   	while(ops>0)
   	{
   		int cur=pq.top();
   		pq.pop();
   		int now=abs(cur - 1);
   		pq.push(now);
   		ops--;
   	}
   	int ans=0;
   	while(!pq.empty())
   	{
   		int cur=pq.top();
   		ans+=cur*cur;
   		pq.pop();
   	}
   	cout<<ans;
    return 0;
}
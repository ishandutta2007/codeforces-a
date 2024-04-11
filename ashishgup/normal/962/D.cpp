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

int n;
int a[N];
map<int, int> m;

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(m.find(a[i])==m.end())
        {
            m[a[i]]=i;
            continue;
        }
        while(m.find(a[i])!=m.end() && m[a[i]]<i)
        {
            a[i]*=2;
            m.erase(a[i]/2);
        }
        m[a[i]]=i;
    }
    vector<pair<int, int> > v;
    for(auto it:m)
    {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end());
    cout<<v.size()<<endl;
    for(auto it:v)
    {
        cout<<it.second<<" ";
    }
    return 0;
}
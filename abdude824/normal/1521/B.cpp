// 
// 
// 
// 
// 
// 


#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ll long long int
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define W(x) int x;cin>>x;while(x--)
#define fr(n) for(int i=n-1;i>=0;i--)
#define mp make_pair
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define vi vector<int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define sortall(x) sort(all(x))
#define mk(arr,n,type)  type *arr=new type[n];
#define vpi vector<pair<int,int> >
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define sz(x) (int)x.size()
#define vs vector<string>
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define f first
#define s second
#define INT_SIZE 32
int mpow(int exp, int base);
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int32_t main()
{
    aeh();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int k = 0;
        vi a(n);
        fi(n){
          cin >> a[i];
        }
        int pos=0,mn=a[0];
        fi(n)
        {
          if(mn>a[i])
          {
            mn=a[i];
            pos=i;
          }
        }
        int cnt=0;
        vector<vector<int>> ans;
        fi(n)
        {
          if(i!=pos)
          {
            vi ans2;
            ans2.pb(i+1);
            ans2.pb(pos+1);
            a[i]=a[pos]+abs(pos-i);
            ans2.pb(a[i]);
            ans2.pb(a[pos]);
            ans.pb(ans2);
            cnt++;
          }
        }
        cout<<cnt<<endl;
        fi(ans.size())
        {
          fj(ans[i].size())
            cout<<ans[i][j]<<" ";
          cout<<endl;
        }
        // cout<<endl;

        // cout<<"\n";

    }
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
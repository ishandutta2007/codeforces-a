// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
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
    cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
int32_t main()
{
    aeh();
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char s[n][n];
        fi(n)
        {
            fj(n)
            {
                cin>>s[i][j];
            }
        }  
        int cnt=0;
        vpi ans;
        if(s[0][1]==s[1][0])
        {   
            if(s[n-1][n-2]==s[0][1])
            {
                cnt++;
                ans.pb(mp(n-1,n-2));
            }
            if(s[n-2][n-1]==s[0][1])
            {
                cnt++;
                ans.pb(mp(n-2,n-1));
            }
        }
        else{
            
            if(s[n-1][n-2]==s[n-2][n-1])
            {

                if(s[n-1][n-2]==s[0][1])
                {
                    cnt++;
                    ans.pb(mp(0,1));
                }
                if(s[n-2][n-1]==s[1][0])
                {
                    cnt++;
                    ans.pb(mp(1,0));
                }
            }
            else{
                cnt++;
                ans.pb(mp(1,0));
                if(s[n-1][n-2]!=s[1][0])
                {
                    cnt++;
                    ans.pb(mp(n-1,n-2));
                }

                if(s[n-2][n-1]!=s[1][0])
                {
                    cnt++;
                    ans.pb(mp(n-2,n-1));
                }
            }
        }
        cout<<cnt<<endl;
        fi(ans.size())
        {
            cout<<ans[i].f+1<<" "<<ans[i].s+1<<endl;
        }

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
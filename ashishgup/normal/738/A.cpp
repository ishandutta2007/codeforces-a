#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll>> vvll;

#define PI 3.141592653589793
#define MOD 1000000007


int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll i=0;
    for (i=0;i<n-2;i++)
    {
        char m = s[i];
        if (m!='o')
        {
            cout<<m;
            continue;
            
        }
        if (m=='o')
        {
            bool temp=false;
            if (s[i+1]=='g')
            {
                if (s[i+2]=='o')
                {
                    temp=true;
                    cout<<"***";
                    i=i+2;
                    bool check=true;
                    while(i<n-2&&check)
                    {
                        if(s[i+1]=='g'&&s[i+2]=='o')
                        {
                            i=i+2;
                        }
                        else
                        {
                            check=false;
                        }
                    }
                }
            }
            if(temp==false)
            {
                cout<<m;
            }
        }
    }
    while(i<n)
    {
        cout<<s[i++];
    }
    return 0;
}
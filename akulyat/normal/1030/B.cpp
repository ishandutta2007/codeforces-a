#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j,d;
vector <ll> m;
bool viv=false;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>d;
ll k;
cin>>k;
for (i=0; i<k; i++)
  {
  ll a,b;
  cin>>a>>b;
  if (abs(a-b)<=d&&a+b>=d&&a+b<=2*n-d)
    cout<<"YES"<<'\n';
  else
    cout<<"NO"<<'\n';
  }








    return 0;
}
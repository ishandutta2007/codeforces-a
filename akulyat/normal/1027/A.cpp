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


ll n,i,j;
vector <ll> m;
bool viv=false;


int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll l;
  string s;
  cin>>l>>s;
  bool can=true;
  for (j=0; j<l/2; j++)
    if ((abs(s[j]-s[l-1-j])>2)||(abs(s[j]-s[l-1-j])&1))
      can=false;
  if (can)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  }

    return 0;
}
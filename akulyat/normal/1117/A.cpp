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
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
ll ma=*max_element(m.begin(), m.end());
vector <ll> v(m.size(), 0);
if (m[0]==ma)
  v[0]=1;
for (ll i=1; i<n; i++)
  if (m[i]==ma)
    v[i]=v[i-1]+1;
cout<<*max_element(v.begin(), v.end());







    return 0;
}
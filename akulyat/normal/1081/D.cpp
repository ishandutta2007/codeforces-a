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
const long long gs=500*kk;

long n,m,i,j,k;
vector <long> reb[gs+10];
vector <long> e[gs+10];
vector <long> we[gs+10];
vector <long> w[gs+10];
vector <ll> col,tc,por,kol,ans;
bool viv=false;
set <ll> have;
set <pair<ll, pll> > all;
set <ll> vi;
void DFS(long v, long c)
{
col[v]=c;
long l=e[v].size();
for (long i=0; i<l; i++)
  {
  long s=e[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1);
    }
  }
}

void BFS(long v)
{
vector <long> st;
st.push_back(v);
long s=0;
tc[v]=0;

while (s<st.size())
  {
  long e=st[s];
  long l=reb[e].size();
  for (long i=0; i<l; i++)
    {
    long s=reb[e][i];
    if (tc[s]==-1)
      {
      st.push_back(s);
      tc[s]=tc[e]+1;
      }
    }
  s++;
  }

}

void add(ll v)
{
have.insert(v);
ll l=reb[v].size();
for (ll i=0; i<l; i++)
  {
  ll s=reb[v][i];
  ll wl=w[v][i];
  if (have.count(s))
    all.erase({wl, {s, v}});
  else
    all.insert({wl, {v, s}});
  }
}

void build(ll v)
{
add(v);
while(have.size()!=n)
  {
  auto a=*all.begin();
  ll nex=a.S.S;
  ll v1=a.S.F;
  ll wl=a.F;
  e[v1].push_back(nex),
  e[nex].push_back(v1),
  we[v1].push_back(wl),
  we[nex].push_back(wl);
  add(nex);
  }
}

vector <ll> prepare()
{
vector <pll> tos;
for (ll i=0; i<n; i++)
  tos.push_back({col[i], i});
sort(tos.rbegin(), tos.rend());
vector <ll> r;
for (auto i:tos)
  r.push_back(i.S);
return r;
}

void work(ll v)
{
ans[v]=-inf;
if (vi.count(v))
  ans[v]=0,
  kol[v]=1;
ll l=e[v].size();
for (ll i=0; i<l; i++)
  {
  ll s=e[v][i];
  if (col[s]>col[v])
    kol[v]+=kol[s];
  if (col[s]>col[v]&&ans[s]!=-inf)
    {
    ll wl=we[v][i];
    ans[v]=max(ans[v], max(wl, ans[s]));
    }
  }
}

void fin(ll v)
{
ll l=e[v].size();
for (ll i=0; i<l; i++)
  {
  ll s=e[v][i];
  ll wl=we[v][i];
  if (col[s]<col[v]&&kol[v]!=k)
    {
    ans[v]=max(ans[v], max(wl, ans[s]));
    }
  }
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m>>k;
for (ll i=0; i<k; i++)
  {ll a; cin>>a; a--; vi.insert(a);}
for (i=0; i<m; i++)
  {
  long a,b;
  ll c;
  cin>>a>>b>>c;
  a--; b--;
  if (a!=b)
    {
    reb[a].push_back(b);
    reb[b].push_back(a);
    w[a].push_back(c);
    w[b].push_back(c);
    }
  }
col.assign(n, -1);
tc.assign(n, -1);
build(0);
DFS(0, 0);
por=prepare();
ans.assign(n, -inf);
kol.assign(n, 0);
for (auto v:por)
  work(v);
reverse(por.begin(), por.end());
for (auto v:por)
  fin(v);
for (auto v:vi)
  cout<<ans[v]<<' ';
cout<<endl;

  return 0;
cout<<"Color ";
for (auto i:col)
  cout<<i<<' ';
cout<<endl;
cout<<"Poryadok ";
for (auto i:por)
  cout<<i<<' ';
cout<<endl;

for (ll i=0; i<n; i++)
  {
  cout<<i<<": ";
  for (ll j=0; j<e[i].size(); j++)
    cout<<"{"<<e[i][j]<<' '<<we[i][j]<<'}';
  cout<<endl;
  }


    return 0;
}
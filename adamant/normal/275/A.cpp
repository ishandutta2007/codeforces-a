#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <queue>

using namespace std;

/////////////////////////////////////////////////////////////
//////////////// ~* CODEFORCES TEMPLATE *~ //////////////////
/////////////////////////////////////////////////////////////


const int INF = 2000000000;


//   
int n;
const int MAXN=0;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;

//   

void dfs (int v) {
	used[v] = true;
	comp.push_back (v);
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (! used[to])
			dfs (to);
	}
}

//   

void find_comps() {
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (! used[i]) {
			comp.clear();
			dfs (i);
 
			cout << "Component:";
			for (size_t j=0; j<comp.size(); ++j)
				cout << ' ' << comp[j];
			cout << endl;
		}
}

//   

vector<int> p_bf;

vector<int> bfs(vector< vector<int> > g, int s)
{
int n=g.size();
queue<int> q;
q.push (s);
vector<bool> used (n);
vector<int> d (n), p (n);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
	int v = q.front();
	q.pop();
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to]) {
			used[to] = true;
			q.push (to);
			d[to] = d[v] + 1;
			p[to] = v;
		}
	}
}
p_bf=p;
return d;
}

//   O(N^2+M)
 
vector<int> p_d;
 
vector<int> dijkstra(vector < vector < pair<int,int> > > g, int s) 
{
    int n=g.size();
	vector<int> d (n, INF),  pn (n);
	d[s] = 0;
	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = true;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				pn[to] = v;
			}
		}
	}
	p_d=pn;
	return d;
}

//   O(M log N)

vector<int> p_ds;

vector<int> dijkstra_sparse(vector < vector < pair<int,int> > > g, int s) 
{
    int n=g.size();
	vector<int> d (n, INF),  ps (n);
	d[s] = 0;
	priority_queue < pair<int,int> > q;
	q.push (make_pair (0, s));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				ps[to] = v;
				q.push (make_pair (-d[to], to));
			}
		}
	}
	p_ds=ps;
	return d;
}

//     O(n)
int*pr/*=new int[6000000]*/;
int pr_s=0;
//    O(n)
int*erat_pl(int N)
{
int*lp=new int[N+1];
for(int i=0;i<N+1;i++)
lp[i]=0;
 
for (int i=2; i<=N; ++i) {
	if (lp[i] == 0) {
		lp[i] = i;
		pr[pr_s++]=i;
	}
	for (int j=0; j<(int)pr_s && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
		lp[i * pr[j]] = pr[j];
}
return lp;
}

//    O(n log log n)
int*erat(int n)
{
int*prime=new int[n+1];

for(int i=0;i<n+1;i++)
prime[i]=true;

prime[0] = prime[1] = false;
prime[2] = true;
for (int j=4; j<=n; j+=2)
				prime[j] = false;
for (int i=3; i*i<=n; i+=2)
	if (prime[i])
		if (i * 1ll * i <= n)
			for (int j=i*i; j<=n; j+=i)
				prime[j] = false;

return prime;
}

//    
int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

//   A   B   M
int powmod (int a, int b, int m) {
	int res = 1;
	while (b > 0)
		if (b & 1) {
			res = (res * a) % m;
			--b;
		}
		else {
			a = (a * a) % m;
			b >>= 1;
		}
	return res % m;
}

//  X, ,  N!   K^X   K
int fact_pow (int n, int k) {
	int res = 0;
	while (n) {
		n /= k;
		res += n;
	}
	return res;
}

//  N   P
int factmod (int n, int p) {
	int res = 1;
	while (n > 1) {
		res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
		for (int i=2; i<=n%p; ++i)
			res = (res * i) % p;
		n /= p;
	}
	return res % p;
}

// 
int gcd (int a, int b) 
{
	while (b) 
    {
		a %= b;
		swap (a, b);
	}
	return a;
}

// 
int lcm (int a, int b) 
{
	return a / gcd (a, b) * b;
}

/////////////////////////////////////////////////////////////
////////////////////// ~* STRINGS *~ ////////////////////////
/////////////////////////////////////////////////////////////

/*
Z-.       N.

z[i] -      a[0..n]
  i- ,   a[i..n]

*/

int*z_func(string a)
{
        int n=a.size(),l=0,r=0,z0,*z=new int[n];
        z[0]=0;
        for(int i=1;i<n;i++)
        {
                if(i>r)
                z0=0;
                else
                z0=min(r-i+1,z[i-l]);
                z[i]=z0;
                for(int j=z[i];j<n-i;j++,z[i]++)
                  if(!(a[j]==a[i+j]))
                  break;
                  if(z[i]-z0)
                  l=i,r=i+z[i]-z0-1;
        }    
        return z;
}

/* 
   ;
(  a#b,  z[i]=|a|,     )
*/

bool search_z(string a,string b)
{
                    string c=a+'#'+b;
                    int*z=z_func(c);
                    int n=c.size();
                    int as=a.size();
                    vector<int> tmp(n);
                    for(int i=as+1;i<n;i++)
                    if(z[i]==as)
                    return true;
                    return false;
}

/* 
    ;
(   .      , 
,  z-,    len-z_max)
*/
int differ_z(string a)
{
    int k=1;
    int n=a.size();
    string t;
    int*z;
    int z_max;
    for(int i=1;i<n;i++)
    {
            t=a.substr(0,i+1);
            reverse(t.begin(),t.end());
            z=z_func(t);
            z_max=0;
            for(int j=0;j<i+1;j++)
            if(z[j]>z_max)
            z_max=z[j];
            k+=i-z_max+1;
            cout<<k<<' '<<t<<' '<<z_max<<' '<<t.size()<<endl;
    }
    return k;
}
/*
 ;
(  i ,  i+z[i]=n,    i   n)
*/

int min_z(string a)
{
    int*z=z_func(a);
    int n=a.size();
    for(int i=1;i<n;i++)
    if(z[i]+i==n && !(n%i))
    return i;
    return n;
}

/*

-.       N.

z[i] -     a[i..n],
   .

*/

int*p_func(string s) 
{
	int n = s.size();
	int*pi=new int[n];
	pi[0]=0;
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

/////////////////////////////////////////////////////////////
////////////////////// ~* MAIN *~ ///////////////////////////
/////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    int a[3][3];
    bool b[3][3]={0,0,0,0,0,0,0,0,0};
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
    cin>>a[i][j];
    for(int k=0;k<a[i][j];k++)
    {
            b[i][j]=!b[i][j];
            if(i)
            b[i-1][j]=!b[i-1][j];
            if(j)
            b[i][j-1]=!b[i][j-1];
            if(i<2)
            b[i+1][j]=!b[i+1][j];
            if(j<2)
            b[i][j+1]=!b[i][j+1];
    }
    }
    
    for(int i=0;i<3;i++)
    {
    for(int j=0;j<3;j++)
    cout<<!b[i][j];
    cout<<endl;
    }
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}
#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N], b[N], p[N], ans[N];

struct graph {
    int n, m;
    vector <int> v, wa, wb;
    vector <vector <int>> adj;

    graph() {}
    graph(int n) : n(n), m(0) {
        adj.resize(n + 1, vector <int>());
    }

    void add_edge(int ui, int vi, int wai, int wbi) {
        v.push_back(vi);
        wa.push_back(wai);
        wb.push_back(wbi);
        adj[ui].push_back(m++);
    }
};

vector <ll> bi;
void dfs(graph &g, int x, ll A) {
	ans[x] = upper_bound(all(bi), A) - bi.begin() - 1;
	for (auto it : g.adj[x]) {
		bi.pb(bi.back() + g.wb[it]);
		dfs(g, g.v[it], A + g.wa[it]);
		bi.pop_back();
	}
}

void solve() {
	cin >> n;
	graph g(n);
	for (int i = 2; i <= n; i++) {
		cin >> p[i] >> a[i] >> b[i];
		g.add_edge(p[i], i, a[i], b[i]);
	}
	bi.pb(0);
	dfs(g, 1, 0);
	bi.pop_back();
	for (int i = 2; i <= n; i++) cout << ans[i] << " ";
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}
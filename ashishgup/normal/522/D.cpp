#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

struct data
{
	//Use required attributes
	int mn;

	//Default Values
	data() : mn(1e9) {};
};

struct SegTree
{
	int N;
	vector<data> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = min(l.mn, r.mn);
	}

	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
		st[node].mn = lazy[node];
		cLazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = 1e9;
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		data left=Query(node*2, L, M, i, j);
		data right=Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}

	data pQuery(int node, int L, int R, int pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
	}	

	void Update(int node, int L, int R, int i, int j, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pUpdate(int node, int L, int R, int pos, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	data query(int pos)
	{
		return pQuery(1, 1, N, pos);
	}

	data query(int l, int r)
	{
		return Query(1, 1, N, l, r);
	}

	void update(int pos, int val)
	{
		pUpdate(1, 1, N, pos, val);
	}

	void update(int l, int r, int val)
	{
		Update(1, 1, N, l, r, val);
	}
};

int n, m;
int a[N], ans[N];
map<int, int> idx;
vector<pair<int, int> > q[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	SegTree st;
	st.init(n);
	for(int i=1;i<=m;i++)
	{
		int l, r;
		cin>>l>>r;
		q[r].push_back({l, i});
	}
	for(int i=1;i<=n;i++)
	{
		int prev = idx[a[i]];
		idx[a[i]] = i;
		if(prev)
			st.update(prev, i - prev);
		for(auto &it:q[i])
		{
			int curans = st.query(it.first, i).mn;
			if(curans == 1e9)
				curans = -1;
			ans[it.second] = curans;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}
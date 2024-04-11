#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int N = 200010;

class T_SAT {
	vector<int> A[N], T[N];
	int tag[N], somev[N];
	vector<int> in[N]; int incnt[N];
	vector<int> out[N];
	int noot[N];

	stack<int> S;
	bool vis1[N];
	void dfs1(int u)
	{
		vis1[u] = true;
		for (auto v : A[u])
			if (!vis1[v])
				dfs1(v);
		S.push(u);
	}

	bool vis2[N];
	void dfs2(int u, int k)
	{
		vis2[u] = true;
		tag[u] = k;
		for (auto v : T[u])
			if (!vis2[v])
				dfs2(v, k);
			else if (tag[v] != k)
			{
				in[k].push_back(tag[v]);
				out[tag[v]].push_back(k);
			}
	}

	int dagN;
	void makeDag(int n)
	{
		memset(tag, -1, sizeof(tag));
		memset(vis1, 0, sizeof(vis1));
		memset(vis2, 0, sizeof(vis2));
		Loop(i, 0, n)
			if (!vis1[i])
				dfs1(i);
		dagN = 0;
		while (!S.empty())
		{
			int u = S.top(); S.pop();
			if (!vis2[u])
			{
				somev[dagN] = u;
				dfs2(u, dagN++);
			}
		}
	}

	bool did[N];
	bool ans[N];
	queue<int> source;
	void remove(int x)
	{
		for (int u : out[x])
		{
			incnt[u]--;
			if (incnt[u] == 0)
				source.push(u);
		}
	}
	bool solve()
	{
		int so;
		do
		{
			if (source.empty())
				return true;
			so = source.front(); source.pop();
		} while (did[so]);
		int si = tag[noot[somev[so]]];
		if (si == so)
			return false;
		ans[si] = 1;
		ans[so] = 0;
		did[si] = true;
		did[so] = true;
		remove(si);
		remove(so);
		return solve();
	}

	int satn = 0;
	int mapp[N];
	bool exist = false;

public:

	T_SAT() { memset(mapp, -1, sizeof(mapp)); }

	bool Exist() { return exist; }

	bool Solve()
	{
		makeDag(satn);
		Loop(i, 0, dagN)
			if (incnt[i] == 0)
				source.push(i);
		exist = solve();
		return exist;
	}

	void addClaw(int x1, int x2, bool b1, bool b2)
	{
		if (mapp[x1] == -1)
		{
			mapp[x1] = satn++;
			noot[mapp[x1]] = satn++;
			noot[noot[mapp[x1]]] = mapp[x1];
		}
		if (mapp[x2] == -1)
		{
			mapp[x2] = satn++;
			noot[mapp[x2]] = satn++;
			noot[noot[mapp[x2]]] = mapp[x2];
		}
		x1 = mapp[x1]; if (b1) x1 = noot[x1];
		x2 = mapp[x2]; if (b2) x2 = noot[x2];
		A[noot[x1]].push_back(x2);
		A[noot[x2]].push_back(x1);
		T[x1].push_back(noot[x2]);
		T[x2].push_back(noot[x1]);
	}

	bool Ans(int x) { return ans[tag[mapp[x]]];  }
}sat;

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	pii q[1010];
	Loop(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		q[i] = { a,b };
	}
	Loop(i, 0, m)
	{
		Loop(j, i+1, m)
		{
			int l1 = q[i].first, r1 = q[i].second;
			int l2 = q[j].first, r2 = q[j].second;
			if ((l1 < l2 && r1 < r2 && l2 < r1) || (l1 > l2 && r1 > r2 && l1 < r2))
			{
				sat.addClaw(i, j, 0, 0);
				sat.addClaw(i, j, 1, 1);
			}
		}
	}
	if (!sat.Solve())
		Kill("Impossible");
	Loop(i, 0, m)
		cout << (sat.Ans(i) ? 'o' : 'i');
}
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace __gnu_pbds;
using namespace std;

#define vi vector<int>


#define ll long long
#define ld long double
#define mp make_pair
#define what_is(x) cerr << #x << " is " << x << endl;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
/*
int p = 10;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}
*/

vector<int> Z(vector<int> s)
{
    int n = s.size();
    vector<int> z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
    return z;
}

mt19937 rnd(time(0));
/*
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct CHT : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a /b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
        isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
*/



/*
typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 1000000000;

struct MaxFlow {
  int N;
  VVI cap, flow;
  VI dad, Q;

  MaxFlow(int N) :
    N(N), cap(N, VI(N)), flow(N, VI(N)), dad(N), Q(N) {}

  void AddEdge(int from, int to, int cap) {
    this->cap[from][to] += cap;
  }

  int BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), -1);
    dad[s] = -2;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < N; i++) {
        if (dad[i] == -1 && cap[x][i] - flow[x][i] > 0) {
          dad[i] = x;
          Q[tail++] = i;
        }
      }
    }

    if (dad[t] == -1) return 0;

    int totflow = 0;
    for (int i = 0; i < N; i++) {
      if (dad[i] == -1) continue;
      int amt = cap[i][t] - flow[i][t];
      for (int j = i; amt && j != s; j = dad[j])
        amt = min(amt, cap[dad[j]][j] - flow[dad[j]][j]);
      if (amt == 0) continue;
      flow[i][t] += amt;
      flow[t][i] -= amt;
      for (int j = i; j != s; j = dad[j]) {
        flow[dad[j]][j] += amt;
        flow[j][dad[j]] -= amt;
      }
      totflow += amt;
    }

    return totflow;
  }

  int GetMaxFlow(int source, int sink) {
    int totflow = 0;
    while (int flow = BlockingFlow(source, sink))
      totflow += flow;
    return totflow;
  }
};*/

/*
struct DSU
{
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int k;
    cin>>k;
    vector<vector<ll>> a(k);
    for (int i = 0; i<k; i++)
    {
        int n;
        cin>>n;
        a[i].resize(n);
        for (int j = 0; j<n; j++) cin>>a[i][j];
    }

    vector<ll> sums(k);
    for (int i = 0; i<k; i++)
    {
        for (auto it: a[i]) sums[i]+=it;
    }

    ll total = 0;
    for (auto it: sums) total+=it;
    if (total%k!=0) {cout<<"No"; return 0;}
    ll need = total/k;


    vector<pair<ll, int>> ans(k);
    vector<ll> to_add(k);

    for (int i = 0; i<k; i++) to_add[i] = need - sums[i];

    set<ll> guys;
    for (auto vec: a)
        for (auto it: vec) guys.insert(it);
    map<ll, int> where;

    for (int i = 0; i<k; i++)
        for (auto it: a[i]) where[it] = i;

    vector<ll> repr((1<<k), -1);

    //cout<<"1"<<endl;

    for (int i = 0; i<k; i++)
    {
        for (auto it: a[i])
        {
            vector<bool> visited(k);
            visited[i] = true;
            ll nxt = it + to_add[i];
            while (nxt!=it)
            {
                if (guys.find(nxt)==guys.end()) break;
                if (visited[where[nxt]]) break;
                visited[where[nxt]] = true;
                nxt = nxt + to_add[where[nxt]];
            }
            if (nxt==it)
            {
                int res = 0;
                for (int j = 0; j<k; j++) if (visited[j]) res+=(1<<j);
                repr[res] = it;
            }
        }
    }

    //cout<<"2"<<endl;

    /*for (auto it: to_add) cout<<it<<' ';
    cout<<endl;*/


    //for (int i = 0; i<(1<<k); i++) cout<<i<<": "<<repr[i]<<endl;

    vector<int> dp((1<<k), -1);
    dp[0] = 1;
    for (int i = 1; i<(1<<k); i++)
    {
        //cout<<"number "<<i<<": "<<endl;
        for (int mask = i ; mask>0; mask=i&(mask-1))
        {
            //cout<<"mask "<<mask<<endl;
            if (repr[mask]!=-1 && dp[(i^mask)]!=-1) dp[i] = mask;
        }
        //cout<<i<<": "<<dp[i]<<endl;
    }

    //cout<<"3"<<endl;

    if (dp[(1<<k)-1]==-1)
    {
        cout<<"No"; return 0;
    }
    cout<<"Yes"<<endl;

    //cout<<"4"<<endl;

    int cur = (1<<k)-1;
    while (cur>0)
    {
        int t = dp[cur];
        ll rep = repr[t];
        while (true)
        {
            ll temp = rep + to_add[where[rep]];
            ans[where[temp]] = mp(temp, where[rep]);
            rep = temp;
            if (rep==repr[t]) break;
        }
        cur = cur^t;
    }

    for (auto it: ans) cout<<it.first<<' '<<it.second+1<<endl;



}
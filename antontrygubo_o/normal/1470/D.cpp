#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using ll = long long;
using ld = long double;



#define mp make_pair

const int p =  1e9 + 7;

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


mt19937 rnd(time(0));


const int N = 2000005;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}




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
};

void solve()
{;
    int n, m;
    cin>>n>>m;
    DSU dsu(n);
    vector<vector<int>> G(n);
    for (int i = 0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        u--; v--; G[u].push_back(v); G[v].push_back(u);
        dsu.union_sets(u, v);
    }
    for (int i = 1; i<n; i++) if (dsu.find_set(0)!=dsu.find_set(i)) {cout<<"NO"<<endl; return;}

    set<int> in;
    set<int> pending;

    vector<int> answer;
    in.insert(0);
    answer.push_back(0);
    for (auto it: G[0])
    {
        in.insert(it);
        for (auto s: G[it]) pending.insert(s);
    }

    while (pending.size()>0)
    {
        auto v = *(pending.begin());
        pending.erase(v);
        if (in.count(v)) continue;

        answer.push_back(v);
        in.insert(v); for (auto it: G[v])
        {
            if (in.count(it)==0)
            {
                in.insert(it); for (auto v: G[it]) pending.insert(v);
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout<<"YES"<<endl;
    cout<<answer.size()<<endl;
    for (auto it: answer) cout<<it+1<<' ';
    cout<<endl;

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();




}
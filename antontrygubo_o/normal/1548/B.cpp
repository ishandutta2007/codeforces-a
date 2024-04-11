#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair

const int MOD =  1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));

/*
const int LIM = 300000;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

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
        return find_set(parent[v]);
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

struct SegmentTree
{
    int n; vector<ll> t;

    void build(vector<ll> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = __gcd(t[v*2], t[v*2+1]);
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return __gcd(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    SegmentTree(vector<ll> a)
    {
        n = a.size();
        t.resize(4*n);
        build(a, 1, 0, n-1);
    }

    ll query(int l, int r)
    {
        return query(1, 0, n-1, l, r);
    }

};

void solve()
{
    int n; cin>>n;
    vector<ll> a(n); for (int i = 0; i<n; i++) cin>>a[i];
    vector<ll> b(n-1); for (int i = 0; i<n-1; i++) b[i] = abs(a[i+1]-a[i]);

    if (n==1)
    {
        cout<<1<<endl; return;
    }

    n--;

    /*vector<vector<ll>> bin(n, vector<ll>(20));

    for (int i = 0; i<n; i++) bin[i][0] = b[i];

    for (int iter = 1; iter<20; iter++)
    {
        int len = (1<<(iter-1));
        for (int i = 0; i<n; i++)
        {

        }
    }*/

    SegmentTree tree(b);

    if (tree.query(0, n-1)>=2) {cout<<n+1<<endl; return;}

    int L = 0; int R = n;
    while (R-L>1)
    {
        int mid = (L+R)/2;
        bool check = false;
        for (int i = 0; i+mid-1<n; i++) if (tree.query(i, i+mid-1)>=2) {check = true; break;}
        if (check) L = mid; else R = mid;
    }

    cout<<L+1<<endl;
    return;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();

}
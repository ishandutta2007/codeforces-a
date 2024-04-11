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

int MOD =  998244353;

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


const int LIM = 400005;

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
}

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

int n, m;

ordered_set X;

int le(int k)
{
    return k - X.order_of_key(k+1);
}

int find_kth(int k)
{
    int L = 1; int R = n;
    if (le(L)==k) return L;
    while (R-L>1)
    {
        int mid = (L+R)/2;
        if (le(mid)>=k) R = mid; else L = mid;
    }
    return R;
}

void solve()
{
    cin>>n>>m;

    vector<int> x(m), y(m);
    for (int i = 0; i<m; i++) cin>>x[i]>>y[i];

    X.clear();

    int cnt = 0;

    for (int i = m-1; i>=0; i--)
    {
        int val1 = find_kth(y[i]);

        int val2 = find_kth(y[i]+1);

        //cout<<val1<<' '<<val2<<endl;

        if (val1+1==val2) cnt++;
        X.insert(val1);
    }
    cout<<C(2*n-cnt-1, n)<<endl;

    //from 1 to n with cnt breaks?

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    init();

    int t; cin>>t; while (t--) solve();

}

/*
1
3 2
2 1
3 1
 */
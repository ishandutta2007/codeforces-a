#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

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


const int MOD =  998244353;

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
const int LIM = 1e6 + 5;

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


/*struct DSU
{
    vector<int> sz;
    vector<int> parent;
    vector<int> value;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
        value[v] = 0;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        else
        {
            auto par = find_set(parent[v]);
            value[v]^=value[parent[v]];
            parent[v] = par;
            return par;
        }
    }

    void union_sets(int a, int b, int w) {
        find_set(a);
        find_set(b);

        w^=value[a]; w^=value[b];
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            value[b] = w;
            sz[a] += sz[b];
        }
    }

    int val(int v)
    {
        find_set(v); return value[v];
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        value.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

bool check(string s)
{
    int n = s.size();
    int balance = 0;
    for (auto c: s)
    {
        if (c==')') balance--; else balance++;
        if (balance<0) return false;
    }
    if (balance!=0) return false;
    return true;
}

void solve()
{
    string s; cin>>s;
    for (int mask = 0; mask<8; mask++)
    {
        string s1;
        for (auto c: s)
        {
            if (mask&(1<<(c-'A'))) s1+='('; else s1+=')';
        }
        if (check(s1)) {cout<<"YES"<<endl; return;}
    }
    cout<<"NO"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while (t--) solve();


}
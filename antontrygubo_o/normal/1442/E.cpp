#include <bits/stdc++.h>

using namespace std;

/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using ll = long long;
using ld = long double;



#define mp make_pair

const int p = 998244353;

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

/*
const int N = 1200000;

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

*/


/*struct DSU
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

/*
int mex(set<int> a)
{
    int cur = 0;
    while (a.count(cur)) cur++;
    return cur;
}

void solve(vector<int> a)
{
    int n = a.size();

    vector<vector<int>> nim(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i<n-1; i++) nim[i][n-1] = 0;
    for (int r = n-2; r>=0; r--)
        for (int l = r-1; l>=0; l--)
        {
            set<int> lol;
            for (int j = r+1; j<n; j++) if (a[j]-a[r]>a[r]-a[l]) {lol.insert(nim[r][j]); dp[l][r] = max(dp[l][r], 1 + dp[r][j]);}
            nim[l][r] = mex(lol);
        }



    for (auto it: a) cout<<it<<' ';
    cout<<endl;

    for (int i = 0; i<n; i++)
    {
        for (int j = i+1; j<n; j++) cout<<i<<' '<<j<<": "<<nim[i][j]<<' '<<dp[i][j]<<endl;
        cout<<endl;
    }

    //cout<<nim[0][1]<<endl;

}*/

int n;
vector<int> a;
vector<vector<int>> G;
vector<int> white, black;

bool good = true;

const int MAX = 500000;

int bound;

void dfs(int v, int par = -1)
{
    for (auto it: G[v]) if (it!=par) dfs(it, v);
    white[v] = MAX;
    black[v] = MAX;
    if (a[v]!=1) // black
    {
        vector<int> guys;
        for (auto it: G[v]) if (it!=par) guys.push_back(min(black[it], white[it]+1));
        sort(guys.begin(), guys.end());
        if (guys.size()==0) black[v] = 0;
        else if (guys.size()==1)
        {
            black[v] = guys[0];
        }
        else
        {
            if (guys[guys.size()-1] + guys[guys.size()-2]<=bound) black[v] = guys[guys.size()-1];
        }
    }
    if (a[v]!=2) // white
    {
        vector<int> guys;
        for (auto it: G[v]) if (it!=par) guys.push_back(min(white[it], black[it]+1));
        sort(guys.begin(), guys.end());
        if (guys.size()==0) white[v] = 0;
        else if (guys.size()==1)
        {
            white[v] = guys[0];
        }
        else
        {
            if (guys[guys.size()-1] + guys[guys.size()-2]<=bound) white[v] = guys[guys.size()-1];
        }
    }
    if (black[v]>bound && white[v]>bound) good = false;
}

bool check(int t)
{
    bound = t;
    white.clear(); black.clear();
    white.resize(n); black.resize(n);
    good = true;
    dfs(n-1);
    return good;
}

void solve()
{
    a.clear(); G.clear();
    cin>>n;
    a.resize(n); G.resize(n);

    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        u--; v--;
        G[u].push_back(v); G[v].push_back(u);
    }

    int L = 0;
    int R = 300000;
    if (check(L)) {cout<<1<<'\n'; return;}
    while (R-L>1)
    {
        int mid = (L+R)/2;
        if (check(mid)) R = mid; else L = mid;
    }

    cout<<(R+3)/2<<'\n';

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();


}

/*
8 7
2 1
2 3
3 4
 */

/*
23 22
2 1
2 3
3 4
5 4
5 6
7 6
7 8
9 8
9 10
11 10
11 12
13 12
13 14
15 14
15 16
17 16
17 18
19 18
19 20
21 20
21 22
23 22
 */
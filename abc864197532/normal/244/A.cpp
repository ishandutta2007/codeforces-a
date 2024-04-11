#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a;
    cin >> n >> k;
    set <int> s;
    fop (i,1,n * k + 1) s.insert(i);
    vector <int> aa;
    fop (i,0,k) {
        cin >> a;
        s.erase(a);
        aa.pb(a);
    }
    fop (i,0,k) {
        cout << aa[i] << ' ';
        fop (i,1,n) cout << *s.begin() << ' ', s.erase(s.begin());
        cout << endl;
    }
}
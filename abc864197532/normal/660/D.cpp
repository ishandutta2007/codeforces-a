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
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17, K = 500;

struct Pt {
    lli x, y;
    Pt (lli _x = 0, lli _y = 0) : x(_x), y(_y) {}
    Pt operator + (const Pt &other) {
        return Pt(x + other.x, y + other.y);
    }
    Pt operator - (const Pt &other) {
        return Pt(x - other.x, y - other.y);
    }
    Pt operator * (const int &k) {
        return Pt(x * k, y * k);
    }
    lli operator * (const Pt &other) { // dot
        return x * other.x + y * other.y;
    }
    lli operator ^ (const Pt &other) { // cross
        return x * other.y - y * other.x;
    }
};

struct cmp {
    bool operator () (Pt a, Pt b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <Pt> a(n);
    map <Pt, int, cmp> m1;
    lli ans = 0;
    fop (i,0,n) {
        cin >> a[i].x >> a[i].y;
        fop (j,0,i) {
            Pt p = a[i] + a[j];
            ans += m1[p];
            m1[p]++;
        }
    }
    cout << ans << endl;
}
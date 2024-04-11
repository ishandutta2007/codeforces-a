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
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 30087, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    sort(rall(s));
    if (s.length() < t.length()) {
        cout << s << endl;
    } else {
        string ans;
        int n = s.length();
        fop (i,0,n + 1) {
            vector <int> cnt(10, 0);
            for (char c : s) cnt[c - '0']++;
            string cur;
            bool is = true;
            fop (j,0,i) {
                if (!cnt[t[j] - '0']) {
                    is = false;
                    break;
                }
                cur += t[j];
                cnt[t[j] - '0']--;
            }
            if (is) {
                if (i == n) {
                    ans = max(ans, cur);
                    break;
                }
                bool iss = false;
                FOP (j,t[i] - '0', 0) if (cnt[j]) {
                    cur += '0' + j;
                    cnt[j]--;
                    iss = true;
                    break;
                }
                if (iss) {
                    FOP (i,10,0) while (cnt[i]) cur += '0' + i, cnt[i]--;
                    ans = max(ans, cur);
                }
            }
        }
        cout << ans << endl;
    }
}
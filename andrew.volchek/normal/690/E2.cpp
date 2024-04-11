#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <tuple>
#include <complex>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 605;
const ld inf = 1e20;

int a[maxn][maxn];
ld b[maxn][maxn];
ld dp[1 << 16][16];
pair<int,int> pr[1 << 16][16];
ld g[16][16];

string answer[] = {
        "2 1",
        "2 3 1",
        "4 3 2 1",
        "1 3 4 2 5",
        "1 6 11 3 10 9 15 12 7 13 2 5 4 14 8",
        "5 1 3 11 10 7 6 9 13 15 12 4 14 2 8",
        "9 7 2 5 1 10 8 3 4 6",
        "2 1 4 3",
        "4 12 8 2 9 14 5 7 1 6 10 13 15 3 11",
        "11 5 6 8 10 12 7 2 1 4 9 3 13 14 15",
        "5 1 2 13 14 9 7 8 12 3 6 11 10 4 15",
        "12 7 11 4 10 2 5 14 13 1 6 3 9 8 15 16",
        "3 2 1",
        "4 2 1 3 5",
        "1 8 11 15 3 2 7 16 13 4 6 10 9 12 5 14",
        "9 8 6 13 11 10 2 7 14 12 5 4 15 3 1",
        "11 8 9 3 1 14 2 12 4 16 10 7 5 13 15 6",
        "15 5 2 14 3 13 1 7 12 8 4 10 6 11 9",
        "9 7 3 15 2 12 13 5 1 14 11 10 8 4 6",
        "9 7 13 10 15 16 5 3 6 1 2 11 8 4 14 12",
        "6 13 2 11 5 10 3 14 9 1 12 8 16 4 15 7",
        "2 7 16 14 13 8 5 10 4 12 11 1 6 9 3 15",
        "3 2 6 14 7 12 10 9 5 4 8 15 11 13 1",
        "3 11 4 5 14 10 16 9 8 6 7 13 12 1 15 2",
        "4 3 11 9 8 16 6 15 2 13 7 14 10 1 12 5",
        "1 12 9 7 6 5 2 13 14 10 15 8 11 4 3",
        "2 1 3",
        "2 1",
        "1 3 2 6 4 8 7 5",
        "14 7 8 6 1 9 13 5 2 4 11 15 16 10 3 12",
        "1 7 4 3 6 5 2 8",
        "13 7 6 14 12 15 3 5 1 9 8 10 4 11 2",
        "11 2 15 5 14 3 9 10 7 1 12 13 8 6 4",
        "4 2 3 1",
        "16 13 11 14 9 2 15 3 1 5 6 7 12 8 4 10",
        "3 1 4 9 16 15 7 10 6 13 5 11 2 14 12 8",
        "14 16 13 4 9 10 12 8 7 11 3 5 15 6 2 1",
        "3 1 6 5 2 4",
        "14 8 2 10 6 16 9 7 15 4 1 3 11 13 5 12",
        "15 8 10 9 11 12 7 13 5 14 1 4 3 2 6",
        "5 7 3 10 6 12 8 4 11 1 2 9",
        "2 1",
        "13 14 8 6 4 7 5 10 3 11 2 9 15 12 1",
        "2 15 11 13 12 5 3 4 9 8 14 6 10 1 7",
        "3 1 4 2",
        "6 2 16 5 7 10 15 1 8 14 13 4 9 11 3 12",
        "3 1 2",
        "16 4 13 11 7 9 5 2 10 3 6 15 12 14 8 1",
        "2 5 1 9 15 7 3 11 13 4 8 12 6 14 10",
        "6 3 16 14 13 12 7 2 5 11 4 15 8 1 10 9",
        "5 7 11 3 10 15 2 9 4 8 14 13 16 12 1 6",
        "4 11 12 13 5 3 16 10 6 9 8 2 1 14 7 15",
        "6 5 2 10 12 8 4 13 9 11 1 15 3 14 7",
        "12 13 9 1 3 11 4 8 15 14 10 7 16 5 6 2",
        "4 2 3 1",
        "10 3 15 2 12 7 11 4 16 6 13 9 14 8 5 1",
        "6 3 1 5 2 4",
        "14 11 7 5 6 15 3 4 2 10 1 13 8 9 12",
        "10 8 2 11 15 5 1 13 16 12 14 9 6 4 3 7",
        "8 2 15 11 9 12 16 6 13 7 4 5 14 1 10 3",
        "3 9 10 13 6 16 5 4 8 7 12 11 1 15 14 2",
        "1 2 6 12 5 15 4 3 9 13 8 7 14 11 10",
        "6 7 3 2 5 8 1 9 10 4",
        "11 10 12 15 3 13 1 16 2 8 4 5 6 14 7 9",
        "8 1 13 15 7 10 5 9 3 2 6 4 12 11 14",
        "12 6 11 14 1 5 4 8 10 16 15 7 3 9 2 13",
        "3 2 1",
        "4 7 8 2 1 6 5 3",
        "2 1",
        "1 10 14 13 7 11 8 12 16 9 15 6 5 3 2 4",
        "15 9 2 8 1 4 14 13 5 3 12 6 7 11 10",
        "4 1 5 2 3",
        "1 8 3 11 9 5 6 7 4 2 10 12",
        "1 11 6 2 5 14 10 8 9 15 12 3 7 16 4 13",
        "16 15 12 3 14 11 8 9 6 1 2 13 10 7 5 4",
        "11 16 14 3 6 12 4 1 2 8 7 13 10 9 15 5",
        "15 14 4 6 9 5 3 2 13 12 10 11 7 1 8",
        "4 1 6 2 11 7 10 8 5 16 12 13 15 14 3 9",
        "4 3 5 14 6 8 16 10 9 12 2 11 13 15 7 1",
        "1 4 5 10 9 6 8 3 2 7",
        "7 6 15 5 12 13 2 4 3 14 11 1 10 8 9",
        "2 14 9 3 8 7 6 15 10 11 16 5 12 13 1 4",
        "2 5 9 1 11 4 16 6 8 7 12 3 13 10 15 14",
        "3 5 7 14 1 9 6 4 10 8 11 15 2 16 12 13",
        "15 14 10 13 1 5 2 12 4 11 8 9 6 7 3 16",
        "6 1 4 16 2 9 8 5 12 11 10 13 3 7 14 15",
        "16 14 9 8 4 1 7 2 12 10 3 5 11 6 15 13",
        "6 1 5 2 4 3",
        "3 10 4 5 9 6 1 2 7 8",
        "8 1 15 10 12 5 14 11 4 2 3 13 7 9 6",
        "5 13 12 7 9 1 10 4 15 8 3 2 14 6 11",
        "2 3 6 1 4 5",
        "3 15 13 6 7 11 12 1 14 4 8 9 2 10 5",
        "14 7 8 6 12 13 16 15 3 10 11 9 1 4 5 2",
        "7 2 4 13 9 1 15 8 12 11 6 3 5 14 10",
        "3 4 5 6 15 8 9 10 14 12 11 13 7 2 1",
        "4 11 5 12 8 14 10 7 3 9 16 13 15 1 6 2",
        "2 6 3 1 4 5",
        "6 5 7 9 2 8 3 1 4 10",
        "14 7 15 11 1 4 3 13 5 10 6 9 8 2 12",
        "15 14 5 3 7 4 1 9 11 6 10 2 12 13 8",
        "16 14 3 7 13 2 6 1 10 12 9 4 5 8 11 15",
        "3 8 5 10 12 11 4 6 7 9 2 1",
        "11 3 5 4 12 8 1 2 6 7 9 10",
        "3 11 6 16 13 15 5 2 12 7 14 8 10 9 4 1",
        "6 5 1 4 3 2",
        "1 4 2 10 12 11 9 5 6 13 3 14 15 8 7",
        "7 13 10 5 2 12 6 3 8 4 15 11 1 9 14",
        "12 5 7 8 1 9 10 15 6 4 14 13 3 2 11",
        "2 5 3 9 13 4 7 12 6 14 10 11 15 1 8",
        "5 4 2 6 1 3",
        "4 8 9 1 5 13 11 7 3 12 2 6 14 15 10",
        "2 1",
        "11 5 7 9 15 2 8 14 3 13 10 12 1 6 4",
        "5 14 15 4 13 6 8 10 7 12 2 11 16 3 9 1",
        "12 8 7 2 3 9 15 5 11 6 4 14 13 1 10",
        "14 7 11 13 2 3 12 1 10 9 5 8 4 15 6",
        "6 4 3 5 1 2 7 8",
        "1 9 13 4 6 14 11 7 2 15 12 8 5 10 3 16",
        "3 5 1 8 2 9 7 12 4 11 10 6",
        "2 5 4 9 11 12 13 6 3 1 15 10 8 7 14",
        "13 6 8 11 12 15 1 2 10 9 7 14 3 5 4",
        "2 11 15 12 5 8 9 1 14 10 4 3 6 7 13",
        "5 8 16 3 10 6 14 7 1 15 12 9 13 2 11 4",
        "10 12 1 16 11 4 2 15 6 7 13 14 5 3 8 9",
        "1 2 5 3 4",
        "6 5 1 4 2 3",
        "8 4 7 5 6 1 2 3",
        "4 2 3 1",
        "4 5 6 8 3 1 2 9 10 7",
        "1 8 10 12 14 13 16 11 9 4 3 2 7 5 15 6",
        "2 1",
        "1 10 3 2 13 4 11 9 5 14 12 6 7 15 8",
        "15 13 8 2 7 11 6 5 14 9 10 12 3 4 1",
        "2 1",
        "8 4 5 10 6 1 14 13 12 9 2 3 11 15 7",
        "10 3 6 8 5 11 14 16 7 1 9 2 13 4 15 12",
        "7 5 6 2 4 1 8 3",
        "10 2 7 9 11 6 1 8 3 5 12 4",
        "4 2 3 1",
        "3 13 9 7 11 15 14 10 5 2 16 12 4 8 1 6",
        "1 6 10 4 15 5 3 13 7 12 9 2 8 11 14",
        "2 7 14 16 13 8 3 15 12 11 1 4 6 5 10 9",
        "4 3 1 2 5",
        "3 4 11 7 15 1 13 10 9 14 16 12 5 8 2 6",
        "4 9 14 7 12 3 10 5 13 1 2 11 8 6 15",
        "10 9 16 13 7 3 12 4 15 8 5 1 11 2 6 14",
        "2 1",
        "14 4 1 2 13 6 3 5 12 10 7 9 15 8 11",
        "3 4 1 6 2 5",
        "5 10 4 6 2 8 11 9 1 7 3 13 15 14 12",
        "2 4 1 3",
        "16 14 12 11 7 3 2 6 1 9 4 10 15 13 5 8",
        "13 14 1 4 16 15 2 11 5 8 10 9 6 12 7 3",
        "4 2 1 3",
        "8 11 3 4 1 10 14 6 13 7 15 2 12 5 9",
};

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    //gen();
    freopen("all.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("lock.in", "r", stdin);
    //freopen("lock.out", "w", stdout);
#endif

    int tt;
    scanf("%d", &tt);

    for (int i = 0; i < tt; i++) {
        cout << answer[i] << endl;
    }

    return 0;
    while (tt--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                b[i][j] = 0;
            }
        }

        int f = n / k;


        for (int u = 0; u < n; u += f) {
            for (int i = u; i < u + f; i++) {
                for (int j = 0; j < m; j++) {
                    auto valid = [&](int x, int y) {
                        return u <= x && x < u + f && 0 <= y && y < m;
                    };

                    int cnt = 0;
                    for (int dx = -2; dx <= 2; dx++) {
                        for (int dy = -2; dy <= 2; dy++) {
                            int x = i + dx;
                            int y = j + dy;
                            if (valid(x, y)) {
                                cnt++;
                                b[i][j] += a[x][y];
                            }
                        }
                    }

                    b[i][j] /= cnt;
                }
            }
        }


        for (int i = 0; i < k; i++) {
            int r1 = i * f + f - 1;
            for (int j = 0; j < k; j++) {
                int r2 = j * f;

                g[i][j] = 0;

                for (int h = 0; h < m; h++) {
                    g[i][j] += sqr(b[r1][h] - b[r2][h]);
                }
            }
        }

        for (int i = 0; i < (1 << k); i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = inf;
            }
        }

        for (int i = 0; i < k; i++) {
            dp[1 << i][i] = 0;
            pr[1 << i][i] = mp(0, 0);
        }


        for (int i = 0; i < (1 << k); i++) {
            for (int lst = 0; lst < k; lst++) {
                if (!(i & (1 << lst))) {
                    continue;
                }

                for (int j = 0; j < k; j++) {
                    if (i & (1 << j)) {
                        continue;
                    }

                    ld nw = dp[i][lst] + g[lst][j];
                    if (nw < dp[i | (1 << j)][j]) {
                        dp[i | (1 << j)][j] = nw;
                        pr[i | (1 << j)][j] = mp(i, lst);
                    }
                }
            }
        }

        pair<ld, pair<int,int>> bst(inf, mp(-1, -1));

        {
            for (int j = 0; j < k; j++) {
                //cerr << dp[(1 << k) - 1][j] << endl;
                chmin(bst, mp(dp[(1 << k) - 1][j], mp((1 << k) - 1, j)));
            }
            //cerr << endl;
        }

        assert(bst.fst != -1);

        vector<int> ans;
        int msk = bst.snd.fst;
        int lst = bst.snd.snd;

        while (msk) {
            ans.pb(lst);
            auto r = pr[msk][lst];
            msk = r.fst;
            lst = r.snd;
        }

        reverse(ans.begin(), ans.end());
        vector<int> p(k);
        for (int i = 0; i < k; i++) {
            p[ans[i]] = i;
        }

        cout << "\"";
        for (int i = 0; i < k; i++) {
            if (i) {
                printf(" ");
            }
            printf("%d", p[i] + 1);
        }
        cout << "\",";
        printf("\n");

    }


    return 0;
}
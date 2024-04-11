#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR (i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define eb emplace_back
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);

template<class T> T& smin(T& a, const T& b) { if (a > b) a = b; return a; }
template<class T> T& smax(T& a, const T& b) { if (a < b) a = b; return a; }
template<class T> T sqr(const T& a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
           const char* delimiter = " ", const char* closing = "\n") {
  for (; begin != end; ++begin != end ? printf("%s", delimiter) : 0)
    printf(fmt, *begin);
  printf("%s", closing);
}

const int N = 1001;
int n, ip[N][N];
double p[N][N], d[N];
double x[N], y[N];
bool us[N];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  REP(i, n) REP(j, n) scanf("%d", ip[i]+j), p[i][j] = ip[i][j] / 100.0;
  REP(i, n-1) x[i] = 1, y[i] = 1e100;
  y[n-1] = 0;
  REP(phase, n) {
    int u = -1;
    REP(i, n) if (!us[i]) {
      d[i] = y[i] / (1 - x[i]);
      if (u == -1 || d[i] < d[u]) u = i;
    }
//    printf("%d: %lf\n", u, d[u]);
    if (u == 0) break;
    us[u] = true;
    REP(i, n) if (!us[i] && ip[i][u] > 0) {
      if (y[i] == 1e100) {
        x[i] = 1 - p[i][u];
        y[i] = 1 + p[i][u] * d[u];
      } else {
        double tx = x[i] * (1 - p[i][u]);
        double ty = y[i] + x[i] * p[i][u] * d[u];
        if (ty / (1 - tx) < d[i]) x[i] = tx, y[i] = ty;
      }
    }
  }
  printf("%lf\n", d[0]);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}
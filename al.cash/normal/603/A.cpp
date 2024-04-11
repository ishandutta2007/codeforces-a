#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdarg>
#include <cstdio>
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

const int N = 1e5+5;
int n;
char s[N];
int l[N][2], r[N][2], rf[N][2];

int main() {
  cin.tie(NULL);
  //ios_base::sync_with_stdio(false);
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d%s", &n, s);
  REP(i, n) s[i] -= '0';
  l[0][0] = l[0][1] = 0;
  REP(i, n) {
    if (s[i] == 0) {
      l[i+1][0] = l[i][1] + 1;
      l[i+1][1] = l[i][1];
    } else {
      l[i+1][0] = l[i][0];
      l[i+1][1] = l[i][0] + 1;
    }
  }

  int ans = -1;
  FORD(i, n-1, 0) {
    if (s[i] == 0) {
      r[i][0] = r[i+1][1] + 1;
      r[i][1] = r[i+1][1];
      rf[i][0] = max(rf[i+1][0], r[i+1][0]);
      rf[i][1] = max(rf[i+1][0], r[i+1][0]) + 1;
    } else {
      r[i][0] = r[i+1][0];
      r[i][1] = r[i+1][0] + 1;
      rf[i][0] = max(rf[i+1][1], r[i+1][1]) + 1;
      rf[i][1] = max(rf[i+1][1], r[i+1][1]);
    }
    smax(ans, max(rf[i][0] + l[i][1], rf[i][1] + l[i][0]));
  }
//  REP(i, n) printf("l: %d %d, rf: %d %d\n", l[i][0], l[i][1], rf[i][0], rf[i][1]);
  printf("%d\n", ans);

#ifdef LocalHost
  cout << endl << endl << clock() << endl;
#endif
  return 0;
}
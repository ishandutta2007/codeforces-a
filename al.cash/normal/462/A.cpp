#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <complex>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define FORE(e, v) for (int e = head[v]; e >= 0; e = E[e].next)
#define UN(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define CL(a, v) memset(a, v, sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INF_LL = 1000000000000000000LL;
const double pi = 2 * acos(0.0);

template<class T> void smin(T& a, T b) { if (a > b) a = b; }
template<class T> void smax(T& a, T b) { if (a < b) a = b; }
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template<class T> T sqr(T a) { return a * a; }

template<typename Iterator>
void print(const char* fmt, Iterator begin, Iterator end,
    const char* separator = " ") {
  for (Iterator it = begin; it != end; ++it) {
    if (it != begin) printf(separator);
    printf(fmt, *it);
  }
  printf("\n");
}

const int h = 111;
int n;
char s[h][h];
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};

int main() {
#ifdef LocalHost
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  FOR(i, 1, n+1) scanf("%s", s[i]+1);
  bool ok = true;
  FOR(i, 1, n+1) FOR(j, 1, n+1) {
    int k = 0;
    REP(t, 4) if (s[i+dx[t]][j+dy[t]] == 'o') ++k;
    if (k&1) {
      ok = false;
      break;
    }
  }
  printf("%s\n", ok ? "YES" : "NO");

#ifdef LocalHost
  cout << endl << endl << "TIME: " << clock() << endl;
#endif
  return 0;
}
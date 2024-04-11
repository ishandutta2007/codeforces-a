#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INFLL = 1000000000000000000LL;

int main () {
#ifdef LocalHost
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for(int i=0; 4*i<=n; ++i) if((n-4*i)%7 == 0) {
    REP(j, i) printf("4");
    REP(j, (n-4*i)/7) printf("7");
    printf("\n");
    return 0;
  }
  printf("-1\n");
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}
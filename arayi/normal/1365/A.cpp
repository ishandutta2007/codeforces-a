//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#include <chrono>
#include <random>

#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jigglypuff
#define ld long double
#define itn int
#define pir pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define str string
#define enl endl
#define en endl
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x, ld y1, ld x2, ld y2)
{
    return sqrt((x - x2) * (x - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
    return (a * (a + 1LL)) / 2;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1, 0 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1, 0 };


const int N = 1e5 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-13;

lli bp(lli a, lli b = mod - 2LL)
{
    lli ret = 1;
    while (b)
    {
        if (b & 1) ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
ostream& operator<<(ostream& c, pir a)
{
    c << a.fr << " " << a.sc;
    return c;
}


int t, n, m;
int a[55][55];
bool col[55], col1[55];
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(col, 0, sizeof(col));
        memset(col1, 0, sizeof(col1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j]) col[i] = true, col1[j] = true;
            }
        itn sm, sm1;
        sm = sm1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (!col[i]) sm++;
        }
        for (int j = 0; j < m; j++)
        {
            if (!col1[j]) sm1++;
        }
        sm = min(sm, sm1);
        if (sm % 2) cout << "Ashish\n";
        else cout << "Vivek\n";
    }
    return 0;
}

/*

  __
*(><)*
  \/ /
  ||/
--||
  ||
  /\
 /  \
/    \
*/
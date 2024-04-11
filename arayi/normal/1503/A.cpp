//Arayi
#define _CRT_SECURE_NO_WARNINGS
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
#include <complex>

#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
#define cd complex<long double>
#define vcd vector<cd>
#define vii vector<int>
#define vlli vector<lli>
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
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 1e6 + 30;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 550;

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
template<class T>
void maxi(T& a, T b)
{
    a = max(a, b);
}
template <class T>
void mini(T& a, T b)
{
    a = min(a, b);
}


int t;
int n;
str s;
bool stg(str s)
{
    int sm = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(') sm++;
        else sm--;
        if (sm < 0) return 0;
    }
    return (sm == 0);
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        str a, b;
        a = b = s;
        itn a1, b1;
        a1 = b1 = 0;
        int qn = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (qn % 2 == 0) a[i] = '(', b[i] = ')';
                else a[i] = ')', b[i] = '(';
                qn++;
            }
        }
        if (qn % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }
        qn = (n - qn) / 2;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (qn > 0) a[i] = b[i] = '(';
                else a[i] = b[i] = ')';
                qn--;
            }
        }
        if (stg(a) && stg(b)) cout << "YES\n" << a << endl << b << endl;
        else cout << "NO\n";
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
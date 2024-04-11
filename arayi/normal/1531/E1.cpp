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
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 200;

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



str s;
int i1;
int a[N], b[N];
void s1(int l, int r)
{
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    s1(l, m);
    s1(m, r);
    int i = l, j = m, k = l;
    while (i < m && j < r)
    {
        if (i1 >= s.length()) return;
        if (s[i1] == '0') b[k] = a[i], i++;
        else b[k] = a[j], j++;
        i1++;
        k++;
    }
    while (i < m) b[k] = a[i], k++, i++;
    while (j < r) b[k] = a[j], k++, j++;
    for (int i = l; i < r; i++) a[i] = b[i];
}
int main()
{
    fastio;
    cin >> s;
    for (int n = 1; n < 100000; n++)
    {
        for (int i = 0; i < n; i++) a[i] = i;
        i1 = 0;
        s1(0, n);
        if(i1 == (int)s.length())
        {
            for (int i = 0; i < n; i++) b[a[i]] = i + 1;
            cout << n << endl;
            for (int i = 0; i < n; i++) cout << b[i] << " ";
            return 0;
        }
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
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
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
#define y1 arayikhalatyan
using namespace std;

lli gcd(lli a, lli b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
lli cg(lli n) {
	return n ^ (n >> 1);
}
lli SUM(lli a)
{
	return (a * (a + 1) / 2);
}
bool CAN(int x, int y, int n, int m)
{
	if (x >= 0 && y >= 0 && x < n && y < m)
	{
		return true;
	}
	return false;
}
double her(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
string strsum(string a, string b)
{
	int p = 0;
	string c;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (b.length() < a.length())
	{
		for (int i = b.length(); i < a.length(); i++)
		{
			b += "0";
		}
	}
	else
	{
		for (int i = a.length(); i < b.length(); i++)
		{
			a += "0";
		}
	}

	a += "0", b += "0";
	for (int i = 0; i < a.length(); i++)
	{
		c += (a[i] - '0' + b[i] - '0' + p) % 10 + '0';
		p = (a[i] + b[i] - '0' - '0' + p) / 10;
	}
	if (c[c.length() - 1] == '0') c.erase(c.length() - 1, 1);
	reverse(c.begin(), c.end());
	return c;
}
string strmin(string a, string b)
{
	if (a.length() > b.length()) return b;
	if (b.length() > a.length()) return a;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] > b[i]) return b;
		if (b[i] > a[i]) return a;
	}
	return a;
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 1e6 + 30;
const lli mod = 998244353;
struct el
{
	lli a, b, ind;
};
bool operator<(const el & x, const el & y)
{
	if (x.a == y.a) return x.b < y.b;
	else return x.a < y.a;
}
lli n;
el a[N], b[N];
lli pat, rs;
lli modf(lli n)
{
	lli res = 1;
	for (lli i = 1; i <= n; i++)
	{
		res *= i;
		res %= mod;
	}
	return res;
}
bool stg()
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i].b > a[i + 1].b) return false;
	}
	return true;
}
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].a >> a[i].b;
		a[i].ind = i;
		b[i].b = a[i].a;
		b[i].a = a[i].b;
		b[i].ind = i;
	}
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	sort(a, a + n);
	sort(b, b + n);
	pat = modf(n);
	if (stg())
	{
		rs = 1;
		for (int i = 0; i < n; i++)
		{
			lli sm = 1;
			while (i < n && a[i].a == a[i + 1].a && a[i].b == a[i + 1].b) sm++, i++;
			rs *= modf(sm);
			rs %= mod;
		}
		pat += rs;
		pat %= mod;
	}
	rs = 1;
	for (int i = 0; i < n; i++)
	{
		lli sm = 1;
		while (i < n && a[i].a == a[i + 1].a) sm++, i++;
		rs *= modf(sm);
		rs %= mod;
	}
	pat -= rs;
	pat %= mod;
	rs = 1;
	for (int i = 0; i < n; i++)
	{
		lli sm = 1;
		while (i < n && b[i].a == b[i + 1].a) sm++, i++;
		rs *= modf(sm);
		rs %= mod;
	}
	pat -= rs;
	pat %= mod;
	//cout << pat;
	
	while (pat<0)
	{
		pat += mod;
	}
	cout << (pat % mod) << endl;
	return 0;
}
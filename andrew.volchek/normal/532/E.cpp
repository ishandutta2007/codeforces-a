#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <vector>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define y1 asdkjghjasd
#define fst first
#define snd second
#define y0 sakjglajaa
#define ll long long
#define ull unsigned long long
#define ld long double

const int maxn = 100005;

string a, b;

int was[2];
ll ans = 0;

int n;

void rec(int p1, int p2)
{
	if (p1 == n && p2 == n)
	{
		ans++;
		return;
	}
	
	if (p1 < n && p2 < n)
	{
		if (a[p1] == b[p2])
		{
			rec(p1 + 1, p2 + 1);
		}
		else
		{
			if (!was[0])
			{
				was[0] = 1;
				rec(p1 + 1, p2);
				was[0] = 0;
			}
			
			if (!was[1])
			{
				was[1] = 1;
				rec(p1, p2 + 1);
				was[1] = 0;
			}
		}
	}
	else
	{
		if (p1 < n && !was[0])
			rec(p1 + 1, p2);
		
		if (p2 < n && !was[1])
			rec(p1, p2 + 1);
	}
}


int main()
{
	//freopen("a.in", "r", stdin);
	cin >> n;
	cin >> a;
	cin >> b;

	if (a == b)
	{
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			int j = i;
			while (j < n && a[j] == a[i])
				j++;
				
			if (i == 0)
				ans += 25LL * (j - i + 1) + 1;
			else
				ans += 25LL * (j - i);
				
			i = j - 1;
		}
	}
	else
	{
		rec(0, 0);
	}
	
	cout << ans << endl;
	
	//cin >> t;
	return 0;
}
/* ______ INCLUDES ______ */

#include <bits/stdc++.h>

/* _____ NAMESPACES _____ */

using namespace std;

/* ______ TEMPLATE ______ */

typedef long long ll;
typedef long double ld;

inline void _redirect_streams(const string input = "", const string output = "")
{
	if(not input.empty())
		assert(freopen(input.c_str(), "r", stdin) != nullptr);

	if(not output.empty())
		assert(freopen(output.c_str(), "w", stdout) != nullptr);
}

inline void _speed_up_iostreams()
{
	//IMPORTANT NOTE: don't mix iostreams and stdio when next line is active
	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);
}

inline void _pre()
{
#ifdef ANDREIKKAA
	_redirect_streams("input.txt");
#else
	//_redirect_streams("input.txt", "output.txt");
#endif //ANDREIKKAA

	_speed_up_iostreams();
}

inline void _post()
{
#ifdef ANDREIKKAA
	cerr.precision(10);
	cerr << "Execution time: " << clock() / (ld) CLOCKS_PER_SEC << endl;
#endif
}

/* ________ CODE ________ */

void _solve()
{
	const int MAX_N = 19;

	static int a[MAX_N];
	static int g[MAX_N][MAX_N];
	static ll dp[1 << MAX_N][MAX_N];

	int n, m, o;
	cin >> n >> m >> o;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		dp[1 << i][i] = a[i];
	}

	for(int i = 0; i < o; ++i)
	{
		int x, y, c;
		cin >> x >> y >> c;
		--x;
		--y;

		g[x][y] = c;
	}

	ll ans = 0;

	for(int i = 0; i < (1 << n); ++i)
	{
		if(__builtin_popcount(i) == m)
		{
			ans = max(ans, *max_element(dp[i], dp[i] + n));
		}

		for(int j = 0; j < n; ++j)
		{
			if(((i >> j) & 1) == 0)
			{
				continue;
			}

			for(int k = 0; k < n; ++k)
			{
				if(((i >> k) & 1) == 1)
				{
					continue;
				}

				if(j == k)
				{
					continue;
				}

				dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] + a[k] + g[j][k]);
			}
		}
	}

	cout << ans << endl;
}

int main()
{
	_pre();

	_solve();

	_post();

	return 0;
}
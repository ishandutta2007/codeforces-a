// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// (`v)
// `..Coding


/*       *********
 *       *
 *   *   *   *
 *       *
 *****************
         *       *
     *   *   *   *
         *       *
 *********       */
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ll long long int
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define W(x) int x;cin>>x;while(x--)
#define fr(n) for(int i=n-1;i>=0;i--)
#define mp make_pair
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define vi vector<int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define sortall(x) sort(all(x))
#define mk(arr,n,type)  type *arr=new type[n];
#define vpi vector<pair<int,int> >
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define sz(x) (int)x.size()
#define vs vector<string>
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define F first
#define S second
#define INT_SIZE 32
int mpow(int exp, int base);
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
	aeh();
	W(t)
	{
		int n; cin >> n;
		n = n * 2;
		vi a(n);
		fi(n)
		cin >> a[i];
		int b = 1;
		int p = n;
		int mx = -1;
		vi res;
		int cnt = 0;
		fi(n)
		{
			if (mx < a[i])
			{
				if (cnt)
					res.pb(cnt);
				mx = a[i];
				cnt = 1;

			}
			else
				cnt++;
		}
		if (cnt)
			res.pb(cnt);

		// fi(res.size())
		// cout << res[i] << " ";
		// cout << endl;
		int m = res.size();
		n = n / 2;
		int dp[m + 1][n + 1];
		fi(n + 1)
		dp[0][i] = 0;

		fi(m + 1)
		{
			dp[i][0] = 1;
		}

		fo(i, 1, m + 1)
		{
			fo(j, 1, n 	+ 1)
			{
				if (res[i - 1] > j)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - res[i - 1]];
				}
			}
		}
		if (dp[m][n])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
}


int mpow(int base, int exp)
{
	base %= mod;
	int result = 1;
	while (exp > 0)
	{
		if (exp & 1)result = (result * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}
#include<bits/stdc++.h>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define chlo(i,a,n) for(int i=a;i<n;i++)
#define vi vector<int>
#define vs vector<string>
#define int long long int
#define all(a) (a).begin(),(a).end()
#define sortall(x) sort(all(x))
#define itr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define sz(x) (int)x.size()
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
#define INT_SIZE 32
#define pr pair<int,int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define F first
#define S second
#define pii pair<int,int>

int mpow(int exp, int base);
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("aana.txt", "r", stdin);
	freopen("jj.txt", "w", stdout);
#endif
}
int32_t main()
{
	aeh();
	W(t)
	{

		int n, m;
		cin >> n >> m;
		int a[n][m];
		fi(n)
		{
			fj(m)
			cin >> a[i][j];
		}
		string v = "Vivek";
		string as = "Ashish";
		int fl = 0;
		int r = 0, c = 0;
		fi(n) {
			int fl = 0;
			fj(m)
			{
				if (a[i][j] == 1) {
					fl = 1;
					break;
				}
			}
			if (!fl)
				r++;
		}
		fj(m)
		{
			int fl = 0;
			fi(n)
			{
				if (a[i][j] == 1)
				{
					fl = 1;
					break;
				}
			}
			if (!fl)
				c++;

		}
		int ans = min(r, c);
		if (ans % 2)
		{
			cout << as << endl;
		}
		else
			cout << v << endl;
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
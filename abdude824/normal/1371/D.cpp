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
#define f first
#define s second
#define INT_SIZE 32
int mpow(int exp, int base);
// I don't know what the funciton aeh() does but it speeds up my mess
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
		int n, k;
		cin >> n >> k;
		if (k == 0) {
			cout << "0" << endl;
			fi(n)
			{
				fj(n)
				{
					cout << 0;
				}
				cout << endl;
			}
			continue;
		}
		if (k % n)
			cout << 2 << endl;
		else
			cout << 0 << endl;
		int p = k / n;
		int arr[n][n];
		fi(n)
		fj(n)
		arr[i][j] = 0;
		int c = k % n;
		fi(n)
		{
			int q = i ;
			int p1 = p;
			int g;
			if (c > 0)
				g = 1;
			else
				g = 0;
			for (int j = q; j < p1 + q + g; j++)
			{
				// deb(j);
				// deb(g);
				// deb(p1 + q + g);
				arr[i][j] = 1;
				// c--;
				if (j >= n) {
					p1 -= (j - q - g);
					j = -1;
					q = 0;
					g = 0;
				}
			}
			c--;
		}
		p = k % n;
		// for (int i = 0; i < n && p > 0; i++)
		// {
		// 	for (int j = 0; j < n; j++)
		// 	{
		// 		if (arr[i][j] == 0)
		// 		{
		// 			arr[i][j] = 1;
		// 			// deb(p);
		// 			p--;
		// 			break;
		// 		}
		// 	}
		// }
		fi(n) {
			fj(n)
			cout << arr[i][j];
			cout << endl;
		}

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
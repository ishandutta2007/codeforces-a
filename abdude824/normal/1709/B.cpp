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
// 
// 
// 
// 
// 
// 
// 
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
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}
int32_t main()
{
	aeh();
	int n,m;cin>>n>>m;
	vi a(n);
	fi(n)cin>>a[i];
	vi prefa(n-1);
	vi prefd(n-1);
	for(int i=1;i<n;i++)
	{
		if(i!=1)
			prefa[i-1]=prefa[i-2]+max(a[i-1]-a[i],0ll);
		else
			prefa[i-1]=max(a[i-1]-a[i],0ll);
	}

	for(int i=n-2;i>=0;i--)
	{
		if(i!=n-2)
			prefd[i]=prefd[i+1]+max(a[i+1]-a[i],0ll);
		else
			prefd[i]=max(a[i+1]-a[i],0ll);
	}
	// fi(n-1)cout<<prefa[i]<<" ";
	// cout<<"\n\n";
	// fi(n-1)cout<<prefd[i]<<" ";
	// cout<<"\n\n";
	fi(m)
	{
		int c,d;cin>>c>>d;
		if(c==1)
			cout<<prefa[d-2]<<endl;
		else if(c==n)
			cout<<prefd[d-1]<<endl;
		else if(c<=d)
			cout<<prefa[d-2]-prefa[c-2]<<endl;
		else{
			cout<<prefd[d-1]-prefd[c-1]<<endl;
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
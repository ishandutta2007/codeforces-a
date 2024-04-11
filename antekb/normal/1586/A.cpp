#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=2e5+5, mod=1e9+7, INF=1e9+5;

int main(){
	//BOOST;
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vi V(n);
		int s=0;
		for(int &i:V)cin>>i, s+=i;
		bool b=0;
		for(int i=2; i*i<=s; i++)if(s%i==0)b=1;
		if(b){
			cout<<n<<"\n";
			for(int i=1; i<=n; i++)cout<<i<<" ";
			cout<<"\n";
		}
		else{
			cout<<n-1<<"\n";
			b=1;
			for(int i=1; i<=n; i++){
				if(V[i-1]&b)b=0; else cout<<i<<" ";
			}
			cout<<"\n";
		}
		
	}
}
#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, k[N];

struct q{
	int l, r;
	bool operator < (const q& x){
        return (k[r] - k[l]) > (k[x.r] - k[x.l]);
    } 
};

void solve() {
	cin >> n;
	vector <q> s;
	for(int i = 1; i <= n; i++) cin >> k[i];
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(k[i] < k[j]) s.pb({i, j});
			else s.pb({j, i});
		}
	}
	sort(all(s));
	string ans;
	for(auto it : s){
		cout << "? " << it.r << " " << it.l << endl;
		cin >> ans;
		if(ans == "Yes") {
			cout << "! " << it.r << " " << it.l << endl;
			return;
		}
	}
	cout << "! " << 0 << " " << 0 << endl;
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}
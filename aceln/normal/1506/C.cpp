#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn=1e6+7;
const int inf=2e9;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while (t--) {
		string a,b; cin>>a>>b;
		int n=sz(a),m=sz(b);
		int ans=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++) {
				for (int k=0;;k++) {
					if (i+k>=n||j+k>=m) break;
					if (a[i+k]!=b[j+k]) break;
					ans=max(ans,k+1);
				}
			}
		cout<<n+m-ans*2<<'\n';
	}
}
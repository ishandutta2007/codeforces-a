#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 200 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , m , A[MAXN][MAXN] , cnt[MAXN];
vector<int> v[MAXN];
vector<pii> vec;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m; vec = {};
		fill(cnt , cnt + n , 0);
		for(int i = 0 ; i < n ; i++){
			v[i] = {};
			for(int j = 0 ; j < m ; j++){
				cin >> A[i][j];
				v[i].push_back(A[i][j]);
				vec.push_back({A[i][j] , i});
			}
			sort(all(v[i]));
		}
		sort(all(vec));
		for(int i = 0 ; i < m ; i++){
			cnt[vec[i].Y]++;
		}
		int tot = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cout << v[i][(j + m - tot) % m] << sep;
			}
			cout << endl;
			tot += cnt[i];
		}
	}

    return 0;
}
/*

*/
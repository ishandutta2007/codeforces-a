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
#define lc							id << 1
#define rc							lc | 1

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , A[MAXN] , B[MAXN] , dp[MAXN] , par[MAXN];
pii seg[MAXN << 2];

void modify(int pos , int val , int id = 1 , int l = 0 , int r = n + 1){
	if(r - l == 1){
		seg[id] = {val , pos};
		return;
	}
	int mid = l + r >> 1;
	if(pos < mid)	modify(pos , val , lc , l , mid);
	else	modify(pos , val , rc , mid , r);
	seg[id] = min(seg[lc] , seg[rc]);
}

pii get(int ql , int qr , int id = 1 , int l = 0 , int r = n + 1){
	if(qr <= l || r <= ql)	return {MOD , MOD};
	if(ql <= l && r <= qr)	return seg[id];
	int mid = l + r >> 1;
	return min(get(ql , qr , lc , l , mid) , get(ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> B[i];
		A[i] = A[i + B[i]] - B[i];
	}
	for(int i = 1 ; i <= n ; i++){
		pii res = get(i - A[i] , i);
		dp[i] = res.X + 1;
		par[i] = res.Y;
		modify(i , dp[i]);
	}
	if(dp[n] >= MOD){
		return cout << -1 << endl , 0;
	}
	vector<int> ans;
	int cur = n;
	while(cur){
		cur = par[cur];
		ans.push_back(cur);
	}
	cout << dp[n] << endl;
	for(int i : ans){
		cout << i << sep;
	}

    return 0;
}
/*

*/
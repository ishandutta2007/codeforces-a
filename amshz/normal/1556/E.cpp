//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

ll a[xn], b[xn], ps[xn], n, q;
pll seg[xn << 2];

void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = {ps[l], ps[l]};
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id].A = min(seg[lc].A, seg[rc].A);
	seg[id].B = max(seg[lc].B, seg[rc].B);
}
pll get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return {INF, - INF};
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	pll x = get(lc, l, mid, ql, qr);
	pll y = get(rc, mid, r, ql, qr);
	x.A = min(x.A, y.A);
	x.B = max(x.B, y.B);
	return x;
}

int main(){
	fast_io;

	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i)
		cin >> b[i];
	for (int i = 1; i <= n; ++ i)
		ps[i] = ps[i - 1] + a[i] - b[i];
	build(1, 1, n + 1);
	while (q --){
		int l, r;
		cin >> l >> r;
		pll x = get(1, 1, n + 1, l, r + 1);
		if (0 < x.B - ps[l - 1] || ps[r] - ps[l - 1])
			cout << - 1 << endl;
		else
			cout << - (x.A - ps[l - 1]) << endl;
	}

	return 0;
}
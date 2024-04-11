# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
typedef pair <pii, pii> ppp;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, qq, Seg[xm][xn * 4], Lazy[xm][xn * 4], num[xn], l, r, t, x, ans;

void Build(int id, int L, int R, ll bit){
	if (R - L == 1){
		Seg[bit][id] = bool((num[L]&(1LL << bit)) > 0);
		return;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid, bit);
	Build(id * 2 + 1, Mid, R, bit);
	Seg[bit][id] = Seg[bit][id * 2] + Seg[bit][id * 2 + 1];
}
void Shift(int id, int L, int R, ll bit){
	if (Lazy[bit][id] == 0) return;
	Seg[bit][id] = R - L - Seg[bit][id];
	if (R - L > 1){
		Lazy[bit][id * 2] ^= Lazy[bit][id];
		Lazy[bit][id * 2 + 1] ^= Lazy[bit][id];
	}
	Lazy[bit][id] = 0;
}
void Update(int id, int L, int R, int Ql, int Qr, ll bit){
	Shift(id, L, R, bit);
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		Lazy[bit][id] ^= 1;
		Shift(id, L, R, bit);
		return;
	}
	int Mid = (L + R) / 2;
	Update(id * 2, L, Mid, Ql, Qr, bit);
	Update(id * 2 + 1, Mid, R, Ql, Qr, bit);
	Seg[bit][id] = Seg[bit][id * 2] + Seg[bit][id * 2 + 1];
}
ll Get(int id, int L, int R, int Ql, int Qr, ll bit){
	Shift(id, L, R, bit);
	if (Qr <= L || R <= Ql) return 0;
	if (Ql <= L && R <= Qr) return Seg[bit][id];
	int Mid = (L + R) / 2;
	return Get(id * 2, L, Mid, Ql, Qr, bit) + Get(id * 2 + 1, Mid, R, Ql, Qr, bit);
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> num[i];
	cin >> qq;
	for (ll bit = 0; bit < 20; bit ++) Build(1, 0, xn, bit);
	while (qq --){
		cin >> t >> l >> r;
		l --;
		if (t == 1){
			ans = 0;
			for (ll bit = 0; bit < 20; bit ++) ans += Get(1, 0, xn, l, r, bit) * (1LL << bit);
			cout << ans << endl;
		}
		else{
			cin >> x;
			for (ll bit = 0; bit < 20; bit ++) if ((x&(1LL << bit))) Update(1, 0, xn, l, r, bit);
		}
	}
	return 0;
}
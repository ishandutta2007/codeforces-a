# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;

# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const ll md = 1e9+7;

string bin(ll n){
	string ans = "";
	while (n > 0){
		if (n%2 == 0) ans = '0'+ans;
		else ans = '1'+ans;
		n /= 2;
	}
	return ans;
}
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

const int xn = 2e5+10;
const int xm = 1e2+10;


int main(){
	fast_io;
	//cout << pow(3, 14);
	int qq;
	cin >> qq;
	while (qq--){
		ll x, y;
		cin >> x >> y;
		ll s = x, k = 0;
		bool fl1 = false;
		if (y == 1 or x >= y) fl1 = true;
		while (s > 1 && s < y && s != 3){
			if (s%2 == 0) s /= 2, s *= 3;
			else s--;
			if (s >= y) fl1 = true;
		}
		if (fl1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
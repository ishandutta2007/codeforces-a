#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s, t, A;
	cin >> A;
	ll fl = 0;
	for(auto x : A){
		if(x == '.'){
			fl = 1;
			continue;
		}
		if(!fl) s += x;
		else t += x; 
	}
	str al = "5";
	for(int i = 1; i < t.size(); i++) al += '0';

	if(s[s.size() - 1] == '9')return cout << "GOTO Vasilisa.\n", 0;
	s[s.size() - 1] += (t >= al);
	cout << s << '\n';
	return 0;
}
#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
bool is_full_sq(string s){
	ll x = atoi(s.c_str());
	if(x == 1) return 1;
	ll k = 2;
	while(k*k<x) k++;
	return k*k == x;
}
main(){
    FAST;
    string s;
    cin >> s;
    queue<string> q;
    q.push(s);
    while(!q.empty()){
    	string sn = q.front();
    	q.pop();
    	if(is_full_sq(sn)){
    		cout << s.length() - sn.length() << endl;
    		exit(0);
    	}else{
    		for(ll i =1;i<((ll)sn.length()-1);i++){
    			q.push(sn.substr(0, i) + sn.substr(i+1));
    		}
    		if(sn.length() > 0) q.push(sn.substr(0, sn.length()-1));
    		if(sn.length() > 1 && sn[1] != '0') q.push(sn.substr(1));
    	}
    }
    cout << -1;
}
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
#define N 1000000
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
ll cntb[N], cnta[N];
main(){
    FAST;
    string s;
    cin >> s;
    ll al = s.length();
    for(ll i =0;i<al;i++){
        cnta[i] = (i>0? cnta[i-1] : 0) + (s[i]=='1' ? 1 : 0);
    }
    cin >> s;
    ll bl = s.length(), br = 0;
    for(ll i = 0;i<bl;i++){
        br += s[i]-'0';
    }
    ll res = 0;
    for(ll i = bl-1;i<al;i++)
        res += ((br%2 == (cnta[i] - (i - bl >= 0 ? cnta[i-bl] : 0))%2) ? 1 : 0);
    cout << res;
}
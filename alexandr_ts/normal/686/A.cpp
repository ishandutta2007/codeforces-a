#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e3;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

string s[N];

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    ll n, x, str = 0;
    cin >> n >> x;
    fr(i, n) {
        char t;
        cin >> t;
        if (t == '+') {
            ll x1;
            cin >> x1;
            x += x1;
        }
        else {
            ll x1;
            cin >> x1;
            if (x1 <= x) {
                x -= x1;
            }
            else
                str++;
        }
    }
    cout << x << " " << str;

}
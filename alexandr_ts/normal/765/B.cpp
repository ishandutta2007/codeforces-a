#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e14 + 10;
const ld EPS = 1e-10;

int main() {
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    char cur = 'a';
    fr(i, s.size())
        if (s[i] == cur)
            cur++;
        else if (s[i] > cur) {
            cout << "NO";
            return 0;
        }
    cout << "YES";

}
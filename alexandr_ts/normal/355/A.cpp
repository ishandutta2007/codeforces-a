#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e3 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

int a[N], b[N];

int main() {
    int k, d;
    cin >> k >> d;
    if (k == 1 && d == 0) {
        cout << 0;
        return 0;
    }
    if (d == 0)
        cout << "No solution";
    else {
        cout << d;
        fr(i, k - 1)
            cout << "0";
    }

}
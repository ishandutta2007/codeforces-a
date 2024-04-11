#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;



bool prime(int x) {
    frab(i, 2, (int)sqrt(x) + 1)
        if (i < x)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    frab(i, 1, 1001)
        if (!prime(n * i+ 1)) {
            cout << i;
            return 0;
        }
}
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, aa, bb;
    cin >> n;
    aa = (n - 5) / 7 * 2;
    if ((n - 5) % 7 > 2) aa += 2;
    else aa += (n - 5) % 7;
    bb = n / 7 * 2;
    if (n % 7 > 2) bb += 2;
    else bb += n % 7;
    cout << max(aa, 0) << ' ' << bb << endl;
}
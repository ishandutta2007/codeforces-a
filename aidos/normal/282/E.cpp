#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (2e5)
using namespace std;
int n;
ll a[MAXN];
struct node{
    public :
    int l, r;
    node(){
        l = -1;
        r = -1;
    }
};
node next[MAXN * 20];
int sz = 1;
void add(ll cur){
    int pos = 0;
    for( int i = 42;  i >= 0; i--) {
        if( cur & (1ll << i )){
            if( next[pos].r == -1){
                next[pos].r = sz;
                next[sz] = node();
                sz++;
            }
            pos = next[pos].r;
        }
        else {
            if( next[pos].l == -1){
                next[pos].l = sz;
                next[sz] = node();
                sz++;
            }
            pos = next[pos].l;
        }
    }
}
ll get(ll cur){
    int pos = 0;
    ll ans = 0;
    for(int i = 42; i >= 0; i--){
        if( ((cur & (1ll << i ) ) == 0 &&  next[pos].r != -1) || next[pos].l == -1){
            ans += (1ll << i);
            pos=next[pos].r;
        }
        else {
            pos = next[pos].l;
        }
    }
    return ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n;
    ll all = 0, cur = 0, maxi = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        all ^= a[i];
        maxi = max(all ,maxi);
    }
    next[0] = node();
    for(int i = n-1; i >= 0; i--){
        all ^= a[i];
        cur ^= a[i];
        add(cur);
        maxi = max( maxi, get( all ) ^ all);
        maxi = max(cur, maxi);
    }
    cout << maxi << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
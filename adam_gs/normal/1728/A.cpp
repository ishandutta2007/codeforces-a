#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  int n;
  cin >> n;
  pair<int,int>T[n];
  rep(i, n) {
    cin >> T[i].st;
    T[i].nd=i;
  }
  sort(T, T+n);
  reverse(T, T+n);
  cout << T[0].nd+1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}
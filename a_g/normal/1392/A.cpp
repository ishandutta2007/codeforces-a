#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    set<int> vals;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      vals.insert(val);
    }
    cout << (vals.size() == 1 ? n : 1) << endl;
  }
}
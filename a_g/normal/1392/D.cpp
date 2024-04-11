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
    string s;
    cin >> s;
    vector<int> blocks;
    char curr = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != curr) {
        blocks.push_back(1);
        curr = s[i];
      }
      else {
        blocks.back()++;
      }
    }
    if (blocks.size() > 1 && blocks.size() & 1) {
      blocks[0] += blocks.back();
      blocks.pop_back();
    }
    int ans = 0;
    for (int b: blocks) ans += b/3;
    if (blocks.size() == 1) ans = (blocks[0]-1)/3+1;
    cout << ans << endl;
  }
}
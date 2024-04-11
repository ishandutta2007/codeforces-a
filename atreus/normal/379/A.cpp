/*
######################################################################
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#
#@@@      @@@@@@   @@@@@@       @@@@@     @@@@@@     @@@@    @@@@  @@#
#@@   @@@@@@@@@  @  @@@@@  @@@@  @@@  @@@  @@@@  @@@  @@@  @  @@@  @@#
#@@@      @@@@  @@@  @@@@       @@@  @@@@@  @@  @@@@@  @@  @@  @@  @@#
#@@@@@@@   @@         @@@  @@@@  @@@  @@@  @@@@  @@@  @@@  @@@  @  @@#
#@@@      @@  @@@@@@@  @@        @@@@     @@@@@@     @@@@  @@@@    @@#
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#
######################################################################
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        ans++;
    while (n >= m){
        int cnt = n;
        ans += n / m;
        n /= m;
        n += cnt % m;
    }
    cout << ans << endl;
}
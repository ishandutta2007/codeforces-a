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

int main ()
{
    ios_base::sync_with_stdio(false);
    long long l, r, x, y;
    long long k;
    cin >> l >> r >> x >> y >> k;
    for (int i = x; i <= y; i++)
        if (k * i <= r && k * i >= l)
            return cout << "YES", 0;
    cout << "NO" << endl;
}
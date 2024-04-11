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

int gcd(int n, int m){
    if (n < m){
        int l = n;
        n = m;
        m = l;
    }
    if (n % m == 0)
        return m;
    if (n == 1)
        return 1;
    return gcd(n % m, m);
}

bool whoiswinner(int a, int b, int n){
    if (gcd(a, n) > n)
        return 1;
    else if (gcd(a, n) == n)
        return 0;
    else{
        if (whoiswinner(b, a, n - gcd(a, n)) == 1)
            return 0;
        else
            return 1;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int a, b, n;
    cin >> a >> b >> n;
    cout << whoiswinner(a, b, n);
}
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    int ans=2*(n/3) + (n%3 > 0);
    cout<<ans;
}
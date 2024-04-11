#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 5e5+20;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n;
        vector<ll> a(n);
        copy_n(istream_iterator<ll>(cin), n, a.begin());
        sort(a.begin(), a.end());
        bool has0=0, has1=0;
        for(auto i : a){
            if(i == 0) has0 = 1;
            if(i == 1) has1 = 1;
        }
        if(has0 && has1){
            cout<<"no\n";
            continue;
        }
        if(!has1){
            cout<<"yes\n";
            continue;
        }
        bool ok = 1;
        for(ll i = 1;i<n;i++) if(a[i] -a[i-1] == 1) ok = 0;
        if(ok) cout<<"yes\n";
        else cout<<"no\n";
    }
}
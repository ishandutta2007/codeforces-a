/*
 _  _    _  _  ____  _  _  ____    _  _  ____  ____    ____  ____   __  ____   __   ____  _  _ 
( \/ )  ( \/ )(  __)/ )( \/ _  )  / )( \(  __)(_  _)  /    \(  _ \ /  \(  __) /  \ (  __)( \/ )
 )  /   / \/ \ ) _) ) __ (\    \  ) __ ( ) _)   )(    ) /\ ( ) __/(  O )) _ \/ /\ \ ) _) / \/ \
(__/    \_)(_/(____)\_)(_/(_/__/  \_)(_/(____) (__)   \_)(_/(__)   \__/(____/\_)(_/(____)\_)(_/
 __ _  ____   __   _  _  ____    _  _   __  ____  _ u_    ____   __   _ _   __ _  _ __         
(  / )(  _ \ /  \ ( \/ )(  __)  ( \/ ) /  \(  __)/ )  )  (  __) / _\ ( ) ))(  / )/ )  )        
 )  (  ) __/(  O )/ \/ \ ) _)   / \/ \(  O )) _) \    \   ) _ \/    \/( ( \ )  ( \    \        
(__\_)(__)   \__/ \_)(_/(____)  \_)(_/ \__/(____)(__(_/  (____/\_/\_/\____/(__\_)(__(_/        
  __   __    __    __       ____                                                               
 /  \ /  \  /  \  /  \  ___(__  )                                                              
(_/ /(  0 )(  0 )(  0 )(___) / /                                                               
 (__) \__/  \__/  \__/      (_/                                                                
 ____    _  _  _  _  ____  ____    ____  ____   __    ___  ____  _ __                          
/ _  )  ( \/ )( \/ )(  __)(  _ \  /    \(  _ \ /  \  / __)(_  _)/ )  )                         
\    \   )  / / \/ \ ) _)  ) __/  ) /\ ( ) __/(  O )( (__   )(  \    \ _  _  _                 
(_/__/  (__/  \_)(_/(____)(__)    \_)(_/(__)   \__/  \___) (__) (__(_/(_)(_)(_)                

(c) 255.
*/
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
const ll N = 5e5+18;
//..
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        string s, t;
        cin >> n >> s >> t;
        stack<ll, vector<ll>> vs[26];
        yree avb;
        for(ll i = 0;i<n;i++) avb.insert(i);
        for(ll i = n-1;i>=0;i--) vs[s[i]-'a'].push(i);
        ll res = inf;
        ll off=0;
        for(ll i = 0;i<n;i++){
            ll mv = n+5, mz =-1;
            for(ll j = 0;j<t[i]-'a';j++){
                if(vs[j].size() && vs[j].top() < mv) mv=vs[j].top(), mz = j;
            }
            if(mz>=0){
                res=min<ll>(res, off+avb.order_of_key(mv));
            }
            ll j = t[i]-'a';
            if(vs[j].empty()) break;
            ll x = vs[j].top(); vs[j].pop();
            off+=avb.order_of_key(x);
            avb.erase(avb.find(x));
        }
        if(res^inf) cout<<res<<'\n';
        else cout<<"-1\n";
    }
}
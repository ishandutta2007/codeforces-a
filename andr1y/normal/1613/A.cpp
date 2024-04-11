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
const ld inf = 0x3fff3fff3fff3fff;
const ll N = 5e5+18;

signed main(){
  cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
  ll q;
  cin >> q;
  while(q--){
    ll x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    auto find_s = [](ll a){
      ll b = a, c=0;
      while(b){
        b/=10;
        c++;
      }
      return c;
    };
    ll v1 = find_s(x1);
    ll v2 = find_s(x2);
    if(v1+p1<v2+p2) cout<<"<\n";
    else if(v1+p1 > v2+p2) cout<<">\n";
    else{
      string s1 = to_string(x1), s2=to_string(x2);
      char res='=';
      for(ll i = 0;i<10&&i<v1+p1;i++){
        ll a1, a2;
        if(i>=(ll)s1.length()) a1 = 0;
        else a1=s1[i]-'0';
        if(i>=(ll)s2.length()) a2 = 0;
        else a2=s2[i]-'0';
        if(a1>a2){
          res='>';
          break;
        }else if(a1<a2){
          res='<';
          break;
        }
      }
      cout<<res<<'\n';
    }
  }
}
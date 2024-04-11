//#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N  =  1e+6+3;
const ll   M  =  1e+5+3;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

set <ll> s[N],ch[N];
int n,k,day,ct,a[M];
vll v;

int main(){
    fastio;
    cin>>n;
    for(int i = 0;i < n;i++)cin>>a[i];
    day = 0;
    ct = 0;
    for(int i = 0;i < n;i++){
        if(a[i] < 0){
            auto it = s[day].lower_bound(-a[i]);
            if((*it) != (-a[i])){
                cout<<-1;
                return 0;
            }
            else{
                s[day].erase(-a[i]);
                ch[day].insert(a[i]);
                ct--;
                k++;
            }
        }
        else{
            auto it = ch[day].lower_bound(-a[i]);
            if((*it) == (-a[i])){
                cout<<-1;
                return 0;
            }
            else{
                s[day].insert(a[i]);
                ct++;
                k++;
            }
        }
        if(ct == 0){
            day++;
            ct = 0;
            v.push_back(k);
            k = 0;
        }
    }
    if(ct == 0){
        cout<<v.size()<<endl;
        for(auto it : v)cout<<it<<" ";
        cout<<endl;
    }
    else cout<<-1;
}
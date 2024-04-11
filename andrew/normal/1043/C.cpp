#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string a;
    cin >> a;
    ll n = a.size();
    vector <ll> ans(n);
    ll uk = 0;
    for(int i = n - 1; i >= 0; i--)if(a[i] == 'a'){
        uk = i;
        break;
    }
    if(uk){
        ans[uk] = 1;
        for(int i = uk - 1; i >= 0; i--)if(a[i] != a[i + 1])ans[i] = 1;
    }
    for(auto i : ans)cout << i << " ";
    cout << "\n";
    return 0;
}
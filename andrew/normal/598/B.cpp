#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

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
    string s;
    cin >> s;
    s = "$" + s;
    string del, s1, s2;
    ll n;
    cin >> n;
    while(n--){
        ll l, r, k;
        cin >> l >> r >> k;
        k %= r - l + 1;
        if(k == 0)continue;
        del = s.substr(l, r - l + 1);
        s.erase(l, r - l + 1);
        reverse(all(del));
        s2 = del.substr(0, k);
        del.erase(0, k);
        reverse(all(del));
        reverse(all(s2));
        del = s2 + del;
        s.insert(l, del);
    }
    s.erase(s.begin());
    cout << s << "\n";
    return 0;
}
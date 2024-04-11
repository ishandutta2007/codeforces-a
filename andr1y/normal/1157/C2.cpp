#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pp(a, b) pb(mp(a, b))
#define get_bit(n, k) n&(1<<k)
#define endl '\n'
#define vl vector<ll>
#define PI 3.1415926535897932384626433832795
#define rad(deg) deg*PI/180
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF LLONG_MAX
#define NINF -INF-1
#define PAIR_OUT_PRE "("
#define PAIR_OUT_BTW ";"
#define PAIR_OUT_PST "), "
#define ARRAY_OUT_PRE "data: "
#define ARRAY_OUT_BTW ", "
#define ARRAY_OUT_PST endl
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << PAIR_OUT_PRE << V.x << PAIR_OUT_BTW << V.y << PAIR_OUT_PST;}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << ARRAY_OUT_PRE; for(auto i:V)os << i << ARRAY_OUT_BTW; return os << ARRAY_OUT_PST;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << ARRAY_OUT_PRE; for(auto i:V)os << i << ARRAY_OUT_BTW; return os << ARRAY_OUT_PST;}
/*--func--*/
template<typename T> ull fast_log(T a){ull c = 0;while((a>>(++c)) > 0);return c-1;}
ll n, a[N];
main(){
    FAST;
    cin >> n;
    for(ll i=0;i<n;i++) cin >> a[i];
    ll l = 0, r = n-1, last = 0;
    string posl = "";
    while(l<=r){
        if(a[l] < a[r]){
            if(last < a[l]){
                last = a[l];
                l++;
                posl+='L';
            }else if(last < a[r]){
                last = a[r];
                r--;
                posl+='R';
            }else{
                break;
            }
        }else if(a[l] == a[r]){
            if(last >= a[l]) break;
            if(l == r){
                last = a[r];
                r--;
                posl+='R';
            }else{
                if(l+1 <= r-1){
                    /*if(a[l] == a[l+1] && a[r] == a[r+1]){
                        last = a[l];
                        l++;
                        posl+='L';
                    }*/
                    if(a[l+1] <= a[l]){
                        if(a[r-1] <= a[r]){
                            last = a[l];
                            l++;
                            posl+='L';
                        }else{
                            last = a[r];
                            r--;
                            posl+='R';
                        }
                    }else{
                        if(a[r-1] <= a[r]){
                            last = a[l];
                            l++;
                            posl+='L';
                        }else{
                            ll cl = 0, cr = 0;
                            for(ll i = l+1;i<=r-1;i++) if(a[i]>a[i-1]) cl++; else break;
                            for(ll i = r-1;i>=l+1;i--) if(a[i]>a[i+1]) cr++; else break;
                            if(cl > cr){
                                last = a[l];
                                l++;
                                posl+='L';
                            }else{
                                last = a[r];
                                r--;
                                posl+='R';
                            }
                        }
                    }

                }else{
                    last = a[l];
                    l++;
                    posl+='L';
                }
            }
        }else{
            if(last < a[r]){
                last = a[r];
                r--;
                posl+='R';
            }else if(last < a[l]){
                last = a[l];
                l++;
                posl+='L';
            }else{
                break;
            }
        }
    }
    cout << posl.length() << endl << posl;
}
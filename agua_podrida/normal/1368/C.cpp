#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    ll a,b,x;
    cin>>a>>b>>x;
    int res = 0;
    while(a <= x and b <= x){
        if(a < b) a += b;
        else b += a;
        res++;
    }
    cout<<res<<'\n';
}

void b(){
    ll k;
    cin>>k;
    vi res(10,1);
    ll ap = 1;
    int i = 0;
    while(ap < k){
        ap /= res[i];
        res[i]++;
        ap *= res[i];
        i++;
        if(i == 10) i = 0;
    }

    string s = "codeforces";
    string t;
    F0(i,10) while(res[i]--) t.pb(s[i]);
    cout<<t<<'\n';
}

void c(){
    int n;
    cin>>n;
    vvb res(3*n,vb(5,false));

    int i = 1;
    while(i < 3*n){
        res[i][2] = true;
        res[i][3] = true;
        res[i][1] = true;
        res[i-1][2] = true;
        res[i+1][2] = true;
        i += 3;
    }

    res[0][1] = true;
    i = 4;
    while(i+3 < 3*n){
        res[i][0] = true;
        res[i+1][0] = true;
        res[i+2][0] = true;
        res[i+3][0] = true;
        i += 6;
    }
    i = 1;
    while(i+3 < 3*n){
        res[i][4] = true;
        res[i+1][4] = true;
        res[i+2][4] = true;
        res[i+3][4] = true;
        i += 6;
    }

    if(n%2 == 0) res[3*n-1][1] = true;
    else res[3*n-1][3] = true;

    int k = 0;
    F0(i,3*n) F0(j,5) if(res[i][j]) k++;
    cout<<k<<'\n';
    F0(i,3*n) F0(j,5) if(res[i][j]) cout<<i<<' '<<j<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}
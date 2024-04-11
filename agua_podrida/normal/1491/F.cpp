#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
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
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it : s)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 1e9+7;

void f(){
    int n;
    cin>>n;
    int res = 0;
    int i = 1;
    while(res == 0){
        i++;
        cout<<"? "<<1<<' '<<i-1<<'\n';
        cout<<i<<'\n';
        F1(j,i-1) cout<<j<<' ';
        cout<<'\n';
        cin>>res;
    }
    vb descargados(n+1,true);
    descargados[i] = false;
    vi cand(i-1);
    F0(j,i-1) cand[j] = j+1;
    while(cand.size() != 1){
        int mid = cand.size()/2;
        cout<<"? "<<1<<' '<<mid<<'\n';
        cout<<i<<'\n';
        F0(j,mid) cout<<cand[j]<<' ';
        cout<<'\n';
        cin>>res;
        if(res) while(cand.size() > mid) cand.pop_back();
        else {
            reverse(todo(cand));
            if(cand.size() % 2) mid++;
            while(cand.size() > mid) cand.pop_back();
        }
    }
    descargados[cand[0]] = false;

    REP(j,i+1,n){
        cout<<"? 1 1\n";
        cout<<i<<'\n'<<j<<'\n';
        cin>>res;
        if(res) descargados[j] = false;
    }

    int k = 0;
    F1(i,n) if(descargados[i]) k++;
    cout<<"! "<<k<<' ';
    F1(i,n) if(descargados[i]) cout<<i<<' ';
    cout<<'\n';

}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int t;
    cin>>t;
    while(t--) f();
}
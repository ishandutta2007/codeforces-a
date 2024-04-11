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
#define INF 1e12
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    F0(i,n){
        if(i % 2) a[i] = abs(a[i]);
        else a[i] = -abs(a[i]);
    }
    F0(i,n) cout<<a[i]<<' ';
    cout<<'\n';
}

void b(){
    int n,m;
    cin>>n>>m;
    vvi a(n,vi(m));
    F0(i,n) F0(j,m) cin>>a[i][j];

    if(a[0][0] > 2 or a[n-1][0] > 2 or a[0][m-1] > 2 or a[n-1][m-1] > 2){
        cout<<"NO\n";
        return;
    }
    F0(i,n){
        if(a[i][0] > 3 or a[i][m-1] > 3){
            cout<<"NO\n";
            return;
        }
    }
    F0(j,m){
        if(a[0][j] > 3 or a[n-1][j] > 3){
            cout<<"NO\n";
            return;
        }
    }

    F0(i,n) F0(j,m){
            if(a[i][j] > 4){
                cout<<"NO\n";
                return;
            }
        }

    cout<<"YES\n";

    F0(i,n){
        F0(j,m){
            if((i == 0 or i == n-1) and (j == 0 or j == m-1)) cout<<2;
            else if(i == n-1 or i == 0 or j == 0 or j == m-1) cout<<3;
            else cout<<4;
            cout<<' ';
        }
        cout<<'\n';
    }
}

int n;

bool ordenado(vi a){
    F1(i,n-1) if(a[i] > a[i+1]) return false;
    return true;
}

bool vale(vi a, vi aQuien, vi res){
    int sobra = n;
    while(aQuien[sobra] != 0){
        int i = aQuien[sobra];
        res.pb(i);
        swap(a[i],sobra);
    }
    if(ordenado(a) and res.size() <= 2*n){
        cout<<res.size()<<'\n';
        F0(i,res.size()) cout<<res[i]<<' ';
        cout<<'\n';
        return true;
    }
    return false;
}

bool anduvo(vi a, vi cant, set<int> libres){
    vi res;
    vi p(n);
    F0(i,n) p[i] = i+1;
    random_shuffle(todo(p));
    int j = 0;
    while(j < n){
        int i = p[j];
        auto it = libres.begin();
        if(*it == n) break;
        res.pb(i);
        cant[a[i]]--;
        if(cant[a[i]] == 0) libres.insert(a[i]);
        a[i] = *it;
        libres.erase(a[i]);
        cant[a[i]]++;
        j++;
    }

    vi aQuienLeSirve(n+1);
    F1(i,n) aQuienLeSirve[i] = i;
    F1(i,n){
        if(vale(a,aQuienLeSirve,res)) return true;
        aQuienLeSirve[i-1] = i;
        aQuienLeSirve[i] = 0;
    }
    return false;
}

bool mandar0alprincipio(vi a, vi cant, set<int> libres){

    vi res;
    vi p(n);
    F0(i,n) p[i] = i+1;
    random_shuffle(todo(p));

    int i = p[0];
    auto it = libres.begin();
    res.pb(i);
    cant[a[i]]--;
    if(cant[a[i]] == 0) libres.insert(a[i]);
    a[i] = *it;
    libres.erase(a[i]);
    cant[a[i]]++;

    i = p[1];
    it = libres.begin();
    res.pb(i);
    cant[a[i]]--;
    if(cant[a[i]] == 0) libres.insert(a[i]);
    a[i] = *it;
    libres.erase(a[i]);
    cant[a[i]]++;

    int j = 0;
    while(j < n){
        int i = p[j];
        auto it = libres.begin();
        if(*it == n) break;
        res.pb(i);
        cant[a[i]]--;
        if(cant[a[i]] == 0) libres.insert(a[i]);
        a[i] = *it;
        libres.erase(a[i]);
        cant[a[i]]++;
        j++;
    }

    vi aQuienLeSirve(n+1);
    F1(i,n) aQuienLeSirve[i] = i;
    F1(i,n){
        if(vale(a,aQuienLeSirve,res)) return true;
        aQuienLeSirve[i-1] = i;
        aQuienLeSirve[i] = 0;
    }
    return false;
}

void d(){
    cin>>n;
    vi a(n+1);
    F1(i,n) cin>>a[i];

    set<int> libres;
    vi cant(n+1);
    F1(i,n) cant[a[i]]++;
    F0(i,n+1) if(cant[i] == 0) libres.insert(i);

    while(!anduvo(a,cant,libres) and !mandar0alprincipio(a,cant,libres));
}

void c(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    if(a[0] < a[n-1]) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) d();
    return 0;
}
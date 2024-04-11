#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vbool;
int mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}

template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 10000000

#define todo(v) v.begin(),v.end()

ll expN(ll b, ll exp){
    if(exp == 0) return 1;
    ll res = expN(b,exp/2);
    res *= res;
    if(exp%2 == 1) res *= b;
    return res;
}

void a(){
    int n;
    ll I;
    cin>>n>>I;
    vi audio(n);
    F0(i,n) cin>>audio[i];
    sort(todo(audio));

    ll lim = 8* I / n;
    lim = expN(2,lim);

    int l = 0; int r = 0;
    int distintos = 1;
    int res = n;
    while(r < n and distintos <= lim){
        r++;
        if(audio[r] != audio[r-1]) distintos++;
    }
    mini(res,n-r+l);
    while(r < n){
        l++;
        while(l < n and audio[l] == audio[l-1]) l++;
        r++;
        while(r < n and audio[r] == audio[r-1]) r++;
        mini(res,n-r+l);
    }
    cout<<res<<'\n';
}

struct segmentMax {
    segmentMax(int nn){
        n = nn;
        tree = vi(2*n);
    }

    segmentMax(vi& v){
        n = v.size();
        tree = vi(2*n);
        F0(i,n){
            tree[i+n] = v[i];
        }
        for(int i = n-1; i >= 1; i--){
            tree[i] = max(tree[2*i],tree[2*i+1]);
        }
    }

    int maxr(int a, int b){
        int res = -1;
        a += n; b += n;
        while(a <= b){
            if(a%2 == 1) maxi(res,tree[a++]);
            if(b%2 == 0) maxi(res,tree[b--]);
            a /= 2;
            b /= 2;
        }
        return res;
    }

    void actualizar(int i, int x){
        i += n;
        tree[i] = x;
        i /= 2;
        while(i >= 1){
            tree[i] = max(tree[2*i],tree[2*i+1]);
            i /= 2;
        }
    }

    int n;
    vi tree;
};

void b(){
    int aux;
    int p,x;
    int n;
    cin>>n;
    vi A(n+1);
    F1(i,n) cin>>A[i];

    int q;
    cin>>q;
    segmentMax tree(q);
    vi ultimaAcutalizacion(n+1,0);
    int t = 0;
    while(q--){
        cin>>aux;
        if(aux == 1){
            cin>>p>>x;
            A[p] = x;
            ultimaAcutalizacion[p] = t;
        }
        if(aux == 2){
            cin>>x;
            tree.actualizar(t,x);
        }
        t++;
    }
    F1(i,n){
        maxi(A[i],tree.maxr(ultimaAcutalizacion[i],t-1));
    }
    F1(i,n) cout<<A[i]<<' ';
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("../subtle_sabotage.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    b();
    return 0;
}
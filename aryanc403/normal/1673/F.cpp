/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
*/
/*
  Credits -
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/ (namespace atcoder)
  Github source code of library - https://github.com/atcoder/ac-library/tree/master/atcoder
  https://codeforces.com/contest/4/submission/150120627
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #define dbg(args...) 42;
    // #define endl "\n"
#endif

// y_combinator from @neal template https://codeforces.com/contest/1553/submission/123849801
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;
template <class T>
using ordered_set =  __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.

const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

const lli INF = 0xFFFFFFFFFFFFFFFLL;
const lli SEED=chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

const lli MX = 48000;

lli getWeightSum(const vector<vi> &wei,const lli n){
    lli sum=0;
    for(lli i=0;i<n;i++){
        for(lli j=0;j<n-1;j++)
            sum+=(wei[i][j]^wei[i][j+1]);
    }

    for(lli i=0;i<n-1;i++){
        for(lli j=0;j<n;j++)
            sum+=(wei[i][j]^wei[i+1][j]);
    }
    dbg(n,sum);
    return sum;
}

vector<vi> getWeights(const lli n){
    if(n==1)
        return {{0}};
    const lli m=n/2;
    const auto a=getWeights(m);
    vector<vi> b(n,vi(n));
    const lli B = n*n/4;
    for(lli i=0;i<n;i++)
        for(lli j=0;j<n;j++){
            const lli r=2*(i/m)+(j/m);
            lli x=i,y=j;
            if(r&2)
                x=n-x-1;
            if(r&1)
                y=n-y-1;
            b[i][j]=a[x][y];
            b[i][j]^=r*B;
        }
    dbg(n)
    for(auto &v:b){
        dbg(v);
    }
    return b;
}

vector<vi> runBF(){
    const lli n=32;
    auto a=getWeights(n);
    getWeightSum(a,n);
    return a;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    const auto a=runBF();
    lli n,k;
    cin>>n>>k;
    for(lli i=0;i<n;i++){
        for(lli j=0;j<n-1;j++)
            cout<<(a[i][j]^a[i][j+1])<<" ";
        cout<<endl;
    }

    for(lli i=0;i<n-1;i++){
        for(lli j=0;j<n;j++)
            cout<<(a[i][j]^a[i+1][j])<<" ";
        cout<<endl;
    }

    map<lli,lli> iden;
    for(lli i=0;i<n*n;i++)
        iden[a[i/n][i%n]^a[0][0]]=i;
    dbg(sz(iden));
    lli cur=0,x;
    while(k--){
        cin>>x;
        cur^=x;
        assert(iden.count(cur));
        x=iden[cur];
        cout<<x/n+1<<" "<<(x%n)+1<<endl;
    }

}   aryanc403();
    return 0;
}
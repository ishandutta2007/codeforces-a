#include <bits/stdc++.h>
using namespace std;
 
 
namespace Rec{
    template<class Fun>
    class y_combinator_result {
        Fun fun_;
    public:
        template<class T>
        explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
        template<class ...Args>
        decltype(auto) operator()(Args &&...args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };
 
    template<class Fun>
    decltype(auto) y_combinator(Fun &&fun) {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }
}
 
 
//fast IO by yosupo
struct Scanner {
    FILE* fp = nullptr;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) reread();
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();            
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(vector<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* _fp) : fp(_fp) {}
};
 
struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }
 
    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }
 
  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val;  // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const vector<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
 
 
using ll=long long;
//#define int ll
 
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
 
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
 
using pii=pair<int,int>;
using vi=vc<int>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 
#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif
 
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
 
template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}
 
template<int i,class T>
void print_tuple(ostream&,const T&){
}
 
template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}
 
template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}
 
template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}
 
ll read(){
	ll i;
	cin>>i;
	return i;
}
 
vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}
 
template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}
 
string readString(){
	string s;
	cin>>s;
	return s;
}
 
template<class T>
T sq(const T& t){
	return t*t;
}
 
//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
}
 
constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}
 
const ll infLL=LLONG_MAX/3;
 
#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif
 
int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}
 
template<class t>
bool inc(t a,t b,t c){
	return a<=b&&b<=c;
}
 
template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}
 
ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}
 
template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}
 
struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	/*modular inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modular(x);
	}*/
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};
extern constexpr modinfo base{1000000007,0};
using mint=modular<base>;

struct AA{
    int s, m, M;
};

const int SZ = (1<<19), INF = 1e9;
struct ITIT{
    int Mx[SZ+SZ];
    void Put(int a, int b){
        a+=SZ;
        Mx[a]=b;
        while(a!=1){
            a>>=1;
            Mx[a]=max(Mx[a*2],Mx[a*2+1]);
        }
    }
    int Max(int b, int e){
        int r = -INF;
        b+=SZ,e+=SZ;
        while(b<=e){
            r=max(r,max(Mx[b],Mx[e]));
            b=(b+1)>>1,e=(e-1)>>1;
        }
        return r;
    }
}ITM, ITm;

vc<AA> Go(vi w){
    int n = si(w);
    vi L(n), R(n), st(n+1);
    rep(i,n)L[i]=-1,R[i]=-1;
    int top = 0;
    rep(i,n){
        while(top && w[st[top]] <= w[i]){
            R[st[top]]=i;
            top--;
        }
        st[++top]=i;
    }
    top = 0;
    per(i,n){
        while(top && w[st[top]] <= w[i]){
            L[st[top]]=i;
            top--;
        }
        st[++top]=i;
    }
    rep(i,n){
        ITM.Put(i, w[i]);
        ITm.Put(i, -w[i]);
    }
    set<pii>Set;
    rep(i,n){
        if(L[i]!=-1 && i-L[i]>=2){
            Set.insert({L[i],i});
        }
        if(R[i]!=-1 && R[i]-i>=2){
            Set.insert({i,R[i]});
        }
    }
    vc<AA>ret;
    for(auto &t : Set){
        int l = t.fi, r = t.se;
        int M = min(w[l],w[r]);
        int s = -ITm.Max(l,r);
        int m = ITM.Max(l+1,r-1);
        ret.pb({s,m,M});
    }
    return ret;
};

vc<vc<pii>>Z(SZ);

struct D2Seg{

    vc<pii>w;
    vi X;

    vc<vi>BIT;
    vc<vi>Y;
    vi L;
    int n;
    void Add(int nd, int a, int b){
        a++;
        while(a <= L[nd]){
            BIT[nd][a]+=b;
            a+=(a&-a);
        }
    }
    int Sum(int nd, int a){
        a++;
        int r = 0;
        while(a){
            r+=BIT[nd][a];
            a-=(a&-a);
        }
        return r;
    }
    void Build(int nd, int b, int e){
        if(b!=e){
            int m = (b+e)>>1;
            Build(nd*2,b,m);
            Build(nd*2+1,m+1,e);
        }
        int l = e-b+1;
        L[nd] = l;
        vc<pii> TP(l);
        rng(i,b,e){
            TP[i-b] = {w[i].se, i};
        }
        sort(all(TP));
        rep(i,l){
            Z[TP[i].se].pb({nd,i});
        }
        Y[nd].resize(l);
        BIT[nd].resize(l+1);
        rep(i,l)Y[nd][i] = TP[i].fi;
    }
    void init(vc<AA> VB){
        n = si(VB);
        w.resize(n);
        X.resize(n);
        rep(i,n){
            w[i] = {VB[i].s, VB[i].M};
            X[i] = w[i].fi;
        }
        BIT.resize(SZ+SZ);
        Y.resize(SZ+SZ);
        L.resize(SZ+SZ);
        Build(1,0,n-1);
    }

    void Put(int a){
        for(auto [nd,x] : Z[a]){
            Add(nd, x, 1);
        }
    }

    ll Get2(int nd, int y){
        int pv = lower_bound(all(Y[nd]),y) - Y[nd].begin();
        return Sum(nd, L[nd]-1) - Sum(nd, pv-1);
    }

    ll Get(int nd, int b, int e, int s, int l, int y){
        if(s>l)return 0;
        if(s<=b && e<=l)return Get2(nd, y);
        int m = (b+e)>>1;
        ll r=0;
        if(s<=m)r += Get(nd*2,b,m,s,l,y);
        if(l>m)r += Get(nd*2+1,m+1,e,s,l,y);
        return r;
    }

    ll Calc(int bx, int ex, int by){
        int b = lower_bound(all(X),bx)-X.begin();
        int e = lower_bound(all(X),ex+1)-X.begin(); e--;
        if(b<=e){
            return Get(1,0,n-1,b,e,by);
        }
        return 0;
    };
}T;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	Scanner sc(stdin);
	Printer pr(stdout);

    int n, m, X;
    sc.read(n,m,X);
    vi A(n+2);
    vi B(m+2);
    rng(i,1,n){
        sc.read(A[i]);
    }
    rng(i,1,m){
        sc.read(B[i]);
    }
    A[0]=A[n+1]=B[0]=B[m+1]=X+1;
    rep(i,n+2)A[i]-=X;
    auto VA = Go(A);
    auto VB = Go(B);

    
    sort(all(VB), [](AA a, AA b){
        return a.s < b.s;
    });

    T.init(VB);

    int na = si(VA), nb = si(VB);

    vi idx(nb);
    rep(i,nb)idx[i]=i;

    sort(all(idx), [&](int a, int b){
        return VB[a].m < VB[b].m;
    });

    sort(all(VA), [](AA a, AA b){
        return -a.s < -b.s;
    });

    //for(auto &[s,m,M]: VA)printf("%d %d %d\n",s,m,M);
    //for(auto &[s,m,M]: VB)printf("%d %d %d\n",s,m,M);

    int pv = 0;
    ll res = 0;
    for(auto &[s,m,M] : VA){
        while(pv < nb){
            int t = idx[pv];
            if(VB[t].m <= -s){
                T.Put(t);
                pv++;
            }
            else break;
        }
        res += T.Calc(-M+1, -m, -s+1);
    }
    printf("%lld\n",res);

}
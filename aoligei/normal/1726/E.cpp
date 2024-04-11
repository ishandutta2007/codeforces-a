//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0) {
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
#define mod 998244353
#define MOD mod
#define P mod
#define inv2 499122177
#define EXP 1
//
inline long long pw(long long x,long long p) {
	long long res=1;
	for(; p; p>>=1,x=x*x%mod)
		if(p&1)res=res*x%mod;
	return res;
}
//
inline long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
namespace getinv {
	int *inv,*fac,*ifac;//
	///ln/exp/main
	void init_inv(int n) {
		inv=new int[n+1];
		inv[0]=1;
		inv[1]=1;
		for(register int i=2; i<=n; ++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	//main
	void init_inv_with_fac(int n) {
		inv=new int[n+1];
		fac=new int[n+1];
		ifac=new int[n+1];
		inv[0]=fac[0]=ifac[0]=1;
		inv[1]=1;
		for(register int i=2; i<=n; ++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		for(register int i=1; i<=n; ++i) fac[i]=1ll*fac[i-1]*i%mod;
		for(register int i=1; i<=n; ++i) ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
	}
}
using namespace getinv;
namespace Poly {
	int *w[30];//
//main
	void NTT_set(int MAXN) {
		for(int i=2,t=0; i<2*MAXN; i<<=1,t++) {
			w[t]=new int[i>>1];
			ll wn=pw(3,(MOD-1)/i);
			w[t][0]=1;
			for(int j=1; j<(i>>1); j++) w[t][j]=w[t][j-1]*wn%MOD;
		}
	}
	struct poly {
		vector<int>a;//f=a[0]+a[1]*x+a[2]*x^2+...+a[n]*x^n
		//nsizena.size()=n+1
		/*----------------------------------------*/
		poly() {
		}
		poly(int sz) {
			a.resize(sz+1);
		}
#if __cplusplus >= 201103L
		poly(initializer_list<int>x) {
			a=x;
		}
#endif
		poly(vector<int>vec) {
			a=vec;
		}
		template<class T>
		poly(T s,T t) {
			//
			a=vector<int>(s,t);
		}
		poly(const poly &x) {
			a=x.a;
		}
		/*----------------------------------------*/
		inline int size() {
			return a.size()-1;
		}
		inline void resize(int x) {
			a.resize(x+1);
		}
		inline int& operator[](int pos) {
			return a[pos];
		}
		inline poly subpoly(int l,int r) {
			//
			return poly(&a[l],&a[r]);
		}
		/*----------------------------------------*/
		//NTT
		inline void NTT() {
			int N=a.size(),len=1;//N=+1
			while(len<N)len<<=1;
			if(N<len) {
				resize(len-1);
			}
			unsigned ll A[len];
			F(i,0,len-1)A[i]=a[i];
			register int j=len>>1;
			for(register int i=1; i<len-1; i++) {
				if (i<j) swap(A[i],A[j]);
				int k=len>>1;
				while (j>=k) {
					j-=k;
					k>>=1;
				}
				j+=k;
			}
			for(register int i=2,t=0; i<=len; i<<=1,t++) {
				if(t==17)for(register int j=0; j<len; ++j)A[j]%=MOD;
				for(register int j=0; j<len; j+=i)
					for(register int k=j; k<j+(i>>1); k++) {
						unsigned ll u=A[k];
						unsigned ll v=w[t][k-j]*A[k+(i>>1)]%MOD;
						A[k]=u+v;
						A[k+(i>>1)]=u-v+mod;
					}
			}
			F(i,0,len-1)a[i]=A[i]%mod;
		}
		//NTT
		inline void UNTT() {
			int N=a.size(),len=1;//N=+1
			while(len<N)len<<=1;
			if(N<len) {
				resize(len-1);
			}
			unsigned ll A[len];
			F(i,0,len-1)A[i]=a[i];
			register int j=len>>1;
			for(register int i=1; i<len-1; i++) {
				if (i<j) swap(A[i],A[j]);
				int k=len>>1;
				while (j>=k) {
					j-=k;
					k>>=1;
				}
				j+=k;
			}
			for(register int i=2,t=0; i<=len; i<<=1,t++) {
				if(t==17)for(register int j=0; j<len; ++j)A[j]%=MOD;
				for(register int j=0; j<len; j+=i)
					for(register int k=j; k<j+(i>>1); k++) {
						unsigned ll u=A[k];
						unsigned ll v=w[t][k-j]*A[k+(i>>1)]%MOD;
						A[k]=u+v;
						A[k+(i>>1)]=u-v+mod;
					}
			}
			reverse(A+1,A+len);
			ll nev=pw(len,MOD-2);
			for(int i=0; i<len; i++) a[i]=(A[i]%MOD)*nev%MOD;
		}
		//DIF-NTT
		inline void DIF_NTT() {
			int N=a.size(),len=1,T=-1;//N=+1
			while(len<N)len<<=1,++T;
			if(N<len) {
				resize(len-1);
			}
			for(register int i=(len>>1),t=T; i; i>>=1,--t)
				for(register int j=0; j<len; j+=(i<<1))
					for(register int k=j; k<j+i; ++k) {
						int u=a[k],v=a[k+i];
						a[k]=(u+v)%mod;
						a[k+i]=1ll*(u-v)*w[t][k-j]%mod;
					}
		}
		//DIF-NTT
		inline void DIF_UNTT() {
			int N=a.size(),len=1;//N=+1
			while(len<N)len<<=1;
			if(N<len) {
				resize(len-1);
			}
			for(register int i=1,t=0; i<len; i<<=1,t++)
				for(register int j=0; j<len; j+=(i<<1))
					for(register int k=j; k<j+i; k++) {
						int u=a[k];
						ll v=1ll*w[t][k-j]*a[k+i];
						a[k]=(u+v)%mod;
						a[k+i]=(u-v)%mod;
					}
			reverse(a.begin()+1,a.begin()+len);
			ll nev=pw(len,MOD-2);
			for(int i=0; i<len; i++) a[i]=(a[i]+MOD)*nev%MOD;
		}
		/*----------------------------------------*/
		//
		inline poly operator+(poly b) {
			register int n=size(),bn=b.size();
			if(n>=bn) {
				poly rt(a);
				for(register int i=0; i<=bn; ++i)rt.a[i]=(a[i]+b.a[i])%mod;
				return rt;
			}
			poly rt(b);
			for(register int i=0; i<=n; ++i)rt.a[i]=(a[i]+b.a[i])%mod;
			return rt;
		}
		//
		inline poly operator-(poly b) {
			register int n=size(),bn=b.size();
			if(n>=bn) {
				poly rt(a);
				for(register int i=0; i<=bn; ++i)rt.a[i]=(a[i]-b.a[i]+mod)%mod;
				return rt;
			}
			poly rt(bn);
			for(register int i=0; i<=n; ++i)rt.a[i]=(a[i]-b.a[i]+mod)%mod;
			for(register int i=n+1; i<=bn; ++i)rt.a[i]=(mod-b.a[i])%mod;
			return rt;
		}
		//
		inline poly operator-() {
			register int n=size();
			poly rt(n);
			for(register int i=0; i<=n; ++i)rt.a[i]=(mod-a[i])%mod;
			return rt;
		}
		//
		inline poly operator*(poly b) {
			int n=size(),bn=b.size();
			int len=n+bn;
			if(1ll*n*bn<=10000) {
				poly rt(len);
				for(register int i=0; i<=n; ++i) {
					for(register int j=0; j<=bn; ++j) {
						rt.a[i+j]=(rt.a[i+j]+1ll*a[i]*b.a[j])%mod;
					}
				}
				return rt;
			}
			poly A(a),B(b.a);
			A.resize(len);
			B.resize(len);
			A.DIF_NTT();
			B.DIF_NTT();
			poly rt(A.size());
			for(register int i=0; i<=A.size(); ++i)rt.a[i]=1ll*A.a[i]*B.a[i]%mod;
			rt.DIF_UNTT();
			rt.resize(len);
			return rt;
		}
		//
		inline poly operator&(poly b) {
			int n=size(),bn=b.size();
			int len=n+bn;
			if(1ll*n*bn<=10000) {
				poly rt(n);
				for(register int i=0; i<=n; ++i) {
					for(register int j=0; j<=min(bn,n-i); ++j) {
						rt.a[i+j]=(rt.a[i+j]+1ll*a[i]*b.a[j])%mod;
					}
				}
				return rt;
			}
			poly A(a),B(b.a);
			A.resize(len);
			B.resize(len);
			A.NTT();
			B.NTT();
			poly rt(A.size());
			for(register int i=0; i<=A.size(); ++i)rt.a[i]=1ll*A.a[i]*B.a[i]%mod;
			rt.UNTT();
			rt.resize(n);
			return rt;
		}
		//res[i-j]+=f[i]*g[j]
		inline poly operator^(poly b) {
			poly temp=b.rev();
			temp=(*this)*temp;
			temp.a.erase(temp.a.begin(),temp.a.begin()+b.size());
			return temp;
		}
		//
		inline poly inv() {
			if(size()==0) {
				return poly(vector<int>(1,getm(1,a[0])));
			}
			poly sub(size()>>1),temp;
			int ss=sub.size();
			for(register int i=0; i<=ss; ++i)sub.a[i]=a[i];
			sub=sub.inv();
			temp=(*this)&(sub*sub);
			F(i,0,ss)sub[i]=(sub[i]<<1)%mod;
			return sub-temp;
		}
		//1
		inline poly sqrt() {
			if(size()==0) {
				return poly(vector<int>(1,1));
			}
			poly sub(size()>>1);
			int ss=sub.size();
			for(register int i=0; i<=ss; ++i)sub.a[i]=a[i];
			sub=sub.sqrt();
			sub.resize(size());
			sub=((*this)&sub.inv())+sub;
			ss=size();
			for(register int i=0; i<=ss; ++i)sub.a[i]=1ll*sub.a[i]*inv2%mod;
			return sub;
		}
		//
		inline poly rev() {
			poly rt(a);
			reverse(rt.a.begin(),rt.a.end());
			return rt;
		}
		//
		inline poly operator/(poly b) {
			if(b.size()>size())return poly();
			poly temp=b.rev();
			temp.resize(size());
			poly rt=rev()&temp.inv();
			rt.resize(size()-b.size());
			return rt.rev();
		}
		//
		inline poly operator%(poly b) {
			if(b.size()>size())return *this;
			poly rt=(*this)-(*this)/b*b;
			rt.resize(b.size()-1);
			return rt;
		}
		//
		inline poly dev() {
			int n=size();
			poly rt(n-1);
			for(register int i=1; i<=n; ++i)rt.a[i-1]=1ll*i*a[i]%mod;
			return rt;
		}
		//
		inline poly inter() {
			int n=size();
			poly rt(n+1);
			for(register int i=0; i<=n; ++i)rt.a[i+1]=1ll*a[i]*getinv::inv[i+1]%P;
			return rt;
		}
		//
		inline poly inter2() {
			int n=size();
			poly rt(n);
			for(register int i=0; i<n; ++i)rt.a[i+1]=1ll*a[i]*getinv::inv[i+1]%P;
			return rt;
		}
		//1
		inline poly ln() {
			return (inv()&dev()).inter2();
		}
		//FFT
		inline void exp_solve(int l,int r,vector<int> &op,int rr) {
			if(l==r)return;
			int mid=(l+r)>>1;
			exp_solve(l,mid,op,rr);
			if(mid>=rr)return;
			poly sub(a.begin(),a.begin()+r-l+1),temp(op.begin()+l,op.begin()+mid+1);
			sub=sub&temp;
			for(int i=mid-l+1,iend=min(r,rr)-l; i<=iend; ++i)op[i+l]=(op[i+l]+1ll*getinv::inv[i+l]*sub[i])%mod;
			exp_solve(mid+1,r,op,rr);
		}
		//0O(nlog^2n),
#if EXP==1
		inline poly exp() {
#else
		inline poly exp2() {
#endif
			unsigned int k=1;
			int temp=a.size();
			while(k<a.size())k<<=1;
			a.resize(k);
			for(int i=1; i<temp; ++i)a[i]=1ll*a[i]*i%mod;
			vector<int>res(a.size(),0);
			res[0]=1;
			exp_solve(0,size(),res,temp-1);
			for(int i=1; i<temp; ++i)a[i]=1ll*a[i]*getinv::inv[i]%mod;
			a.resize(temp);
			res.resize(temp);
			return poly(res);
		}
		//0O(nlogn),
#if EXP!=1
		inline poly exp() {
#else
		inline poly exp2() {
#endif
			if(size()==0) {
				return poly(vector<int>(1,1));
			}
			poly sub(size()>>1),temp;
			int ss=sub.size();
			for(register int i=0; i<=ss; ++i)sub.a[i]=a[i];
			sub=sub.exp();
			temp=sub;
			temp.resize(size());
			temp=*this-temp.ln();
			temp.a[0]=(temp.a[0]+1)%mod;
			return temp&sub;
		}
		//
		inline poly OtoE() {
			int n=size();
			poly rt(n);
			for(register int i=0; i<=n; ++i)rt.a[i]=1ll*a[i]*ifac[i]%mod;
			return rt;
		}
		//
		inline poly EtoO() {
			int n=size();
			poly rt(n);
			for(register int i=0; i<=n; ++i)rt.a[i]=1ll*a[i]*fac[i]%mod;
			return rt;
		}
		/*----------------------------------------*/
		//x
		inline poly power(ll x) {
			vector<int>temp=a;
			int t1=0,t2=0,n=size();
			for(register int i=0; i<=n; ++i) {
				if(a[i]) {
					t1=i,t2=a[i];
					for(register int j=i; j<=n; ++j)a[j]=getm(a[j],t2);
					a.erase(a.begin(),a.begin()+i);
					break;
				}
			}
			if((x>=mod&&t1)||!t2) {
				a=temp;
				return poly(n);
			}
			ll xx=x%(mod-1);
			x%=mod;
			if(t1*x>n) {
				a=temp;
				return poly(n);
			}
			t2=pw(t2,xx);
			*this=ln();
			for(register int i=0; i<=n; ++i)a[i]=a[i]*x%mod;
			*this=exp();
			for(register int i=0; i<=n; ++i)a[i]=1ll*a[i]*t2%mod;
			a.insert(a.begin(),t1*x,0);
			swap(a,temp);
			return temp;
		}
		//xmodxxmod-1
		inline poly power(ll x,ll xx,bool exc=false) {
			vector<int>temp=a;
			int t1=0,t2=0,n=size();
			for(register int i=0; i<=n; ++i) {
				if(a[i]) {
					t1=i,t2=a[i];
					for(register int j=i; j<=n; ++j)a[j]=getm(a[j],t2);
					a.erase(a.begin(),a.begin()+i);
					break;
				}
			}
			if((exc&&t1)||t1*x>n||!t2) {
				a=temp;
				return poly(n);
			}
			t2=pw(t2,xx);
			*this=ln();
			for(register int i=0; i<=n; ++i)a[i]=a[i]*x%mod;
			*this=exp();
			for(register int i=0; i<=n; ++i)a[i]=1ll*a[i]*t2%mod;
			a.insert(a.begin(),t1*x,0);
			swap(a,temp);
			return temp;
		}
		//
		inline void multieva_getpoly(int *bg,int *ed,int p,poly *op) {
			if(bg+1==ed) {
				op[p]=poly(1);
				op[p][1]=1;
				op[p][0]=mod-*bg;
				return;
			}
			multieva_getpoly(bg,bg+((ed-bg)>>1),p<<1,op);
			multieva_getpoly(bg+((ed-bg)>>1),ed,p<<1|1,op);
			op[p]=op[p<<1]*op[p<<1|1];
		}
		//
		inline void multieva_solve(int *bg,int *ed,poly *mul,int p,int *op) {
			if(bg+1==ed) {
				*op=a[0];
				return;
			}
			poly t1=(*this)%mul[p<<1],t2=(*this)%mul[p<<1|1];
			t1.multieva_solve(bg,bg+((ed-bg)>>1),mul,p<<1,op);
			t2.multieva_solve(bg+((ed-bg)>>1),ed,mul,p<<1|1,op+((ed-bg)>>1));
		}
		//
		inline void EI_multieva_getpoly(int *bg,int *ed,int p,poly *op) {
			if(bg+1==ed) {
				op[p]=poly(1);
				op[p][0]=1;
				op[p][1]=mod-*bg;
				return;
			}
			EI_multieva_getpoly(bg,bg+((ed-bg)>>1),p<<1,op);
			EI_multieva_getpoly(bg+((ed-bg)>>1),ed,p<<1|1,op);
			op[p]=op[p<<1]*op[p<<1|1];
		}
		//
		inline void EI_multieva_solve(int *bg,int *ed,poly *mul,int p,int *op) {
			mul[p].a.resize(ed-bg);
			if(bg+1==ed) {
				*op=mul[p].a[0];
				return;
			}
			swap(mul[p<<1],mul[p<<1|1]);
			mul[p<<1]=mul[p]^mul[p<<1],mul[p<<1|1]=mul[p]^mul[p<<1|1];
			EI_multieva_solve(bg,bg+((ed-bg)>>1),mul,p<<1,op);
			EI_multieva_solve(bg+((ed-bg)>>1),ed,mul,p<<1|1,op+((ed-bg)>>1));
		}
		//
		inline void multieva(int *bg,int *ed,int *op) {
			vector<poly>temp((ed-bg+1)<<2);
			multieva_getpoly(bg,ed,1,&temp[0]);
			multieva_solve(bg,ed,&temp[0],1,op);
		}
		//
		inline void EI_multieva(int *bg,int *ed,int *op) {
			vector<poly>temp((ed-bg+1)<<2);
			int N=a.size();
			if(N<ed-bg)a.resize(ed-bg);
			EI_multieva_getpoly(bg,ed,1,&temp[0]);
			if(temp[1].size()<size())temp[1].resize(size());
			temp[1]=(*this)^temp[1].inv();
			EI_multieva_solve(bg,ed,&temp[0],1,op);
			if(a.size()>N)a.resize(N);
		}
		// 1,c,c^2,...,c^m 
		inline vector<int> chirp_z(int c,int m) {
			int iv=pw(c,mod-2),n=size();
			poly A(n+m),B(n);
			long long x=1,y=1,z=1,w=1;
			for(int i=0; i<=n; ++i) {
				A.a[i]=z,B.a[i]=a[i]*w%mod;
				z=z*x%mod,w=w*y%mod;
				x=x*c%mod,y=y*iv%mod;
			}
			for(int i=n+1; i<=n+m; ++i) {
				A.a[i]=z;
				z=z*x%mod;
				x=x*c%mod;
			}
			A=A^B;
			y=w=1;
			for(int i=0; i<=m; ++i) {
				A.a[i]=A.a[i]*w%mod;
				w=w*y%mod;
				y=y*iv%mod;
			}
			return A.a;
		}
	} ;
	//
	template<class T>
	inline poly multi(T bg,T ed) {
		//
		if(bg+1==ed)return *bg;
		return multi(bg,bg+((ed-bg)>>1))*multi(bg+((ed-bg)>>1),ed);
	}

}
using namespace Poly;
int n;
ll f[300002],g[300002];
inline ll C(int x,int y){
	return fac[x]*1ll*ifac[y]%mod*ifac[x-y]%mod;
}
int main() {
	init_inv_with_fac(500000);
	n=3e5;
	f[0]=1;
	F(i,2,n){
		f[i]=(f[i-2]*(i-1)*2)%mod;
	}
	g[0]=g[1]=1;
	F(i,2,n){
		g[i]=(g[i-1]+g[i-2]*(i-1))%mod;
	}
	F(sadf,1,read()){
		read(n);
		ll tot=0;
		F(i,0,n>>2){
			tot+=C(n-(i<<1),i<<1)%mod*g[n-(i<<2)]%mod*f[i<<1]%mod;
		}
		write(tot%mod,'\n');
	}
	return 0;
}
/*
1 2
0 1
1 2
10 11
18 2 6 17 7 19 17 6 2 12 14
4 15 5 20 2 6 20 12 16 5 114514
*/
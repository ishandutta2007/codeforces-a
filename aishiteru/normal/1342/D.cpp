#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
typedef long double ldb;
typedef unsigned long long ull;
#define pb push_back
#define mkp make_pair
#define pl pair<ll,int> 
#define pi pair<int,int>
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;}
	template <class I> 
	il I A(I x){return x<0?-x:x;}
	template <class I> 
	il void sp(I&p,I&q){I x=p;p=q,q=x;}
	template <class I>
	il void ckMax(I&p,I q){p=(p>q?p:q);}
	template <class I>
	il void ckMin(I&p,I q){p=(p<q?p:q);}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
using io :: ckMax;
using io :: ckMin;
const int N=1000005;
int T,n,a[N],b[N],c[N],ans,k;
char s[N];
int main(){ 
	scanf("%d%d",&n,&k);it i;
	for(i=1;i<=n;++i) scanf("%d",&a[i]),++c[1],--c[a[i]+1];
	std::sort(a+1,a+1+n);
	for(i=1;i<=k;++i) c[i]+=c[i-1];
	for(i=1;i<=k;++i) scanf("%d",&b[i]),ans=Max(ans,(c[i]-1)/b[i]+1);
	printf("%d\n",ans);
	for(i=1;i<=ans;++i){
		it now=i,x=0;
		while(now<=n) ++x,now+=ans;
		printf("%d ",x),now=i;
		while(now<=n) printf("%d ",a[now]),now+=ans;
		puts("");
	}
	return 0;
}
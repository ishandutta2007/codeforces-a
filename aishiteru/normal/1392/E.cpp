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
const int N=10005;
int n,m;
int main(){ 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;it i,j,s;long long x;
	for(i=0;i<n;cout<<endl,++i)
		for(j=0;j<n;++j)
			cout<<((ll) (i&1)<<(i+j))<<' ';
	cout<<flush;
	cin>>m;ct lim=n-1<<1;
	while(m--){
		cin>>x;i=j=1,cout<<i<<' '<<j<<endl;
		for(s=1;s<=lim;++s)
			((i&1)==(x>>s&1))?++i:++j,cout<<i<<' '<<j<<endl;
		cout<<flush;
	}
	return 0;
}
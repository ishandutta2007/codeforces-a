#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
int n;
ll a[300006],now,p,ans;
int main() {
	read(n);
	for(int i=1;i<=n;++i)
		read(a[i]);
	for(int i=1;i<=n;++i)
		ans+=p=min(now,a[i]>>1),now-=p,a[i]-=p<<1,ans+=a[i]/3,a[i]%=3,now+=a[i];
	printf("%lld\n",ans);
}
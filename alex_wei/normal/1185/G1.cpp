/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

//#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

// IO templates.

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)

inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

/*
	Templates end.
	Please give me more points.
*/

const int N=15+2;
const int T=225+2;
const int P=1e9+7;

int n,t,ans,ti[N],gi[N],buc[4],fc[N],g[N][N][N][4],s[N][N][N];

void add(int &x,int y){x+=y%P; if(x>=P)x-=P;}

int main(){
	n=read(),t=read(); fc[0]=1;
	for(int i=1;i<=n;i++){
	    ti[i-1]=read(),gi[i-1]=read();
	    fc[i]=1ll*fc[i-1]*i%P,buc[gi[i-1]]++;
	}
	
	g[1][0][0][1]=g[0][1][0][2]=g[0][0][1][3]=1;
	for(int i=0;i<=buc[1];i++)
	    for(int j=0;j<=buc[2];j++)
	        for(int k=0;k<=buc[3];k++){
	            add(g[i+1][j][k][1],g[i][j][k][2]+g[i][j][k][3]);
	            add(g[i][j+1][k][2],g[i][j][k][1]+g[i][j][k][3]);
	            add(g[i][j][k+1][3],g[i][j][k][1]+g[i][j][k][2]);
	            int arr=1ll*fc[i]*fc[j]%P*fc[k]%P;
	            s[i][j][k]=1ll*((g[i][j][k][1]+g[i][j][k][2])%P+g[i][j][k][3])*arr%P;
	        }
	
	for(int i=1;i<1<<n;i++){
		int sum=0,a=0,b=0,c=0;
		for(int j=0;j<n;j++)if((i>>j)&1)
			sum+=ti[j],gi[j]==1?a++:gi[j]==2?b++:c++;
		if(sum==t)add(ans,s[a][b][c]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
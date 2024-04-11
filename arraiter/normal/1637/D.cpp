#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[11];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

#define int long long

int n,A[105],B[105],dp[2][30010];

void solve(){
  n=read();
  rep(i,1,n)A[i]=read();
  rep(i,1,n)B[i]=read();
  int dt=0;
  rep(i,1,n)rep(j,i+1,n)dt+=A[i]*A[i]+A[j]*A[j];
  rep(i,1,n)rep(j,i+1,n)dt+=B[i]*B[i]+B[j]*B[j];
  memset(dp,0x3f,sizeof dp);
  int sel=0,sum=0;
  dp[0][0]=0;
  rep(i,1,n){
    memset(dp[sel^1],0x3f,sizeof dp[sel^1]);
    rep(j,0,20000){
      chkmin(dp[sel^1][j+A[i]],dp[sel][j]+j*A[i]+(sum-j)*B[i]);
      chkmin(dp[sel^1][j+B[i]],dp[sel][j]+j*B[i]+(sum-j)*A[i]);
    }
    sum+=A[i]+B[i];
    sel^=1;
  }
  int ans=1e18;
  rep(i,0,20000){
    chkmin(ans,dt+2*dp[sel][i]);
  }
  cout<<ans<<endl;
}

signed main(){
  int T;cin>>T;
  while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}
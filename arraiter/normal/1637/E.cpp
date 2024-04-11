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

const int maxn=3e5+10;
int n,A[maxn];

map<int,int>cnt;

vi vec[maxn];

map<int,set<int>>E;

void solve(){
  cnt.clear();
  n=read();int m=read();
  rep(i,1,n)A[i]=read(),cnt[A[i]]++,vec[i].clear();E.clear();
  for(pii p:cnt)vec[p.second].push_back(p.first);
  vi id;
  rep(i,1,n)if(!vec[i].empty())id.push_back(i);
  ll ans=0;
  rep(i,1,m){
    int x=read(),y=read();
    E[x].insert(y);
    E[y].insert(x);
  }
  for(int cx:id)for(int cy:id)if(cx<=cy){
    per(i,vec[cx].size()-1,0){
      int u=vec[cx][i],ps=-1;
      per(j,vec[cy].size()-1,0){
        int v=vec[cy][j];
        if(u==v)continue;
        auto it=E.find(u);
        if(!(it!=E.end()&&(it->second).count(v))){
          chkmax(ans,1ll*(cx+cy)*(u+v));
          ps=j;
          break;
        }
      }
      if(ps==(int)vec[cy].size()-1)break;
    }
  }
  printf("%lld\n",ans);
}

signed main(){
  int T;cin>>T;
  while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}
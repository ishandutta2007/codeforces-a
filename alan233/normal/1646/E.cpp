// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

bool vis[1000005],used[25000005];
int n,m;
ll ans=1;

int main(){
    n=read(),m=read();
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            int ex=0;
            for(ll j=i;j<=n;j*=i)vis[j]=1,++ex;
            if(ex>2){
                rep(k1,1,ex)
                    rep(t,1,m)
                        used[k1*t]=1;
                rep(k1,1,ex*m)
                    if(used[k1])ans++;
                rep(k1,1,ex)
                    rep(t,1,m)
                        used[k1*t]=0;
            }else if(ex==2){
                ans+=m;
                ans+=m-m/2;
            }else{
                ans+=m;
            }
        }
    }
    print(ans,'\n');
    return 0;
}
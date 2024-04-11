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

const int N=200005;

vector<int> adj[N],jda[N];
int dp[N],n,m;

int dfs(int u){
    if(dp[u])return dp[u];
    dp[u]=1;
    if(SZ(adj[u])>1)
        for(auto v:adj[u]){
            if(SZ(jda[v])==1)continue;
            ckmax(dp[u],dfs(v)+1);
        }
    return dp[u];
}

int main(){
    n=read(),m=read();
    rep(i,1,m){
        int u=read(),v=read();
        adj[u].pb(v),jda[v].pb(u);
    }
    int ans=0;
    rep(i,1,n)ckmax(ans,dfs(i));
    print(ans,'\n');
    return 0;
}
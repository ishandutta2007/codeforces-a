#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=1e9+7;
void add(int &x,int y){
    x+=y;
    x-=mod*(x>=mod);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int po(int x,int y){
    int z=1;
    while(y){
        if(y&1){
            z=mul(z,x);
        }
        x=mul(x,x);
        y>>=1;
    }
    return z;
}
int inv(int x){
    return po(x,mod-2);
}
int main(){
    AquA;
    int n,k;
    cin >> n >> k;
    if(n<=5000){
        int ans=0;
        int nw=n;
        for(int i=1;i<=n;i++){
            add(ans,mul(po(i,k),nw));
            nw=mul(nw,mul(n-i,inv(i+1)));
        }
        cout << ans << "\n";
        return 0;
    }
    vector<vector<int> > dp(k+1,vector<int>(k+1));
    dp[0][0]=1;
    for(int i=0;i<k;i++){
        for(int j=0;j<=i;j++){
            add(dp[i+1][j],mul(j,dp[i][j]));
            if(j+1<=k){
                add(dp[i+1][j+1],mul(n-j,dp[i][j]));
            }
        }
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        add(ans,mul(po(2,n-i),dp[k][i]));
    }
    cout << ans << "\n";
    return 0;
}
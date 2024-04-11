/*
             ,]@@@@@@@@@@@\]            *@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@*
          /@@@@@@@@@@@@@@@@@@@\`        *@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@*
       =/@@@@@@@/[     ,[\@@@@@@@`      *[[[[[[[[[[@@@@@/[[[[[[[[[[     @@@@@*
      =@@@@@@`             *\@@@@@\                @@@@@^               @@@@@*
     /@@@@@^                 *@@@@@@*              @@@@@^               @@@@@*
    =@@@@@`                    \@@@@@              @@@@@^               @@@@@*
   *@@@@@^                     *@@@@@^             @@@@@^               @@@@@*
   =@@@@@                       =@@@@@             @@@@@^               @@@@@*
   @@@@@^                       =@@@@@             @@@@@^               @@@@@*
   @@@@@^                       =@@@@@             @@@@@^               @@@@@*
   @@@@@^                       =@@@@@             @@@@@^               @@@@@*
   =@@@@@                       =@@@@/             @@@@@^               @@@@@*
   ,@@@@@^                     *@@@@@`             @@@@@^               @@@@@*
    =@@@@@`                    @@@@@/              @@@@@^               @@@@@*
     \@@@@@^                 ,@@@@@/               @@@@@^               @@@@@*
      =@@@@@@]             ,@@@@@@^                @@@@@^               @@@@@*
        \@@@@@@@@]]]]]]]/@@@@@@@/                  @@@@@^               @@@@@@@@@@@@@@@@@@@`
          [@@@@@@@@@@@@@@@@@@@`                    @@@@@^               @@@@@@@@@@@@@@@@@@@^
              [\@@@@@@@@@[[                        [[[[[`               [[[[[[[[[[[[[[[[[[[`





         ,@@@@@\               ,@@@@@`         =@@@@@      =@@@@@@@@@@@@@@@@@@@@@@@@@@
          ,@@@@@\             ,@@@@@`          =@@@@@      =@@@@@@@@@@@@@@@@@@@@@@@@/
           ,@@@@@\           ,@@@@@`           =@@@@@                        ,@@@@@`
            *@@@@@^         ,@@@@@`            =@@@@@                       /@@@@@
             *@@@@@^       ,@@@@@`             =@@@@@                     *@@@@@^
              *@@@@@^     ,@@@@@*              =@@@@@                    ,@@@@@`
               *@@@@@^   ,@@@@@*               =@@@@@                   /@@@@/
                *@@@@@^ ,@@@@@                 =@@@@@                 ,@@@@@^
                 *@@@@@\@@@@@                  =@@@@@                =@@@@@`
                  *@@@@@@@@@                   =@@@@@               /@@@@/
                   *@@@@@@@                    =@@@@@             ,@@@@@`
                    *@@@@@                     =@@@@@            =@@@@@*
                    *@@@@@                     =@@@@@          *@@@@@/
                    *@@@@@                     =@@@@^         ,@@@@@`
                    *@@@@@                    ,@@@@@*        /@@@@@
                    *@@@@@                   ,@@@@@`       *@@@@@/
                    *@@@@@            =@@@@@@@@@@@`       ,@@@@@@@@@@@@@@@@@@@@@@@@@@^
                    *@@@@@            =@@@@@@@@/`        =@@@@@@@@@@@@@@@@@@@@@@@@@@@^
*/
#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,dep[N],leaf[N],gkp[N];
VI e[N];
void dfs_dep(int u,int fa){
	dep[u] = dep[fa]+1;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs_dep(v,u);
	}
}
int dfs(int u,int fa){
	int res = 0;
	if(leaf[u] == 1)
		return 1; 
	for(auto v:e[u]){
		if(v==fa) continue;
		res +=  dfs(v,u);
	}
	if(res > 1) gkp[u] = res-1;
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1;i < n;++i){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs_dep(1,0);
	bool f1,f2;
	f1 = f2 = 0;
	for(int i = 1;i <= n;++i){
		if(e[i].size() == 1){
			leaf[i] = 1;
			if(dep[i]%2==1) f1 = 1;
			else f2 = 1;
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;++i)
		if(leaf[i] != 1) {dfs(i,0);break;}
	for(int i = 1;i <= n;++i)
		if(gkp[i]) ans -= gkp[i];
	ans += n-1; 
	if((f1&f2)==0) cout << 1 << ' ';
	else cout << 3 << ' ';
	cout << ans;
	return 0;
}
/*
7
1 2
1 3
1 4
1 5
1 6
1 7
*/
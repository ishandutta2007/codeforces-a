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
#define N 30015
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,k,a[N],tot,cur,ans[N];
char s[N];
VI res[3000015];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",&s);
	for(int i = 0;i < n;++i)
		if(s[i]=='R') ++tot;
	for(int i = 0;i < n;++i)
		if(s[i]=='R') a[cur++] = n-tot+cur-i-1;
	for(int i = 0;i < tot;++i){
		ans[i] = i;
		//cout <<a[i]<<endl;
		if(a[i]+i>k){
			cout << -1;
			return 0;
		}
	}
	ans[tot] = k;
	for(int i = tot-1;i >= 0;--i){
		ans[i] = max(ans[i+1]-a[i],ans[i]);
	}
	if(ans[0]>0){
		cout << -1;
		return 0;
	}
	for(int i = 0;i < tot;++i){
		//cout << ans[i] << endl;
		int l = k-a[i]+1-ans[i],r = l+a[i]-1;
		//cout << l << ' ' << r << endl;
		for(int j = l;j <= r;++j){
			//cout << n-(tot-i-1) << endl;
			res[j].pb(n-(tot-i-1)-a[i]+j-l);
		}
	}
	for(int i = 1;i <= k;++i){
		int sz = res[i].size();
		printf("%d ",sz);
		for(auto val:res[i]) printf("%d ",val);
		printf("\n");
	}
	return 0;
}
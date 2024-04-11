#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 200200

typedef long long ll;
using namespace std;

char str[220];

main(){

	int n;
	scanf("%d",&n);
	scanf(" %s",str);

	int ans = 0;

	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){

			int x=0, y=0;

			for(int k=i;k<=j;k++){
				if(str[k] == 'U') x++;
				if(str[k] == 'D') x--;
				if(str[k] == 'L') y++;
				if(str[k] == 'R') y--;
			}

			if(x == 0 && y == 0)
				ans++;

		}

	printf("%d\n",ans);

}
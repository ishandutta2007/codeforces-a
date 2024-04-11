#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

char str[100100];

main(){

		scanf("%s",str);

		int k=-1, n=strlen(str);

		for(int i=0;i<n;i++)
			if(k == -1 && str[i] == '0')
				k = i;

		if(k == -1)
			k = 0;

		for(int i=0;i<n;i++)
			if(i != k)
				printf("%c",str[i]);

		printf("\n");

	}
//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
#define MOD 1000000007
    LLI T,n,in,i,m,j;
    vector <LLI> a;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        scanf(" %lld",&n);
        pair<LLI,LLI> ma,mi;
        
		scanf(" %lld",&in);
        ma=mp(in,1);
        mi=mp(in,1);
        
        for(i=2;i<=n;++i)
        {
        	scanf(" %lld",&in);
        	
        	if(in>ma.X)
        	{
        		ma=mp(in,i);
			}
			
			if(in<=mi.X)
			{
				mi=mp(in,i);
			}
		}
    
    LLI cnt=0;
    cnt+=ma.Y-1;
    cnt+=n-mi.Y;
    cnt-=(ma.Y>mi.Y);
    
    cout<<cnt;
    
    return 0;
}
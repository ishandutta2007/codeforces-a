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
    string s;
    vector <LLI> :: iterator it;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    LLI ind=-1,d;
        fo(i,s.size())
        {
        	d=s[i]-'0';
            if(d%2==0)
            {
            	ind=i;
				if(s[i]<s[s.size()-1])
				{
					char c;
					c=s[i];
					s[i]=s[s.size()-1];
					s[s.size()-1]=c;
					break;
				}
			}
        }
        
    if(ind!=-1)
    {
    
    	if(i==s.size())
    	{
    		i=ind;
    		char c;
			c=s[i];
			s[i]=s[s.size()-1];
			s[s.size()-1]=c;
		}
    
        cout<<s;
    }
    else
    	cout<<-1;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=100010; typedef long long ll;
#define int ll
int T;
string s;
signed main(){
	cin>>T;
	while(T--){
		cin>>s;
		bool a0=1,a1=1;
		repeat(i,0,s.length()){
			if(s[i]=='1')a0=0;
			if(s[i]=='0')a1=0;
		}
		if(a0 || a1)cout<<s;
		else
		repeat(i,0,s.length())
			cout<<"01";
		cout<<endl;
	}
	return 0;
}
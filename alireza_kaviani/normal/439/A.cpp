#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<pii,int>               piii;
typedef pair<pll,ll>                plll;
typedef pair<pdd,double>            pddd;
typedef pair<pld,ld>                pldd;
typedef vector<int>                 vi;
typedef vector<ll>                  vll;
typedef vector<double>              vd;
typedef vector<ld>                  vld;
typedef vector<pii>                 vpii;
typedef vector<pll>                 vpll;
typedef vector<pdd>                 vpdd;
typedef vector<pld>                 vpld;
typedef vector<piii>                vpiii;
typedef vector<plll>                vplll;
typedef vector<pddd>                vpddd;
typedef vector<pldd>                vpldd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define pb                          push_back
#define ppb                         pop_back
#define pf                          push_front
#define ppf                         pop_front
#define X                           first
#define Y                           second
#define M                           make_pair


int main()
{
	int n,d;
	cin >> n >> d;
	
	int x=0 , y=-10;
	for(int i=0;i<n;i++)
	{
		int t;
		cin >> t;
		x+=t;
		y+=t+10;
	}
	
	if(y>d)
	{
		cout <<  -1 << endl;
		return 0;
	}
	
	cout << (d-x)/5;
	return 0;
}
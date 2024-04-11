#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<int, lng> PLL;
typedef pair<lng, int> PLI;
typedef pair<ld, ld> PDD;
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
#define hash asdhash
#define move asdmove
#define pow10 asdpow10
const double EPS = 1e-6;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld PI = 3.1415926535897932384626433832795;
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
uint gcd(uint a,uint b){return a?gcd(b%a,a):b;}

int n;
PLL ar[110000];
lng res;

void turn(){
	forn(i,n){
		ar[i]=mp(ar[i].Y,-ar[i].X);
	}
}

void half(){
	sort(ar,ar+n);
	multiset<lng> st;
	forn(i,n){
		st.insert(ar[i].Y);
	}
	int j=0;
	forn(i,n){
		while(true){
			lng d1;
			if(j<=i)
				d1=-1;
			else
				d1=ar[j-1].X-ar[i].X;
			lng d2;
			if(st.empty())
				d2=0;
			else
				d2=*st.rbegin()-*st.begin();
			if(d2>d1){
				if(j==n)
					return;
				st.erase(st.lower_bound(ar[j].Y));
				++j;
			}else{
				res=min(res,d1);
				break;
			}
		}
		st.insert(ar[i].Y);
	}
}

int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	
	cin>>n;
	forn(i,n){
		int x,y;
		scanf("%d%d",&x,&y);
		ar[i]=mp(x+y,x-y);
	}
	res=LINF;
	half();
	turn();
	half();
	printf("%.15lf",res/2.);
	
	return 0;
}
//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define pb push_back
#define F first
#define S second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;

	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

inline void scani(int& x){
	scanf("%d",&x);
}

//end of macro

const int N = 1e6 + 5;

int n;
string str;
int fl[2][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);

    cin>>n>>str;
    FOR(i,n){
        fl[0][i] = fl[1][i] = 0;
        if(str[i] == '0' || str[i] == '?'){
            if(i > 0)fl[0][i] = fl[0][i-1] + 1;
            else fl[0][i] = 1;
        }
        if(str[i] == '1' || str[i] == '?'){
            if(i > 0)fl[1][i] = fl[1][i-1] + 1;
            else fl[1][i] = 1;
        }
    }

    REP(i,1,n){
        int ans = 0;
        int l = 0, r = i-1;
        while(r < n){
            int mxfl = max(fl[0][r], fl[1][r]);
            // printf("at %d-%d, fl 0=%d 1=%d\n",l,r,fl[0][r],fl[1][r]);
            if(mxfl >= i){
                ans++;
                // printf("take %d-%d\n",l,r);
                l += i;
                r += i;
            }else{
                int fw = i - mxfl;
                l += fw;
                r += fw;
            }
        }
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
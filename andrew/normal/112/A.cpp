#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
const ll maxn=1000000;
ll a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
template <typename T>
T sqr(T a)
{
    return a*a;
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
string s1,s2;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    for(i=0;i<s1.size();++i)s1[i]=toupper(s1[i]);
    for(i=0;i<s2.size();++i)s2[i]=toupper(s2[i]);
    if(s1==s2)vout("0");
    if(s1<s2)vout("-1");
    vout("1");
return 0;
}
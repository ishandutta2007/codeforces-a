#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
 
typedef long double DOUBLE;
typedef complex<DOUBLE> COMPLEX;
typedef vector<DOUBLE> VD;
typedef vector<COMPLEX> VC;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

 
void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}
 
void get(vector<auto> &a)
{
    for (int i = 0; i<(int)a.size(); i++) cin>>a[i];
}
 
const int p = 998244353;
 
 
int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}
 
int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}
 
int sub(int a, int b) {
    int s = (a-b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}
 
int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}
 
int inv(int n)
{
    return po(n, p-2);
}
 
vector<int> Z(vector<int> s)
{
int n = s.size();
vector<int> z(n);
int L = 0, R = 0;
for (int i = 1; i < n; i++) {
  if (i > R) {
    L = R = i;
    while (R < n && s[R-L] == s[R]) R++;
    z[i] = R-L; R--;
  } else {
    int k = i-L;
    if (z[k] < R-i+1) z[i] = z[k];
    else {
      L = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    }
  }
}
return z;
}

mt19937 rnd(time(0));

void solve()
{
    ll n, k;
    cin>>n>>k;
    ll cnt = 0;
    while (n!=0)
    {
        cnt+=(n%k);
        n-=(n%k);
        if (n!=0) {n/=k; cnt++;}
    }
    cout<<cnt<<endl;
}

ll MAXX = 1LL<<32;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll answer = 0;
    int t;
    cin>>t;
    ll prod = 1;
    int cnt_taken = 0;
    stack<ll> cnt;
    string s;
    for (int i = 0; i<t; i++)
    {
        cin>>s;
        if (s=="add")
        {
            if (cnt.empty()) answer++;
            else
            {
                if (prod>=MAXX) {cout<<"OVERFLOW!!!"; return 0;}
                else answer+=prod;
            }
        }
        else if (s=="end")
        {
            if (cnt_taken<cnt.size()) cnt.pop();
            else {prod/=cnt.top(); cnt.pop(); cnt_taken--;}
        }
        else 
        {
            int n;
            cin>>n;
            cnt.push(n);
            if (prod<MAXX)
            {
                prod*=n;
                cnt_taken++;
            }
        }
        if (answer>=MAXX) {cout<<"OVERFLOW!!!"; return 0;}
    }
    
    cout<<answer;
    
}
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

const int p = 1e9 + 7;
 
 
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

ll MAXX = 1LL<<60;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i<n; i++) for (int j = 0; j<m; j++) cin>>a[i][j];
    
    bool check = true;
    vector<char> lol(n);
    for (int i = 0; i<n; i++)
    {
        lol[i] = a[i][0];
        for (int j = 1; j<m; j++)
        {
            if (a[i][j]!=a[i][j-1]) {lol[i] = '0'; check = false; break;}
        }
    }
    if (check&&(n%3==0))
    {
        int cnt = 0;
        for (int i = 1; i<n; i++) 
        {
            if (lol[i]!=lol[i-1]) cnt++;
        }
        sort(lol.begin(), lol.end());
        for (int i = 0; i<n/3; i++) if (lol[i]!='B') check = false;
        for (int i = n/3; i<2*n/3; i++) if (lol[i]!='G') check = false;
        for (int i = 2*n/3; i<n; i++) if (lol[i]!='R') check = false;
        if (cnt==2&&check==true) {cout<<"YES"; return 0;}
    }
    
    check = true;
    lol = vector<char>(m);
    for (int i = 0; i<m; i++)
    {
        lol[i] = a[0][i];
        for (int j = 1; j<n; j++) if (a[j][i]!=a[j-1][i]) {lol[i] = '0'; check = false; break;}
    }
    
    if (check&&(m%3==0))
    {
        int cnt = 0;
        for (int i = 1; i<m; i++) if (lol[i]!=lol[i-1]) cnt++;
        sort(lol.begin(), lol.end());
        for (int i = 0; i<m/3; i++) if (lol[i]!='B') check = false;
        for (int i = m/3; i<2*m/3; i++) if (lol[i]!='G') check = false;
        for (int i = 2*m/3; i<m; i++) if (lol[i]!='R') check = false;
        if (cnt==2&&check==true) {cout<<"YES"; return 0;}
    }
    
    cout<<"NO";
    
}
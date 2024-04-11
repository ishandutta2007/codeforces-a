#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

typedef long double DOUBLE;
typedef complex<DOUBLE> COMPLEX;
typedef vector<DOUBLE> VD;
typedef vector<COMPLEX> VC;

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
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

vector<int> Z(string s)
{
int n = s.length();
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



void solve()
{
    string s;
    cin>>s;
    
    vector<char> odd;
    vector<char> even;
    for (int i = 0; i<s.length(); i++) 
    {
        if ((s[i]-'a')%2==0) even.push_back(s[i]);
        else odd.push_back(s[i]);
    }
    
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    
    
    if (odd.size()==0||even.size()==0)
    {
        for (auto it: odd) cout<<it;
        for (auto it: even) cout<<it;
        cout<<endl;
        return;
    }
    
    int o = odd.size();
    int e = even.size();
    
    
    if (abs(odd[o-1]-even[0])!=1)
    {
        for (auto it: odd) cout<<it;
        for (auto it: even) cout<<it;
        cout<<endl;
        return;
    }
    
    if (abs(odd[0]-even[e-1])!=1)
    {
        for (auto it: even) cout<<it;
        for (auto it: odd) cout<<it;
        cout<<endl;
        return;
    }
    
    if (abs(odd[0]-even[0])!=1)
    {
        for (int i = o-1; i>=0; i--) cout<<odd[i];
        for (auto it: even) cout<<it;
        cout<<endl;
        return;
    }
    
    if (abs(odd[o-1]-even[e-1])!=1)
    {
        for (auto it: odd) cout<<it;
        for (int i = e-1; i>=0; i--) cout<<even[i];
        cout<<endl;
        return;
    }
    
    cout<<"No answer"<<endl;
    return;
    
    
    
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    for (int i = 0; i<t; i++) solve();
    
}
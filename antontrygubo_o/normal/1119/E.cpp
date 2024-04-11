#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const int p = 1e9 + 7;


int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}

int add(int a, int b) {
    ll s = (a+b);
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

ll ans(vector<ll> a)
{
    int n = a.size();
    ll sum = 0;
    int s = (n+1)%2;
    while (s<n)
    {
        sum+=a[s];
        s+=2;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    

    int n;
    cin>>n;
    vector<ll> a(n);
    get(a);
    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i<n; i++) pref[i] = pref[i-1] + a[i];
    vector<ll> left(n);
    left[0] = a[0]%3;
    for (int i = 1; i<n; i++)
    {
        int t = min(a[i]/2, left[i-1]);
        left[i] = left[i-1] - t;
        a[i]-=2*t;
        left[i]+=a[i]%3;
    }
    
    cout<<(pref[n-1]-left[n-1])/3;
    
}
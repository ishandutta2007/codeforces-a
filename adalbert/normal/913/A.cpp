#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef unsigned long long ll;
typedef long double ld;
const int arr=5e5+100;
const int md=1e9+7;
const int base=1e9+7;
///magic
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
///

signed main()
{
    int n,m;
    cin>>n>>m;
    if (n>40)
        cout<<m; else
    {
        int md=1;
        while (n--)
            md*=ll(2);
        cout<<m%md;
    }
}
/************************************************************************************************************************************************************************************
  *                                                                                                                                                                                  *
   *                                                                                                                                                                                  *
    *  ****************    **************    *               *    ****************    *           *    ****************    *              *    ****************    ****************    *
     *  *              *    *            *    *               *    *              *    **          *    *                   *              *    *              *                   *    *
      *  *              *    *            *    *               *    *              *    * *         *    *                   *              *    *              *                   *    *
       *  *              *    *            *    *               *    *              *    *  *        *    *                   *              *    *              *                   *    *
        *  *              *    *            *    *               *    *              *    *   *       *    *                   *              *    *              *                   *    *
         *  *              *    *            *    *               *    *              *    *    *      *    *                   *              *    *              *                   *    *
          *  ****************    **************    *****************    ****************    *     *     *    *                   ****************    *              *    ****************    *
           *  *              *    *  *                      *            *              *    *      *    *    *                                  *    *              *                   *    *
            *  *              *    *    *                    *            *              *    *       *   *    *                                  *    *              *                   *    *
             *  *              *    *      *                  *            *              *    *        *  *    *                                  *    *              *                   *    *
              *  *              *    *        *                *            *              *    *         * *    *                                  *    *              *                   *    *
               *  *              *    *          *              *            *              *    *          **    *                                  *    *              *                   *    *
                *  *              *    *            *            *            *              *    *           *    ****************                   *    ****************    ****************    *
                 *                                                                                                                                                                                  *
                  *                                                                                                                                                                                  *
                   ************************************************************************************************************************************************************************************/
/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  Author - Aryan Choudhary (@aryanc403)
 
  const short DEBUG { 0 };
  #define debug(x) if (DEBUG) cout << #x << " = " << x << '\n'
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"
#define PI 3.1415926535897932384626433832795
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

//const lli [3] ={ 999119999L,1000000007L,1000992299L};
//const lli [3] ={ 97L,101L,103L};
//const lli  = chrono::high_resolution_clock::now().time_since_epoch().count();
clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

class cmp
{
public:
    bool operator()(lli a , lli b) //For min priority_queue .
    {
        return a > b;
    }
};

void add( map<lli,lli> &m, lli x)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt==m.end())         m.insert(mp(x,1));
    else                    jt->Y++;
}

void del( map<lli,lli> &m, lli x)
{
    map<lli,lli> ::iterator jt;
    jt=m.find(x);
    if(jt->Y==1)            m.erase(jt);
    else                    jt->Y--;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli mod = 1000000007L;

    lli T,n,i,m,j,k,in,cnt,l,x,y;
    vi pri,ans;
    bool ex[1000006];
    //set<lli> s,tmp,a,b;
    bool vis[1000006];
    vi :: iterator it;
    //priority_queue < lli , vector < lli > , cmp > pq;// min priority_queue .

void pre(lli n)
{
    lli i,j;
    for(i=2;i<=n;++i)
    {
        if(vis[i])
            continue;
        pri.pb(i);
        for(j=i;j<=n;j+=i)
            vis[j]=true;
    }
}

void factorise(lli n)
{
    //set<lli> a;
    lli i;
    for(auto &i:pri)
    {
        if(i*i>n)
            break;
        if(n%i==0)
        {
            ans.pb(i);
            while(n%i==0)
            {
                n/=i;
            }
        }
    }
    if(n>1)
        ans.pb(n);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre(1000000);
    
    cin>>n;
    
    cin>>x>>y;
    factorise(x);
    factorise(y);
    lli sz=ans.size();
    lli cnt=sz;
    --n;
    while(n--)
    {
        cin>>x>>y;
        fo(i,sz)
        {
            if(!ex[i]&&x%ans[i]&&y%ans[i])
            {
                ex[i]=true;
                cnt--;
            }
        }
        if(cnt==0)
        {
            cout<<-1;
            return 0;
        }
    }
    fo(i,sz)
    {
        if(!ex[i])
        {
            cout<<ans[i];
            return 0;
        }
    }
    aryanc403();
    return 0;
}
/*#include <bits/stdc++.h>
#define gibon     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef struct pii{
    int x, y;
}pii;
int N, A[21][21], Sumd[21][21], Sumb[21][21];
long long dp[21][21][21][21][2];
long long cald(pii a, pii b)
{
    return Sumd[b.x][b.y]-Sumd[b.x][a.y-1]-Sumd[a.x-1][b.y]+Sumd[a.x-1][b.y-1];
}
long long calb(pii a, pii b)
{
    return Sumb[b.x][b.y]-Sumb[b.x][a.y-1]-Sumb[a.x-1][b.y]+Sumb[a.x-1][b.y-1];
}
void makesumd()
{
    Sumd[1][1]= (A[1][1]==2) ? 1 : 0;
    for(int i=2;i<=N;i++)
        Sumd[1][i]=Sumd[1][i-1]+((A[1][i]==2) ? 1 : 0);
    for(int i=2;i<=N;i++)
    {
        Sumd[i][1]=Sumd[i-1][1]+((A[i][1]==2) ? 1 : 0);
        for(int j=2;j<=N;j++)
        {
            Sumd[i][j]=Sumd[i-1][j]+Sumd[i][j-1]-Sumd[i-1][j-1];
        }
    }
}
void makesumb()
{
    Sumb[1][1]= (A[1][1]==1) ? 1 : 0;
    for(int i=2;i<=N;i++)
        Sumb[1][i]=Sumb[1][i-1]+((A[1][i]==1) ? 1 : 0);
    for(int i=2;i<=N;i++)
    {
        Sumb[i][1]=Sumb[i-1][1]+((A[i][1]==1) ? 1 : 0);
        for(int j=2;j<=N;j++)
        {
            Sumb[i][j]=Sumb[i-1][j]+Sumb[i][j-1]-Sumb[i-1][j-1];
        }
    }
}
long long finding(pii a, pii b, int typ)
{
    if(dp[a.x][a.y][b.x][b.y][typ]!=-1)
        return dp[a.x][a.y][b.x][b.y][typ];
    if(cald(a, b)==1)
    {
        if(calb(a, b)==0)
            return 1;
        return 0;
    }
    if(cald(a, b)==0)
        return 0;
    int ansp=0;
    if(typ==1)
    {
        if(a.y+2>=b.y)
            return 0;
        for(int i=a.y+1;i<b.y;i++)
        {
            if(calb({a.x, i}, {b.x ,i})>=1 && cald({a.x, i}, {b.x, i})==0)
                ansp+=
        }
    }
    else
    {

    }
}
int main()
{
    gibon
    cin >> N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)   cin >> A[i][j];
    makesumd();
    makesumb();
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=N;k++)
            {
                for(int l=1;l<=N;l++)
                    A[i][j][k][l][0]=A[i][j][k][l][1]=-1;
            }
        }
    }
    ans+=finding({1, 1}, {N, N}, 1);
    ans+=finding({1, 1}, {N, N}, 0);
}*/
#include <bits/stdc++.h>
using namespace std;
#define gibon     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
char A[101010];
int dp[101010][2], B[101010], dpp[101010][2];
int main()
{
    gibon
    cin >> A;
    int lenA=strlen(A);
    if(A[lenA-1]=='0')
        dp[lenA-1][0]=1, dp[lenA-1][1]=0;
    else
        dp[lenA-1][0]=0, dp[lenA-1][1]=1;
    for(int i=lenA-2;i>=0;i--)
    {
        if(A[i]=='0')
        dp[i][0]=max(dp[i+1][0], dp[i+1][1])+1, dp[i][1]=dp[i+1][1];
        else
        dp[i][0]=dp[i+1][0], dp[i][1]=dp[i+1][1]+1;
    }
    for(int i=lenA-1;i>=0;i--)
    {
        if(A[i]=='0')
        {
            B[i]=0;
            dpp[i][0]=max(dpp[i+1][0], dpp[i+1][1])+1;
            dpp[i][1]=dpp[i+1][1];
        }
        else
        {
            if(dp[i+1][0]==dp[i+1][1])
            {
                if(dpp[i+1][0]==dpp[i+1][1])
                {
                    B[i]=0;
                    dpp[i][0]=dpp[i+1][0]+1;
                    dpp[i][1]=dpp[i+1][1];
                }
                else if(dpp[i+1][0]>dpp[i+1][1])
                {
                    B[i]=0;
                    dpp[i][0]=dpp[i+1][0]+1;
                    dpp[i][1]=dpp[i+1][1];
                }
                else
                {
                    B[i]=1;
                    dpp[i][0]=dpp[i+1][0];
                    dpp[i][1]=dpp[i+1][1]+1;
                }
            }
            else if(dp[i+1][0]>dp[i+1][1])
            {
                if(dpp[i+1][0]>dpp[i+1][1])
                {
                    B[i]=1;
                    dpp[i][0]=dpp[i+1][0];
                    dpp[i][1]=dpp[i+1][1]+1;
                }
                else
                {
                    B[i]=0;
                    dpp[i][0]=dpp[i+1][0]+1;
                    dpp[i][1]=dpp[i+1][1];
                }
            }
            else
            {
                if(dpp[i+1][0]==dpp[i+1][1])
                {
                    B[i]=0;
                    dpp[i][0]=dpp[i+1][0]+1;
                    dpp[i][1]=dpp[i+1][1];
                }
                else if(dpp[i+1][0]>dpp[i+1][1])
                {
                    B[i]=0;
                    dpp[i][0]=dpp[i+1][0];
                    dpp[i][1]=dpp[i+1][1]+1;
                }
                else
                {
                    B[i]=1;
                    dpp[i][0]=dpp[i+1][0];
                    dpp[i][1]=dpp[i+1][1]+1;
                }
            }
        }
    }
    for(int i=0;i<lenA;i++)
    {
        cout << B[i];
    }
}
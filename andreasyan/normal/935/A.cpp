#include <iostream>
using namespace std;

int n;
int main()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<n;++i)
        if((n-i)%i==0)
            ++ans;
    cout<<ans<<endl;
    return 0;
}
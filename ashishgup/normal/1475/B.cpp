//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3005;

int32_t main()
{
	IOS;
	set<int> s;
	for(int i = 0; i * 2020 <= 1e6; i++)
	{
		for(int j = 0; i * 2020 + j * 2021 <= 1e6; j++)
			s.insert(i * 2020 + j * 2021);
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(s.find(n) != s.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
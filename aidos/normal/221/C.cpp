#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {
	int n, a[111111], b[111111];
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a+n);
	int ans = 0;
	for(int i  = 0; i<n; i++)
		if(a[i] != b[i]) ans++;
	if(ans < 3) cout << "YES";
	else cout << "NO";
    return 0;
}
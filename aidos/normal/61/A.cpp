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
#define pll pair <long long,long long>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define MAXN 1000000
#define INF 1000000000
using namespace std;
int main () {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector < int > v;
    for(int i = 0; i<n; i++){
        if(s[i] == t[i]) cout << 0;
        else cout << 1;
    }
    return 0;
}
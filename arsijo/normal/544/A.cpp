#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
//#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
const int MAX = 1e5;
const ld E = 1e-9;

int main(){

	int n;
	cin >> n;

	bool used[26];
	ms(used);

	vector<string> vec;
	string s;
	cin >> s;

	for(int i = 0; i < (int) s.length(); i++){
		if(!used[s[i] - 'a']){
			string st = "";
			st += s[i];
			vec.push_back(st);
			if((int) vec.size() == n){
				cout << "YES" << endl;
				for(int z = 0; z < (int) vec.size() - 1; z++)
					cout << vec[z] << endl;
				cout << *vec.rbegin();
				for(int j = i + 1; j < (int) s.length(); j++)
					cout << s[j];
				return 0;
			}
			used[s[i] - 'a'] = true;
		}else{
			vec[vec.size() - 1] += s[i];
		}
	}

	cout << "NO";

}
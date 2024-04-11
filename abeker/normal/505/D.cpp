#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N, M;
vector <int> V[MAXN], E[MAXN];
vector <int> comp;
bool bio[MAXN];
int color[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		V[a].push_back(b);
		V[b].push_back(a);
		E[a].push_back(b);
	}
}

void dfs(int x) {
	bio[x] = true;
	comp.push_back(x);
	for (int i = 0; i < V[x].size(); i++) 
		if (!bio[V[x][i]]) dfs(V[x][i]);
}

bool cycle(int x) {
	if (color[x] == 2) return false;
	if (color[x] == 1) return true;
	color[x] = 1;
	for (int i = 0; i < E[x].size(); i++) 
		if (cycle(E[x][i])) return true;
	color[x] = 2;
	return false;
}

bool check() {
	for (int i = 0; i < comp.size(); i++) 
		if (cycle(comp[i])) return true;
	return false;
}

int solve() {	
	int sol = 0;
	for (int i = 1; i <= N; i++)
		if (!bio[i]) {
			dfs(i);
			sol += (int)comp.size() - 1 + check();
			comp.clear();
		}
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}
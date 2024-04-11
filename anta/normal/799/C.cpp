#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }


template<typename Val, typename Compare = std::less<Val>, int BlockSize = 10>
class DirectRMQ {
public:
	typedef int Index;	//int(query)
	typedef char InBlockIndex;
	typedef InBlockIndex(*BlockTypeRef)[BlockSize];

	DirectRMQ(Compare comp_ = Compare()) :
		blockTypes(0), innerBlockTable(0), sparseTable(0) {
		comp = comp_;
		calcBallotNumbers();
		buildInnerBlockTable();
	}
	~DirectRMQ() {
		delete[] innerBlockTable;
		delete[] blockTypes; delete[] sparseTable;
	}

	void build(const Val *a, Index n) {
		blocks = (n + BlockSize - 1) / BlockSize;
		stHeight = 0; while (1 << stHeight < blocks) ++ stHeight;
		delete[] blockTypes; delete[] sparseTable;

		blockTypes = new BlockTypeRef[blocks];
		calcBlockTypes(a, n);
		buildInnerBlockTable(a, n);
		sparseTable = new Index[blocks * stHeight];
		buildSparseTable(a);
	}

	//[l,r]
	Index query(const Val *a, Index l, Index r) const {
		Index x = l / BlockSize, y = r / BlockSize, z = y - x;
		if (z == 0) return x * BlockSize + blockTypes[x][l % BlockSize][r % BlockSize];
		if (z == 1) return assumeleft_minIndex(a,
			x * BlockSize + blockTypes[x][l % BlockSize][BlockSize - 1],
			y * BlockSize + blockTypes[y][0][r % BlockSize]);
		z -= 2;
		Index k = 0, s;
		s = ((z & 0xffff0000) != 0) << 4; z >>= s; k |= s;
		s = ((z & 0x0000ff00) != 0) << 3; z >>= s; k |= s;
		s = ((z & 0x000000f0) != 0) << 2; z >>= s; k |= s;
		s = ((z & 0x0000000c) != 0) << 1; z >>= s; k |= s;
		s = ((z & 0x00000002) != 0) << 0; z >>= s; k |= s;
		return assumeleft_minIndex(a
			, assumeleft_minIndex(a,
				x * BlockSize + blockTypes[x][l % BlockSize][BlockSize - 1],
				sparseTable[x + 1 + blocks * k])
			, assumeleft_minIndex(a,
				sparseTable[y + blocks * k - (1 << k)],
				y * BlockSize + blockTypes[y][0][r % BlockSize])
		);
	}

	Val queryVal(const Val *a, Index l, Index r) const {
		Index x = l / BlockSize, y = r / BlockSize, z = y - x;
		if (z == 0) return a[x * BlockSize + blockTypes[x][l % BlockSize][r % BlockSize]];
		Val edge = minVal(
			a[x * BlockSize + blockTypes[x][l % BlockSize][BlockSize - 1]],
			a[y * BlockSize + blockTypes[y][0][r % BlockSize]]);
		if (z == 1) return edge;
		z -= 2;
		Index k = 0, s;
		s = ((z & 0xffff0000) != 0) << 4; z >>= s; k |= s;
		s = ((z & 0x0000ff00) != 0) << 3; z >>= s; k |= s;
		s = ((z & 0x000000f0) != 0) << 2; z >>= s; k |= s;
		s = ((z & 0x0000000c) != 0) << 1; z >>= s; k |= s;
		s = ((z & 0x00000002) != 0) << 0; z >>= s; k |= s;
		return minVal(edge, minVal(
			a[sparseTable[x + 1 + blocks * k]],
			a[sparseTable[y + blocks * k - (1 << k)]]));
	}
private:
	Compare comp;

	int ballotNumbers[BlockSize + 1][BlockSize + 1];
	InBlockIndex(*innerBlockTable)[BlockSize][BlockSize];

	Index blocks;
	int stHeight;
	BlockTypeRef *blockTypes;
	Index *sparseTable;

	inline Index minIndex(const Val *a, Index x, Index y) const {
		return comp(a[x], a[y]) || (a[x] == a[y] && x < y) ? x : y;
	}
	inline Index assumeleft_minIndex(const Val *a, Index x, Index y) const {
		return comp(a[y], a[x]) ? y : x;
	}

	inline Val minVal(Val x, Val y) const {
		return comp(y, x) ? y : x;
	}

	void buildSparseTable(const Val *a) {
		Index *b = sparseTable;
		if (stHeight) for (Index i = 0; i < blocks; i ++)
			b[i] = i * BlockSize + blockTypes[i][0][BlockSize - 1];
		for (Index t = 1; t * 2 < blocks; t *= 2) {
			std::memcpy(b + blocks, b, blocks * sizeof(Index));
			b += blocks;
			for (Index i = 0; i < blocks - t; ++ i)
				b[i] = assumeleft_minIndex(a, b[i], b[i + t]);
		}
	}

	void buildInnerBlockTable(const Val *a, Index n) {
		for (Index i = 0; i < blocks; i ++) {
			BlockTypeRef table = blockTypes[i];
			if (table[0][0] != -1) continue;
			const Val *p = getBlock(a, n, i);
			for (InBlockIndex left = 0; left < BlockSize; left ++) {
				Val minV = p[left];
				InBlockIndex minI = left;
				for (InBlockIndex right = left; right < BlockSize; right ++) {
					if (comp(p[right], minV)) {
						minV = p[right];
						minI = right;
					}
					table[left][right] = minI;
				}
			}
		}
	}

	//static
	const Val *getBlock(const Val *a, Index n, Index i) {
		Index offset = i * BlockSize;
		if (offset + BlockSize <= n)
			return a + offset;
		else {
			static Val tmp_a[BlockSize];
			std::copy(a + offset, a + n, tmp_a);
			Val maxVal = Val();
			for (Index j = i; j < n; j ++)	//ioffset()(())
				if (comp(maxVal, a[j])) maxVal = a[j];
			std::fill(tmp_a + (n - offset), tmp_a + BlockSize, maxVal);
			return tmp_a;
		}
	}

	void calcBlockTypes(const Val *a, Index n) {
		Val tmp_rp[BlockSize + 1];
		for (Index i = 0; i < blocks; i ++)
			blockTypes[i] = calcBlockType(getBlock(a, n, i), tmp_rp);
	}

	BlockTypeRef calcBlockType(const Val *a, Val *rp) {
		int q = BlockSize, N = 0;
		for (int i = 0; i < BlockSize; i ++) {
			while (q + i - BlockSize > 0 && comp(a[i], rp[q + i - BlockSize])) {
				N += ballotNumbers[BlockSize - i - 1][q];
				q --;
			}
			rp[q + i + 1 - BlockSize] = a[i];
		}
		return innerBlockTable[N];
	}

	void calcBallotNumbers() {
		for (int p = 0; p <= BlockSize; p ++) {
			for (int q = 0; q <= BlockSize; q ++) {
				if (p == 0 && q == 0)
					ballotNumbers[p][q] = 1;
				else if (p <= q)
					ballotNumbers[p][q] =
					(q ? ballotNumbers[p][q - 1] : 0) +
					(p ? ballotNumbers[p - 1][q] : 0);
				else
					ballotNumbers[p][q] = 0;
			}
		}
	}

	void buildInnerBlockTable() {
		int numberOfTrees = ballotNumbers[BlockSize][BlockSize];
		innerBlockTable = new InBlockIndex[numberOfTrees][BlockSize][BlockSize];
		for (int i = 0; i < numberOfTrees; i ++)
			innerBlockTable[i][0][0] = -1;
	}
};

int main() {
	int n; int C; int D;
	while (~scanf("%d%d%d", &n, &C, &D)) {
		vector<pii> fs[2];
		int maxB[2] = { -INF,-INF };
		rep(i, n) {
			int b; int p;
			scanf("%d%d", &b, &p);
			char buf[101];
			scanf("%s", buf);
			if ((*buf == 'C' && p <= C) || (*buf == 'D' && p <= D)) {
				amax(maxB[*buf == 'C' ? 0 : 1], b);
				fs[*buf == 'C' ? 0 : 1].emplace_back(p, b);
			}
		}
		int ans = max(0, maxB[0] + maxB[1]);
		rep(k, 2) {
			auto &v = fs[k];
			if (v.empty()) continue;
			sort(v.begin(), v.end());
			vector<int> bs(v.size());
			rep(i, v.size())
				bs[i] = v[i].second;
			DirectRMQ<int,greater<int>> rMq;
			rMq.build(bs.data(), (int)bs.size());
			int j = (int)v.size();
			int X = k == 0 ? C : D;
			rep(i, v.size()) {
				for (; i + 1 < j && v[i].first + v[j - 1].first > X; -- j);
				if (i + 1 < j) {
					int x = rMq.queryVal(bs.data(), i + 1, j - 1);
					amax(ans, bs[i] + x);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
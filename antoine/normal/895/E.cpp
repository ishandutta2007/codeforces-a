#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

template<class T, class U> struct LazyST {
	int n;
	int stOffset;
	int stHi;
	vector<T> st;
	vector<U> lazy;

	LazyST(const int n) : n(n) {
		stOffset = 1 << (int)ceil(log2(n));
		st.resize(stOffset << 1);
		lazy.resize(st.size());
		stHi = st.size() - 1 - stOffset;
	}

	LazyST(const int n, istream &in) : LazyST(n) { // O(n)
		for (int i = 0; i < n; ++i)
			in >> st[i + stOffset].v;
		for (int si = stOffset - 1; si; --si)
			st[si] = T(st[si << 1], st[si << 1 | 1]);
	}

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = U(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = U(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = U();
	}

	T query(const int i, const int j, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (i <= lo && hi <= j)
			return st[si];
		auto mid = (lo + hi) >> 1;
		if (j <= mid)
			return query(i, j, si << 1, lo, mid);
		if (mid < i)
			return query(i, j, si << 1 | 1, mid + 1, hi);
		return T(query(i, j, si << 1, lo, mid), query(i, j, si << 1 | 1, mid + 1, hi));
	}

	T query(const int i, const int j) {
		return (i <= j && i < n && j >= 0) ? query(i, j, 1, 0, stHi) : T();
	}

	void update(const int i, const int j, const U &u, const int si, const int lo, const int hi) {
		if (i <= lo && hi <= j) {
			lazy[si] = U(lazy[si], u);
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < i || j < lo)
				return;
			int mid = (lo + hi) >> 1;
			update(i, j, u, si << 1, lo, mid);
			update(i, j, u, si << 1 | 1, mid + 1, hi);
			st[si] = T(st[si << 1], st[si << 1 | 1]);
		}
	}

	void update(const int i, const int j, const U u) {
		if (i <= j)
			update(i, j, u, 1, 0, stHi);
	}

	// remove and return all non-zero values in a range, assuming all values >= 0
	void remAll(const int i, const int j, const int si, const int lo, const int hi, vector<int> &res) {
		updateLazy(si, lo, hi);
		if (!st[si] || hi < i || j < lo)
			return;
		if (lo == hi) {
			res.push_back(si - stOffset);
			st[si] = 0;
		}
		else {
			int mid = (lo + hi) >> 1;
			remAll(i, j, si << 1, lo, mid, res);
			remAll(i, j, si << 1 | 1, mid + 1, hi, res);
			st[si] = T(st[si << 1], st[si << 1 | 1]);
		}
	}

	vector<int> remAll(const int i, const int j) { // ^^
		vector<int> res;
		remAll(i, j, 1, 0, stHi, res);
		return res;
	}

	void updateAllLazy(const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			int mid = (lo + hi) >> 1;
			updateAllLazy(si >> 1, lo, mid);
			updateAllLazy(si >> 1 | 1, mid + 1, hi);
		}
	}

	void updateAllLazy() {
		updateAllLazy(1, 0, stHi);
	}

	const T * const retreive() {
		updateAllLazy();
		return &st[stOffset];
	}

	vector<T> retreiveVector() {
		updateAllLazy();
		return vector<T>(&st[stOffset], &st[stOffset + n]);
	}
};

struct StVal { // define
	double v = 0;
	StVal() {}
	StVal(const double v) : v(v) {}
	StVal(const StVal &v1, const StVal &v2) {
		v = v1 + v2;
	}
	operator double() const {
		return v;
	}
};

struct StUpdate { // define
	double a = 1, b = 0;
	StUpdate() {}
	StUpdate(const double a, const double b) : a(a), b(b) {}
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		a = u1.a * u2.a;
		b = u2.a * u1.b + u2.b;
	}
	void apply(StVal &v, const int lo, const int hi) {
		v.v = a * v.v + b * (hi - lo + 1);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	LazyST<StVal, StUpdate> st(n, cin);
	while (q-- > 0) {
		int type;
		cin >> type;
		if (type == 2) {
			int l, r;
			cin >> l >> r;
			cout << st.query(--l, --r) << '\n';
		} else {
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			
			double q1 = st.query(--l1, --r1);
			double q2 = st.query(--l2, --r2);
			
			double a1 = (double)(r1 - l1) / (r1 - l1 + 1);
			double a2 = (double)(r2 - l2) / (r2 - l2 + 1);

			double b1 = (1 - a1) * q2 / (r2 - l2 + 1);
			double b2 = (1 - a2) * q1 / (r1 - l1 + 1);

			st.update(l1, r1, { a1, b1 });
			st.update(l2, r2, { a2, b2 });
		}
	}
	return 0;
}
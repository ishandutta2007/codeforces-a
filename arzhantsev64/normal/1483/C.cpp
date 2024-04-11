#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

#define int long long

template <typename T>
struct seg_tree {

    vector<T> t;

    size_t main_size;

    void build(int v, int L, int R, vector<int> & a) {
        if (L == R - 1)
            t[v] = a[L];
        else {
            int M = (L + R) / 2;
            build(2 * v + 1, L, M, a);
            build(2 * v + 2, M, R, a);
            t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void update(int v, int L, int R, int i, int x) {
        if (R <= i || L > i)
            return;
        else if (L == R - 1)
            t[v] = x;
        else {
            int M = (L + R) / 2;
            update(2 * v + 1, L, M, i, x);
            update(2 * v + 2, M, R, i, x);
            t[v] = min(t[2 * v + 1], t[2 * v + 2]);
        }
    }

    void update(int i, int x) {
        update(0, 0, main_size, i, x);
    }

    int seg_min(int v, int L, int R, int l, int r) {
        if (R <= l || r <= L)
            return INF;
        else if (l <= L && R <= r)
            return t[v];
        else {
            int M = (L + R) / 2;
            return min(seg_min(2 * v + 1, L, M, l, r), seg_min(2 * v + 2, M, R, l, r));
        }
    }

    int seg_min(int l, int r) {
        return seg_min(0, 0, main_size, l, r);
    }

    seg_tree() { }

    seg_tree(vector<T> & a) {
        main_size = a.size();
        t.resize(a.size() * 4);
        build(0, 0, a.size(), a);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i)
        cin >> h[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    vector<int> near_lower(n);
    vector<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && h[st.back()] > h[i])
            st.pop_back();

        if (st.empty())
            near_lower[i] = -1;
        else
            near_lower[i] = st.back();
        
        st.push_back(i);
    }

    vector<int> ans_v(n);
    seg_tree<int> ans_st(ans_v);

    for (int i = 0; i < n; ++i) {
        int ans = INF;
        if (i != 0)
            ans = ans_st.seg_min(max(near_lower[i], 0LL), i) - b[i];
        // cout << -ans << endl;
        if (near_lower[i] == -1)
            ans = min(ans, -b[i]);
        // cout << -ans << endl;

        if (near_lower[i] != -1)
            ans = min(ans, ans_st.seg_min(near_lower[i], near_lower[i] + 1));
        // cout << -ans << endl << endl;

        ans_st.update(i, ans);
        // for (int j = 0; j <= i; ++j)
            // cout << -ans_st.seg_min(j, j + 1) << ' ';
        // cout << endl;
    }

    cout << -ans_st.seg_min(n - 1, n) << endl;

    return 0;
}
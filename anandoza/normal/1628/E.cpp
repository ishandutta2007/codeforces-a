#include <bits/stdc++.h>
using namespace std;

// clang-format off
// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)

#define L1(u, ...) [&](auto &&u) { return __VA_ARGS__; }
#define L2(u, v, ...) [&](auto &&u, auto &&v) { return __VA_ARGS__; }

#define sort_by(x, y) sort(all(x), [&](const auto &l, const auto &r) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template <typename T> void ckmin(T &a, const T &b) { a = min(a, b); }
template <typename T> void ckmax(T &a, const T &b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template <class T1, class T2> void re(pair<T1, T2> &p);
    template <class T> void re(vector<T> &a);
    template <class T, size_t SZ> void re(array<T, SZ> &a);

    template <class T> void re(T &x) { cin >> x; }
    void re(double &x) { string t; re(t); x = stod(t); }
    template <class Arg, class... Args> void re(Arg &first, Args &...rest) { re(first); re(rest...); }

    template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.first, p.second); }
    template <class T> void re(vector<T> &a) { for (auto &x : a) re(x); }
    template <class T, size_t SZ> void re(array<T, SZ> &a) { for (auto &x : a) re(x); }
}
using namespace __input;

namespace __output {
    template <typename T> struct is_outputtable { template <typename C> static constexpr decltype(declval<ostream &>() << declval<const C &>(), bool()) test(int) { return true; } template <typename C> static constexpr bool test(...) { return false; } static constexpr bool value = test<T>(int()); };
    template <class T, typename V = decltype(declval<const T &>().begin()), typename S = typename enable_if<!is_outputtable<T>::value, bool>::type> void pr(const T &x);

    template <class T, typename V = decltype(declval<ostream &>() << declval<const T &>())> void pr(const T &x) { cout << x; }
    template <class T1, class T2> void pr(const pair<T1, T2> &x);
    template <class Arg, class... Args> void pr(const Arg &first, const Args &...rest) { pr(first); pr(rest...); }

    template <class T, bool pretty = true> void prContain(const T &x) { if (pretty) pr("{"); bool fst = 1; for (const auto &a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0; if (pretty) pr("}"); }

    template <class T> void pc(const T &x) { prContain<T, false>(x); pr("\n"); }
    template <class T1, class T2> void pr(const pair<T1, T2> &x) { pr("{", x.first, ", ", x.second, "}"); }
    template <class T, typename V, typename S> void pr(const T &x) { prContain(x); }

    void ps() { pr("\n"); }
    template <class Arg> void ps(const Arg &first) { pr(first); ps(); }
    template <class Arg, class... Args> void ps(const Arg &first, const Args &...rest) { pr(first, " "); ps(rest...); }
}
using namespace __output;

#define __pn(x) pr(#x, " = ")
#ifdef ANAND_LOCAL
#define pd(...) pr("\033[1;31m"), __pn((__VA_ARGS__)), ps(__VA_ARGS__), pr("\033[0m"), cout << flush
#else
#define pd(...)
#endif

namespace __algorithm {
    template <typename T> void dedup(vector<T> &v) { sort(all(v)); v.erase(unique(all(v)), v.end()); }
    template <typename T> typename vector<T>::const_iterator find(const vector<T> &v, const T &x) { auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end(); }
    template <typename T> size_t index(const vector<T> &v, const T &x) { auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin(); }
    template <typename I> struct _reversed_struct { I &v_; explicit _reversed_struct(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
    template <typename I> _reversed_struct<I> reversed(I &v) { return _reversed_struct<I>(v); }
    template <typename I> struct _range_struct { const I first_, last_; explicit _range_struct(const I first, const I last) : first_{first}, last_{last} {} I begin() const { return first_; } I end() const { return last_; } };
    template <typename I> _range_struct<I> range(const I first, const I last) { return _range_struct<I>(first, last); }
}
using namespace __algorithm;

namespace __io {
    void setIO() {
#ifndef ANAND_LOCAL
        ios_base::sync_with_stdio(0); cin.tie(0);
#endif
        cout << setprecision(15);
    }
}
using namespace __io;
// }}}
// sparse_table {{{
#include <vector>
#include <cassert>

template<typename T, typename IdempotentBinaryOperation = const T&(*)(const T&, const T&)>
struct sparse_table {
    int SZ;
    IdempotentBinaryOperation TT;
    std::vector<std::vector<T>> data;

    sparse_table() {}

    sparse_table(IdempotentBinaryOperation _TT) : TT(_TT) {}

    template<typename Function>
    sparse_table(int _SZ, IdempotentBinaryOperation _TT, Function fn) : TT(_TT) {
        construct(_SZ, fn);
    }

    template<typename Function>
    void construct(int _SZ, Function fn) {
        SZ = _SZ;

        const int L = 32 - __builtin_clz(std::max(SZ - 1, 1));
        data.assign(L, std::vector<T>(SZ));

        for (int i = 0; i < SZ; i++)
            data[0][i] = fn(i);

        for (int l = 0; l + 1 < L; l++)
            for (int i = 0; i + (2 << l) <= SZ; i++)
                data[l + 1][i] = TT(data[l][i], data[l][i + (1 << l)]);
    }

    // Accumulates the elements at indices in [i, j) in O(1)
    T accumulate(int first, int last) const {
        assert(0 <= first && first < last && last <= SZ);
        int l = last - first > 1 ? 31 - __builtin_clz(last - first - 1) : 0;
        return TT(data[l][first], data[l][last - (1 << l)]);
    }
};
// }}}
// tree {{{
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

struct edge {
    int u_xor_v;

    edge() : u_xor_v(0) {}

    edge(int _u_xor_v) : u_xor_v(_u_xor_v) {}

    int get_nbr(int u) const {
        assert(u_xor_v);
        return u ^ u_xor_v;
    }
};

template<typename Data>
struct edge_with_data : edge {
    Data data;

    edge_with_data() : edge() {}

    edge_with_data(int _u_xor_v, Data _data) : edge(_u_xor_v), data(_data) {}
};

enum TreeInputFormat { EDGE_LIST, PARENT_LIST };
template<typename Edge>
struct tree {
    int V, root;
    std::vector<std::vector<Edge>> neighbors;

    std::vector<int> parent, depth, subtree_size, preorder, preorder_index;

    tree() : V(0), root(-1) {}

    tree(int _V, int _root) : V(_V), root(_root), neighbors(V) {}

    void add_edge(int u, int v, Edge e = {}) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        e.u_xor_v = u ^ v;
        neighbors[u].push_back(e);
        neighbors[v].push_back(e);
    }

    const Edge& parent_edge(int u) const {
        assert(u != root);
        return neighbors[u].front();
    }

    template<typename Function>
    void for_each_child(int u, Function fn) const {
        for (int i = u != root; i < int(neighbors[u].size()); i++)
            fn(neighbors[u][i]);
    }

    static void DefaultEdgeDataReader(__attribute((unused)) Edge &e) {}

    template<typename EdgeDataReader = void(*)(Edge&)>
    friend void re(tree &t, TreeInputFormat Format, int FirstIndex,
            EdgeDataReader read = DefaultEdgeDataReader) {
        assert(t.V > 0);
        for (int i = 0; i < t.V - 1; i++) {
            int u, v;
            std::cin >> u, u -= FirstIndex;
            if (Format == PARENT_LIST) v = i + 1;
            else std::cin >> v, v -= FirstIndex;
            Edge e;
            read(e);
            t.add_edge(u, v, e);
        }
        t.init();
    }

    void reroot(int _root) {
        root = _root;
        init();
    }

    void init() {
        parent.resize(V), depth.resize(V), subtree_size.resize(V), preorder_index.resize(V);

        parent[root] = -1;
        depth[root] = 0;

        traverse(root);

        for (int u = 0; u < V; u++) {
            sort(neighbors[u].begin(), neighbors[u].end(), [&](const Edge &a, const Edge &b) {
                return subtree_size[a.get_nbr(u)] > subtree_size[b.get_nbr(u)];
            });
        }

        preorder.clear();
        build_preorder(root);
    }

    void traverse(int u) {
        subtree_size[u] = 1;
        for (Edge e : neighbors[u]) {
            int v = e.get_nbr(u);
            if (v == parent[u]) continue;

            parent[v] = u;
            depth[v] = depth[u] + 1;
            traverse(v);
            subtree_size[u] += subtree_size[v];
        }
    }

    void build_preorder(int u) {
        preorder_index[u] = preorder.size();
        preorder.push_back(u);
        for_each_child(u, [&](Edge e) { build_preorder(e.get_nbr(u)); });
    }

    static void DefaultEdgeDataWriter(__attribute((unused)) Edge &e) {}

    template<typename EdgeDataWriter = void(*)(Edge&)>
    friend void pr(const tree& t, EdgeDataWriter write = DefaultEdgeDataWriter) {
        std::cout << "{V=" << t.V << " root=" << t.root << " |";
        for (int u = 0; u < t.V; u++) {
            std::cout << " " << u << "--{";
            t.for_each_child(u, [&](Edge e) {
                std::cout << "(ch=" << e.get_nbr(u);
                write(e);
                std::cout << ")";
            });
            std::cout << "}";
        }
        std::cout << "}";
    }
};
// }}}
// lowest_common_ancestor {{{
// {{{ graphs/tree.cpp }}}
// {{{ data_structures/sparse_table.cpp }}}

#include <vector>

template<typename Edge>
struct lowest_common_ancestor {
    const tree<Edge>& t;

    std::vector<int> euler_tour, tour_depths, first_visit, last_visit;

    int operator()(int i, int j) const {
        // if two visits have equal depth we prefer the later, allowing us to compute first_step
        return tour_depths[i] < tour_depths[j] ? i : j;
    }

    sparse_table<int, const lowest_common_ancestor<Edge>&> tour_table;

    lowest_common_ancestor() {}

    lowest_common_ancestor(const tree<Edge>& _t) : t(_t), first_visit(t.V), last_visit(t.V), tour_table(*this) {
        record_tour(t.root);
        tour_table.construct(int(euler_tour.size()), [](int i) { return i; });
    }

    void record_tour(int u) {
        first_visit[u] = int(euler_tour.size());
        euler_tour.push_back(u);
        tour_depths.push_back(t.depth[u]);

        t.for_each_child(u, [&](const Edge& e) {
            record_tour(e.get_nbr(u));
            euler_tour.push_back(u);
            tour_depths.push_back(t.depth[u]);
        });

        last_visit[u] = int(euler_tour.size()) - 1;
    }

    int lca(int u, int v) const {
        u = first_visit[u], v = first_visit[v];
        if (u > v) std::swap(u, v);
        return euler_tour[tour_table.accumulate(u, v + 1)];
    }

    int dist(int u, int v) const {
        return t.depth[u] + t.depth[v] - 2 * t.depth[lca(u, v)];
    }

    bool uv_path_has_w(int u, int v, int w) const {
        return w != -1 && dist(u, v) == (dist(u, w) + dist(w, v));
    }

    bool is_ancestor(int anc, int desc) const {
        return first_visit[anc] <= first_visit[desc] && first_visit[desc] <= last_visit[anc];
    }

    // Returns the neighbor of u on the simple path from u to v
    int first_step(int u, int v) const {
        assert(u != v);
        if (!is_ancestor(u, v)) return t.parent[u];
        return euler_tour[tour_table.accumulate(first_visit[u], first_visit[v]) + 1];
    }
};
// }}}
// union_find {{{
#include <vector>
#include <numeric>
#include <iostream>

struct union_find {
    struct node {
        int parent_or_size;
        node () : parent_or_size(-1) {}
    };

    mutable std::vector<node> data;

    union_find(int SZ = 0) : data(SZ) {}

    // Returns the root of the component containing i
    int find(int i) const {
        if (data[i].parent_or_size < 0)
            return i;
        data[i].parent_or_size = find(data[i].parent_or_size);
        return data[i].parent_or_size;
    }

    int size(int i) const {
        return -data[find(i)].parent_or_size;
    }

    bool is_root(int i) const {
        return data[i].parent_or_size < 0;
    }

    node& operator[] (int i) const {
        return data[find(i)];
    }

    /* Unites the components containing a and b if they are different.
     * Returns a boolean indicating whether a and b were in different components.
     */
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;

        if (-data[a].parent_or_size < -data[b].parent_or_size)
            std::swap(a, b);

        data[a].parent_or_size += data[b].parent_or_size;
        data[b].parent_or_size = a;

        return true;
    }

    friend void pr(const union_find& u) {
        std::cout << "{";
        bool first = 1;
        for (int i = 0; i < int(u.data.size()); i++) {
            if (u.is_root(i)) {
                if (!first) std::cout << ", ";
                else first = 0;
                std::cout << "[ " << i << " | size=" << u.size(i) << " ]";
            }
        }
        std::cout << "}";
    }
};
// }}}
// segment_tree_lazy {{{
#include <vector>
#include <cassert>

template<typename T, typename U,
    typename TAssociativeCombineFunction,
    typename UAssociativeCombineFunction,
    typename UApplicator>
struct segment_tree_lazy {
    int SZ;
    T t_identity;
    U u_identity;
    TAssociativeCombineFunction TT;
    UAssociativeCombineFunction UU;
    UApplicator UT;

    std::vector<T> data;
    std::vector<bool> has_update;
    std::vector<U> updates;

    segment_tree_lazy() {}

    segment_tree_lazy(int _SZ, T _t_identity, U _u_identity,
            TAssociativeCombineFunction _TT, UAssociativeCombineFunction _UU, UApplicator _UT)
            : SZ(_SZ), t_identity(_t_identity), u_identity(_u_identity), TT(_TT), UU(_UU), UT(_UT) {
        data.assign(2 * SZ, t_identity);
        has_update.assign(SZ, false);
        updates.assign(SZ, u_identity);
    }

    template<typename Function>
    void assign(Function fn) {
        for (int i = 0; i < SZ; i++)
            data[SZ + i] = fn(i);
        for (int i = SZ - 1; i; i--)
            data[i] = TT(data[2 * i], data[2 * i + 1]);
        has_update.assign(SZ, false);
        updates.assign(SZ, u_identity);
    }

private:
    void apply_update(int i, const U &u) {
        data[i] = UT(u, data[i]);
        if (i < SZ) {
            has_update[i] = true;
            updates[i] = UU(u, updates[i]);
        }
    }

    void propagate_ancestor_updates(int i) {
        for (int ht = 31 - __builtin_clz(i); ht > 0; ht--) {
            int anc = i >> ht;
            if (has_update[anc]) {
                apply_update(2 * anc, updates[anc]);
                apply_update(2 * anc + 1, updates[anc]);
                has_update[anc] = false;
                updates[anc] = u_identity;
            }
        }
    }

    void recompute_ancestors(int i) {
        for (i /= 2; i; i /= 2)
            data[i] = UT(updates[i], TT(data[2 * i], data[2 * i + 1]));
    }

    void modify_leaf(int i, T v, bool overwrite) {
        i += SZ;
        propagate_ancestor_updates(i);
        data[i] = overwrite ? v : TT(data[i], v);
        recompute_ancestors(i);
    }

public:
    // Assigns v at index i
    void assign(int i, T v) {
        modify_leaf(i, v, true);
    }

    // Replaces the current value at index i with TT(current value, v)
    void combine_and_assign(int i, T v) {
        modify_leaf(i, v, false);
    }

    // Applies update u to the elements at indices in [first, last)
    void apply_update(int first, int last, U u) {
        assert(0 <= first && last <= SZ);
        first += SZ, last += SZ;

        propagate_ancestor_updates(first);
        propagate_ancestor_updates(last - 1);

        for (int i = first, j = last; i < j; i /= 2, j /= 2) {
            if (i&1) apply_update(i++, u);
            if (j&1) apply_update(--j, u);
        }

        recompute_ancestors(first);
        recompute_ancestors(last - 1);
    }

    // Accumulates the elements at indices in [first, last)
    T accumulate(int first, int last) {
        assert(0 <= first && last <= SZ);
        first += SZ, last += SZ;

        propagate_ancestor_updates(first);
        propagate_ancestor_updates(last - 1);

        T left = t_identity, right = t_identity;
        for (int i = first, j = last; i < j; i /= 2, j /= 2) {
            if (i&1) left = TT(left, data[i++]);
            if (j&1) right = TT(data[--j], right);
        }
        return TT(left, right);
    }

    // Returns the current value at index i
    T read(int i) {
        i += SZ;
        propagate_ancestor_updates(i);
        return data[i];
    }
};
// }}}

// clang-format on

struct E {
    int u, v, w;
};

const int INF = 1e9;

enum U { ON, OFF, NONE } U_identity = NONE;
struct T {
    int left, right;
    int left_on, right_on;
} T_identity{INF, -1, INF, -1};

U uu(const U &l, const U &r) { return l == NONE ? r : l; }
T tt(const T &l, const T &r) {
    return {min(l.left, r.left), max(l.right, r.right), min(l.left_on, r.left_on), max(l.right_on, r.right_on)};
}
T ut(const U &u, const T &t) {
    switch (u) {
    case NONE:
        return t;
    case ON:
        return {t.left, t.right, t.left, t.right};
    case OFF:
        return {t.left, t.right, INF, -1};
    }
}

int main() {
    setIO();

    int n, q;
    re(n, q);

    vector<E> edges(n - 1);
    for (auto &[u, v, w] : edges) {
        re(u, v, w);
        u--, v--;
    }

    // Path max
    sort(all(edges), L2(l, r, l.w < r.w));
    n = 1 + sz(edges);
    tree<edge> tr(n + n - 1, 0);
    vector<int> big(n);
    iota(all(big), 0);
    union_find uf(n);
    vector<int> weights{};
    for (auto &[u, v, w] : edges) {
        int k = n + sz(weights);
        weights.push_back(w);
        tr.add_edge(big[uf.find(u)], k);
        tr.add_edge(big[uf.find(v)], k);
        uf.unite(u, v);
        big[uf.find(u)] = k;
    }
    tr.reroot(n + sz(weights) - 1);
    lowest_common_ancestor lca(tr);

    auto path_max = [&](int u, int v) -> int {
        if (u == v)
            return -1;
        return weights[-n + lca.lca(u, v)];
    };

    int tree_n = 1;
    while (tree_n < n)
        tree_n *= 2;
    segment_tree_lazy st(tree_n, T_identity, U_identity, tt, uu, ut);
    st.assign(L1(i, T{lca.first_visit[i], lca.last_visit[i], INF, -1}));

    while (q--) {
        int t;
        re(t);
        if (t == 3) {
            int x;
            re(x);
            x--;

            auto res = st.data[1];
            auto l = res.left_on, r = res.right_on;
            ckmin(l, lca.first_visit[x]);
            ckmax(r, lca.last_visit[x]);

            ps(path_max(lca.euler_tour[l], lca.euler_tour[r]));
        } else {
            int l, r;
            re(l, r);
            l--;

            st.apply_update(l, r, t == 1 ? ON : OFF);
        }
    }

    return 0;
}
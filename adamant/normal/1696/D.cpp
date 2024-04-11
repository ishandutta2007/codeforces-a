#include <bits/stdc++.h>

using namespace std;

namespace lib {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 

    template<typename T>
    T bpow(T x, size_t n) {
        if(n == 0) {
            return T(1);
        } else {
            auto t = bpow(x, n / 2);
            t = t * t;
            return n % 2 ? x * t : t;
        }
    }

    template<int m>
    struct modular {
        int r;
        constexpr modular(): r(0) {}
        constexpr modular(int64_t rr): r(rr % m) {if(r < 0) r += m;}
        modular inv() const {return bpow(*this, m - 2);}
        modular operator - () const {return r ? m - r : 0;}
        modular operator * (const modular &t) const {return (int64_t)r * t.r % m;}
        modular operator / (const modular &t) const {return *this * t.inv();}
        modular operator += (const modular &t) {r += t.r; if(r >= m) r -= m; return *this;}
        modular operator -= (const modular &t) {r -= t.r; if(r < 0) r += m; return *this;}
        modular operator + (const modular &t) const {return modular(*this) += t;}
        modular operator - (const modular &t) const {return modular(*this) -= t;}
        modular operator *= (const modular &t) {return *this = *this * t;}
        modular operator /= (const modular &t) {return *this = *this / t;}
        
        bool operator == (const modular &t) const {return r == t.r;}
        bool operator != (const modular &t) const {return r != t.r;}
        
        explicit operator int() const {return r;}
        int64_t rem() const {return 2 * r > m ? r - m : r;}
    };
    
    template<int T>
    istream& operator >> (istream &in, modular<T> &x) {
        return in >> x.r;
    }
    
    template<int T>
    ostream& operator << (ostream &out, modular<T> const& x) {
        return out << x.r;
    }
};

#define int int64_t

const int mod = 1e9 + 7;

using base = lib::modular<mod>;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int d[n];
    d[0] = 0;
    fill(d + 1, d + n, n);
    vector<int> sti, sta;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        while(!sti.empty() && a[sti.back()] > a[i]) {
            sti.pop_back();
        }
        while(!sta.empty() && a[sta.back()] < a[i]) {
            sta.pop_back();
        }
        if(i > 0) {
            if(!sti.empty() && sti.back() == i - 1) {
                auto it = lower_bound(
                    begin(sti),
                    end(sti),
                    sta.empty() ? 0 : sta.back()
                );
                d[i] = d[*it] + 1;
            }
            if(!sta.empty() && sta.back() == i - 1) {
                auto it = lower_bound(
                    begin(sta),
                    end(sta),
                    sti.empty() ? 0 : sti.back()
                );
                d[i] = d[*it] + 1;
            }
        }
        sta.push_back(i);
        sti.push_back(i);
    }
    cout << d[n - 1] << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
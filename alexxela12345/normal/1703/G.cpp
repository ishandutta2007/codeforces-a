#line 2 "/Users/alex/Templates/template/template.hpp"
#ifdef PRAGMAS
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <codecvt>
#include <complex>
#include <condition_variable>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <thread>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

#include <cassert>
#include <ccomplex>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cwchar>
#include <cwctype>

#line 2 "/Users/alex/Templates/template/macro.hpp"

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int((v).size()))
#line 6 "/Users/alex/Templates/template/util.hpp"

template<typename T>
void unq(std::vector<T> &arr) {
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
}
void unq(std::string &arr) {
    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
}
#line 79 "/Users/alex/Templates/template/template.hpp"

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;

namespace Quark {
    void solve();
};

int main() { Quark::solve(); }

#line 2 "main.cpp"

using namespace Quark;


void Quark::solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int K = 35;
        vector<ll> dp(K);
        for (int i = 0; i < n; i++) {
            vector<ll> dp2(K, LLONG_MIN);
            for (int j = 0; j < K; j++) {
                dp2[j] = dp[j] + (arr[i] >> j) - k;
                if (j) {
                    dp2[j] = max(dp2[j], dp[j - 1] + (arr[i] >> j));
                }
            }
            dp2[K - 1] = max(dp2[K - 1], dp[K - 1]);
            dp = dp2;
        }
        cout << *max_element(all(dp)) << endl;
    }
}
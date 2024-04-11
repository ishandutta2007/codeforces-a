// 392699

#include <bits/stdc++.h>

using namespace std;

#ifdef Aestas16
    #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
    #define debug(...) 0
#endif

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

set<int> s;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    for (int _ = fr(); _--;) {
        int a = fr(), b = fr();
        s.clear();
        int A = (a + b + 1) / 2, B = (a + b) / 2;
        for (int i = 0; i <= A; i++) {
            int j = a + i - A;
            if (j >= 0 && j <= B) s.insert(i + j);
        }
        A = (a + b) / 2, B = (a + b + 1) / 2;
        for (int i = 0; i <= A; i++) {
            int j = a + i - A;
            if (j >= 0 && j <= B) s.insert(i + j);
        }
        printf("%d\n", s.size());
        for (auto i : s) printf("%d ", i);
        puts("");
    }
    return 0;
}
/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e2;

int a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), minpos = 0, maxpos = n + 1;
        a[0] = 1e9, a[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            fr(a[i]);
            if (a[i] < a[minpos]) minpos = i;
            if (a[i] > a[maxpos]) maxpos = i;
        }
        int ans = 0;
        if (minpos > maxpos) swap(minpos, maxpos);
        ans = minpos + n - maxpos + 1;
        ans = min(ans, maxpos);
        ans = min(ans, n - minpos + 1);
        cat:
        printf("%d\n", ans);
    }
    return 0;
}
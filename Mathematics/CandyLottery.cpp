#include <bits/stdc++.h>

using namespace std;

double power(double a, int b) {
    double result = 1;
    while (b > 0) {
        if (b & 1) result *= a;
        a *= a;
        b >>= 1;
    }

    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    double ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += (power(i, n) - power(i - 1, n)) * i;
    }

    ans /=  power(k, n);

    printf("%.6f\n", ans);

    return 0;
}
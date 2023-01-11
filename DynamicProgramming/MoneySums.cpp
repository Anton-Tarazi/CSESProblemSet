#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, x;
    cin >> n;

    bitset<MAX_N + 1> dp;
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        cin >> x;
        dp |= (dp << x);
    }

    cout << dp.count() - 1 << "\n";
    for (int i = 1; i <= MAX_N; i++) {
        if (dp[i]) {
            cout << i << "\n";
        }
    }

    return 0;
}
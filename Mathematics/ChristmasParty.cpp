#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1;

    for (long long i = 3; i <= n; i++) {
        dp[i] = (i - 1) * ((dp[i - 2] + dp[i - 1]) % MOD) % MOD;
    }

    cout << dp[n] << "\n";


    return 0;
}
#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        matrix[a][b]++;
    }

    vector<vector<long long>> dp(1 << (n - 1), vector<long long> (n + 1));
    for (int j = 2; j <= n; j++) {
        dp[1 << (j - 2)][j] = matrix[1][j];
    }

    for (int i = 1; i < (1 << (n - 1)); i++) {
        for (int node = 2; node <= n; node++) {

            if (i & (1 << (node - 2))) {
                int subset = i ^ (1 << (node - 2));

                for (int j = 2; j <= n; j++) {
                    if (subset & (1 << (j - 2))) {
                        dp[i][node] = (dp[i][node] + dp[subset][j] * matrix[j][node]) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[(1 << (n - 1)) - 1][n] << "\n";


    return 0;
}
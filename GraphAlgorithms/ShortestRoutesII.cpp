#include <bits/stdc++.h>

using namespace std;

#define INF (long long) (1e18)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, q, a, b;
    long long c;

    cin >> n >> m >> q;

    vector<vector<long long>> distances(n + 1, vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        distances[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        distances[a][b] = min(distances[a][b], c);
        distances[b][a] = min(distances[b][a], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << (distances[a][b] == INF ? -1 : distances[a][b]) << "\n";
    }


    return 0;
}
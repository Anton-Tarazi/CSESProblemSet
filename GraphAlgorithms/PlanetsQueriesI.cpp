#include <bits/stdc++.h>

using namespace std;

const int LOG = 31;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, q, x, k;
    cin >> n >> q;

    vector<vector<int>> succ(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> succ[0][i];
    }

    for (int jump = 1; jump < LOG; jump++) {
        for (int node = 1; node <= n; node++) {
            succ[jump][node] = succ[jump - 1][succ[jump - 1][node]];
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> x >> k;
        for (int bit = 0; bit <= LOG; bit++) {
            if (k & (1 << bit)) {
                x = succ[bit][x];
            }
        }

        cout << x << "\n";
    }


    return 0;
}
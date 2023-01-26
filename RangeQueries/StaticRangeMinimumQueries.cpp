#include <bits/stdc++.h>

using namespace std;

#define LOG2(x) (31 - __builtin_clz(x))


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, q;
    cin >> n >> q;

    int log = LOG2(n);

    vector<vector<int>> sparse_table(log + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> sparse_table[0][i];
    }

    for (int i = 1; i <= log; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            sparse_table[i][j] = min(sparse_table[i - 1][j],
                        sparse_table[i - 1][j + (1 << (i - 1))]);
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int len = b - a + 1;
        int largest_pow = LOG2(len);

        int ans = min(sparse_table[largest_pow][a],
                      sparse_table[largest_pow][b - (1 << largest_pow) + 1]);
        cout << ans << "\n";

    }


    return 0;
}
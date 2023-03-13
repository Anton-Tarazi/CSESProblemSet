#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, q;
    cin >> n >> q;

    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));

    char tree;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tree;
            forest[i][j] = forest[i][j - 1] + forest[i - 1][j] - forest[i - 1][j - 1];
            forest[i][j] += tree == '*';
        }
    }

    int r1, c1, r2, c2;
    for (int i = 0; i < q; i++) {
        cin >> r1 >> c1 >> r2 >> c2;

        int bottom_row = max(r1, r2);
        int right_col = max(c1, c2);

        int top_row = min(r1, r2);
        int left_col = min(c1, c2);

       int trees = forest[bottom_row][right_col] -
                forest[top_row - 1][right_col] - forest[bottom_row][left_col - 1]
                + forest[top_row - 1][left_col - 1];

        cout << trees << "\n";

    }



    return 0;
}
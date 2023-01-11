#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000

bool building[MAX_SIZE][MAX_SIZE];
int m, n;
int dirs[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || !building[r][c]) {
        return;
    }

    building[r][c] = false;
    for (auto &dir : dirs) {
        dfs(r + dir[0], c + dir[1]);
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    char c;

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            building[i][j] = (c == '.');
        }
    }

    int rooms = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (building[i][j]) {
                dfs(i, j);
                rooms++;
            }
        }
    }

    cout << rooms << "\n";

    return 0;
}
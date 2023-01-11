#include <bits/stdc++.h>

using namespace std;

int m, n;

int dirs[][3] = {{'D', 1, 0}, {'U', -1, 0},
                 {'R', 0, 1}, {'L', 0, -1}};


bool dfs(int r, int c, int steps, vector<vector<int>> &graph, string &path) {
    if (r < 0 || r >= m || c < 0 || c >= n || steps >= graph[r][c]) {
        return false;
    }

    if (r == 0 || c == 0 || r == m - 1 || c == n - 1) {
        return true;
    }

    for (auto dir: dirs) {
        int nr = r + dir[1];
        int nc = c + dir[2];

        path.push_back((char) dir[0]);

        if (dfs(nr, nc, steps + 1, graph, path)) {
            return true;
        }
        path.pop_back();

    }

    return false;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    char ch;

    cin >> m >> n;
    const int INF = m * n + 1;

    vector<vector<int>> maze(m, vector<int>(n));

    int start_row = -1;
    int start_col = -1;
    vector<pair<int, int>> monsters;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ch;
            switch (ch) {
                case 'A': {
                    start_row = i;
                    start_col = j;
                }
                case '.': {
                    maze[i][j] = INF;
                    break;
                }
                case 'M': {
                    monsters.emplace_back(i, j);
                    maze[i][j] = 0;
                    break;
                }
                case '#': {
                    maze[i][j] = -1;
                    break;
                }
            }
        }
    }

    int monster_distance = 1;
    while (!monsters.empty()) {

        vector<pair<int, int>> new_monsters;

        for (pair<int, int> &monster: monsters) {
            auto [r, c] = monster;

            for (auto dir: dirs) {
                int nr = r + dir[1];
                int nc = c + dir[2];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                    maze[nr][nc] != INF) {
                    continue;
                }

                maze[nr][nc] = monster_distance;
                new_monsters.emplace_back(nr, nc);

            }
        }

        monsters = new_monsters;
        monster_distance++;
    }


    string out;
    if (dfs(start_row, start_col, 0, maze, out)) {
        cout << "YES\n";
        cout << out.size() << "\n";
        cout << out << "\n";
    } else {
        cout << "NO\n";
    }


    return 0;
}
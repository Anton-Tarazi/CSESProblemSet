#include <bits/stdc++.h>

using namespace std;

int dirs[][3] = {{'D', 1, 0}, {'U', -1, 0},
                 {'R', 0, 1}, {'L', 0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int m, n;

    cin >> m >> n;

    vector<vector<char>> maze(m, vector<char>(n));
    queue<pair<int, int>> to_check;

    int target_row = -1, target_col = -1;


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'A') {
                to_check.push({i, j});
            } else if (maze[i][j] == 'B') {
                maze[i][j] = '.';
                target_row = i;
                target_col = j;
            }
        }
    }

    while (!to_check.empty()) {

        auto[r, c] = to_check.front();
        to_check.pop();

        if (r == target_row && c == target_col) {
            break;
        }

        for (auto dir: dirs) {
            int nr = r + dir[1];
            int nc = c + dir[2];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                maze[nr][nc] != '.') {
                continue;
            }

            maze[nr][nc] = (char) dir[0];
            to_check.push({nr, nc});

        }
    }


    if (maze[target_row][target_col] == '.') {
        cout << "NO\n";
        return 0;
    }

    string directions;
    while (maze[target_row][target_col] != 'A') {

        char last_move = maze[target_row][target_col];
        directions.push_back(last_move);
        switch (last_move) {
            case ('U'): {
                target_row++;
                break;
            }
            case ('D'): {
                target_row--;
                break;
            }
            case ('L'): {
                target_col++;
                break;
            }
            case ('R'): {
                target_col--;
                break;
            }
        }
    }

    reverse(directions.begin(), directions.end());

    cout << "YES\n";
    cout << directions.size() << "\n";
    cout << directions << "\n";


    return 0;
}
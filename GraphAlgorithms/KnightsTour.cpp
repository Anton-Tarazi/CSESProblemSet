#include <bits/stdc++.h>

using namespace std;

constexpr int BOARD_SIZE = 8;
constexpr int LAST_STEP = BOARD_SIZE * BOARD_SIZE;

int board[BOARD_SIZE][BOARD_SIZE];
int dirs[][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2},
                 {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};


static inline bool in_bounds(int r, int c) {
    return r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == 0;
}

struct NeighborComparator {

    static inline int valid_neighbors(pair<int, int> coords) {
        auto [r, c] = coords;
        int count = 0;

        for (int *dir: dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (in_bounds(nr, nc))
                count++;
        }
        return count;
    }

    bool operator() (const pair<int, int> &left, const pair<int, int> right) {
        return valid_neighbors(left) < valid_neighbors(right);
    }

};



bool backtrack(int r, int c, int step) {
    board[r][c] = step;

    if (step == LAST_STEP) {
        return true;
    }

    vector<pair<int, int>> next_step;
    for (int *dir: dirs) {
        int nr = r + dir[0];
        int nc = c + dir[1];
        if (in_bounds(nr, nc)) {
            next_step.emplace_back(nr, nc);
        }
    }

    sort(next_step.begin(), next_step.end(), NeighborComparator());

    for (pair<int, int> &coords: next_step) {
        auto [nr, nc] = coords;
        if (backtrack(nr, nc, step + 1)) {
            return true;
        }
    }

    board[r][c] = 0;
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int x, y;
    cin >> x >> y;

    backtrack(--y, --x, 1);

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
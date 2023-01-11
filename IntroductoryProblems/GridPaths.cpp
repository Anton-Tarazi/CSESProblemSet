#include <bits/stdc++.h>

using namespace std;

#define GRID_SIZE 7

int grid[GRID_SIZE][GRID_SIZE] = {{0}};
int total = 0;
string path;

static inline int up_free(int r, int c) {
    return r - 1 >= 0 && !grid[r - 1][c];
}

static inline int down_free(int r, int c) {
    return r + 1 < GRID_SIZE && !grid[r + 1][c];
}

static inline int left_free(int r, int c) {
    return c - 1 >= 0 && !grid[r][c - 1];
}

static inline int right_free(int r, int c) {
    return c + 1 < GRID_SIZE && !grid[r][c + 1];
}

static inline int dir_free(int r, int c, char dir) {
    switch (dir) {
        case 'U': {
            return up_free(r, c);
        }
        case 'D': {
            return down_free(r, c);
        }
        case 'L': {
            return left_free(r, c);
        }
        default: {
            return right_free(r, c);
        }
    }
}

static inline int sides_free(int r, int c, char dir) {
    if (dir == 'U' || dir == 'D') {
        return left_free(r, c) && right_free(r, c);
    } else {
        return up_free(r, c) && down_free(r, c);
    }
}

void dfs(int i, int r, int c, char dir) {

    if (r < 0 || r >= GRID_SIZE || c < 0 || c >= GRID_SIZE || grid[r][c] ||
        (!dir_free(r, c, dir) && sides_free(r, c, dir))) {
        return;
    }

    if (i > 0 && path[i - 1] != '?' && dir != path[i - 1]) {
        return;
    }

    if (r == GRID_SIZE - 1 && c == 0) {
        if (i == GRID_SIZE * GRID_SIZE - 1) {
            total++;
        }
        return;
    }

    grid[r][c] = 1;

    dfs(i + 1, r - 1, c, 'U');
    dfs(i + 1, r + 1, c, 'D');
    dfs(i + 1, r, c - 1, 'L');
    dfs(i + 1, r, c + 1, 'R');

    grid[r][c] = 0;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    cin >> path;
    dfs(0, 0, 0, '\0');
    cout << total << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define GRID_SIZE 8

string board[GRID_SIZE];
int total = 0;
int cols[GRID_SIZE] = {0};
int diag1[2 * GRID_SIZE + 1] = {0};
int diag2[2 * GRID_SIZE + 1] = {0};


void backtrack(int row) {
    if (row == GRID_SIZE) {
        total++;
        return;
    }

    for (int col = 0; col < GRID_SIZE; col++) {
        if (cols[col] || diag1[row + col] || diag2[row - col + GRID_SIZE - 1]
            || board[row][col] == '*') {
            continue;
        }

        cols[col] = diag1[row + col] = diag2[row - col + GRID_SIZE - 1] = 1;
        backtrack(row + 1);
        cols[col] = diag1[row + col] = diag2[row - col + GRID_SIZE - 1] = 0;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    for (auto &row: board) {
        cin >> row;
    }

    backtrack(0);

    cout << total << "\n";

    return 0;
}
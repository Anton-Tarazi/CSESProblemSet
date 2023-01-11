#include <bits/stdc++.h>

#ifndef LOCAL
#pragma GCC target("popcnt")
#endif

using namespace std;

const int MAX_N = 3000;
bitset<MAX_N> rows[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    string s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> rows[i];
    }

    size_t total = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            size_t matching_cols = (rows[i] & rows[j]).count();

            total += matching_cols * (matching_cols - 1);

        }
    }

    cout << total / 2 << "\n";





    return 0;
}
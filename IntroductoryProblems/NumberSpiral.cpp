#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int t;
    long long r, c;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> r >> c;

        if (r > c) {
            long long corner = r * r - r + 1;
            if (r % 2 == 0)
                cout << corner + (r - c) << "\n";
            else
                cout << corner - (r - c) << "\n";

        } else {
            long long corner = c * c - c + 1;
            if (c % 2 == 0)
                cout << corner - (c - r) << "\n";
            else
                cout << corner + (c - r) << "\n";

        }

    }

    return 0;
}
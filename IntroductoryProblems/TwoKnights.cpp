#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        long long knight1 = k * k;
        long long knight2 = knight1 - 1;
        long long total_knights = knight1 * knight2 / 2;
        long long attacked = 4 * (k - 1) * (k - 2);

        cout << total_knights - attacked << "\n";

    }

    return 0;
}
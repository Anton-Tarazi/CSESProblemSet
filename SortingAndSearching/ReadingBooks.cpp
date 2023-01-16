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
    long long t;
    cin >> n;
    long long max = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> t;
        sum += t;
        max = std::max(max, t);
    }

    if (max > sum / 2) {
        cout << 2 * max << "\n";
    } else {
        cout << sum << "\n";
    }


    return 0;
}
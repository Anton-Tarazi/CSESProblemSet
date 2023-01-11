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
    long long x;
    cin >> n;

    long long max_sum = LONG_LONG_MIN;
    long long current_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;
        current_sum += x;
        max_sum = max(max_sum, current_sum);
        current_sum = max(current_sum, 0LL);

    }

    cout << max_sum << "\n";

    return 0;
}
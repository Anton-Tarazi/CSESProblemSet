#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    long long n;
    int x;
    cin >> n;

    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        sum += x;
    }

    long long expected_sum = n * (n + 1) / 2;
    cout << expected_sum - sum << "\n";

    return 0;
}
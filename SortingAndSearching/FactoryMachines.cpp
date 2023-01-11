#include <bits/stdc++.h>

using namespace std;

bool canMake(vector<long long> &times, long long target_quantity, long long time) {
    long long current_quantity = 0;

    for (long long &t: times) {
        current_quantity += (time / t);
    }

    return current_quantity >= target_quantity;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    long long t;
    cin >> n >> t;

    vector<long long> times(n);
    long long min_val = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> times[i];
        min_val = min(min_val, times[i]);
    }

    long long left = 0;
    long long right = min_val * t;
    long long ans = -1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (canMake(times, t, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }

    }

    cout << ans << "\n";


    return 0;
}
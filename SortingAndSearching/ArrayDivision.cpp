#include <bits/stdc++.h>

using namespace std;

bool can_divide(vector<int> &nums, long long max_sum, int k) {
    int divisions = 0;
    long long sum = 0;

    for (int n: nums) {
        if (sum + n <= max_sum) {
            sum += n;
        } else {
            sum = n;
            divisions++;
        }
    }

    return divisions < k;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, k, x;
    cin >> n >> k;

    long long left = LONG_LONG_MIN;
    long long right = 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums[i] = x;

        if (x > left) left = x;
        right += x;
    }

    long long ans = right;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (can_divide(nums, mid, k)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }

    }

    cout << ans << "\n";


    return 0;
}
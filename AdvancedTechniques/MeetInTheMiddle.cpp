#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, x;
    cin >> n >> x;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<long long, int> counts;
    int mid = n / 2;
    int second_half = n - mid;

    for (int i = 0; i < (1 << mid); i++) {
        long long subset_sum = 0;

        for (int j = 0; j < mid; j++) {
            if (i & (1 << j)) {
                subset_sum += nums[j];
            }
        }

        counts[subset_sum]++;
    }

    long long total_subsets = 0;

    for (int i = 0; i < (1 << second_half); i++) {
        long long subset_sum = 0;

        for (int j = 0; j < second_half; j++) {
            if (i & (1 << j)) {
                subset_sum += nums[j + mid];
            }
        }

        auto other_half = counts.find(x - subset_sum);
        if (other_half != counts.end()) {
            total_subsets += other_half->second;
        }

    }

    cout << total_subsets << "\n";

    return 0;
}
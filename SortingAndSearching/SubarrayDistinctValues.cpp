#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long count = 0;
    unordered_map<int, int> values;
    int distinct = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        if (values[nums[right]]++ == 0) distinct++;

        while (distinct > k) {
            if (--values[nums[left++]] == 0) distinct--;
        }

        count += right - left + 1;

    }

    cout << count << "\n";


    return 0;
}
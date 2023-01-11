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

    long long count = 0;
    long long sum = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        sum += nums[right];
        while (sum >= x) {
            if (sum == x) count++;

            sum -= nums[left++];
        }
    }

    cout << count << "\n";


    return 0;
}
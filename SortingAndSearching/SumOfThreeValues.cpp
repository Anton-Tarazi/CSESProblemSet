#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, x, a;
    cin >> n >> x;
    vector<pair<int, int>> nums(n);
    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums[i] = {a, i + 1};
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int total = nums[i].first + nums[j].first + nums[k].first;
            if (total == x) {
                cout << nums[i].second << " " << nums[j].second
                    << " " << nums[k].second << "\n";
                return 0;
            } else if (total < x) {
                j++;
            } else {
                k--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";


    return 0;
}
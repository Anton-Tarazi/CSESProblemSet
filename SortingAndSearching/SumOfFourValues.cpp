#include <bits/stdc++.h>

using namespace std;

#define V first
#define P second


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, x, a;
    cin >> n >> x;
    vector <pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums[i] = {a, i + 1};
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                long long total = nums[i].V + nums[j].V + nums[k].V + nums[l].V;
                if (total == x) {
                    cout << nums[i].P << " " << nums[j].P << " "
                        << nums[k].P << " " << nums[l].P << "\n";
                    return 0;
                } else if (total < x) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
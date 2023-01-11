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
    cin >> n;
    vector<long long> weights;
    for (int i = 0; i < n; i++) {
        cin >> x;
        weights.push_back(x);
    }

    long long sum = accumulate(weights.begin(), weights.end(), 0LL);
    long long min_diff = sum;

    for (int i = 0; i < (1 << n); i++) {

        long long subgroup_sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subgroup_sum += weights[j];
            }
        }

        min_diff = min(min_diff, abs(sum - 2 * subgroup_sum));
    }

    cout << min_diff << "\n";
    return 0;
}
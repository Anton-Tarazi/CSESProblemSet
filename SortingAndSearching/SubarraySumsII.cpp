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

    long long count = 0;
    long long sum = 0;
    unordered_map<long long, long long> prefix_sums;
    prefix_sums[0] = 1;

    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;

        auto need = prefix_sums.find(sum - x);
        if (need != prefix_sums.end()) count += need->second;

        prefix_sums[sum]++;
    }

    cout << count << "\n";


    return 0;
}
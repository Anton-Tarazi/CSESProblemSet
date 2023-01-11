#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a;
    cin >> n;

    long long count = 0;
    int sum = 0;
    vector<int> prefix_sums(n);
    prefix_sums[0] = 1;

    for (int i = 0; i < n; i++) {
        cin >> a;
        sum = ((sum + a) % n + n) % n;

        count += prefix_sums[sum];
        prefix_sums[sum]++;
    }

    cout << count << "\n";

    return 0;
}
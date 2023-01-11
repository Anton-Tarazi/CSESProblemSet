#include <bits/stdc++.h>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a, b, x;
    cin >> n >> a >> b;

    vector<long long> prefix_sums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        prefix_sums[i] = prefix_sums[i - 1] + x;
    }

    long long max_subarray = LONG_LONG_MIN;
    int window_size = b - a + 1;
    deque<long long> q;

    for (int right = a; right < n + window_size; right++) {

        if (right <= n) {
            while (!q.empty() && prefix_sums[right] > prefix_sums[q.back()]) {
                q.pop_back();
            }
        }

        if (!q.empty() && right - q.front() >= window_size) {
            q.pop_front();
        }

        if (right <= n) {
            q.push_back(right);
        }

        if (right >= b) {
            max_subarray = max(max_subarray, prefix_sums[q.front()] - prefix_sums[right - b]);
        }

    }

    cout << max_subarray << "\n";


    return 0;
}
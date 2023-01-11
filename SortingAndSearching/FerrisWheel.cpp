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

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());
    int left = 0;
    int right = n - 1;

    int gondolas = 0;
    while (left <= right) {
        if (weights[left] + weights[right] <= x) {
            left++;
        }
        gondolas++;
        right--;
    }

    cout << gondolas << "\n";



    return 0;
}
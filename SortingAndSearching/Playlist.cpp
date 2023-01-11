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

    unordered_map<int, int> last_index;
    int max_streak = 0;
    int left = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (last_index.count(x) && last_index[x] >= left) {
            left = last_index[x] + 1;
        }

        last_index[x] = i;
        max_streak = max(max_streak, i - left + 1);

    }

    cout << max_streak << "\n";


    return 0;
}
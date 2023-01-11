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

    vector<int> increasing;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (increasing.empty() || x > increasing.back()) {
            increasing.push_back(x);
        } else {
            auto target = lower_bound(increasing.begin(), increasing.end(), x);
            *target = x;
        }
    }

    cout << increasing.size() << "\n";


    return 0;
}
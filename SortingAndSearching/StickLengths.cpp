#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> lengths(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    sort(lengths.begin(), lengths.end());
    int median = lengths[n / 2];

    long long cost = 0;
    for (int length: lengths) {
        cost += abs(length - median);
    }

    cout << cost << "\n";


    return 0;
}
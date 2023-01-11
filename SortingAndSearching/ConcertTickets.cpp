#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, t, c;
    cin >> n >> m;

    multiset<int> tickets;

    for (int i = 0; i < n; i++) {
        cin >> t;
        tickets.insert(t);
    }


    for (int i = 0; i < m; i++) {
        cin >> c;

        auto price = tickets.lower_bound(c + 1);
        if (price == tickets.begin()) {
            cout << "-1\n";
        } else {
            cout << *--price << "\n";
            tickets.erase(price);
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> movie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, k, a, b;
    cin >> n >> k;
    vector<movie> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        movies[i] = {a, b};
    }

    multiset<int, greater<>> club;
    for (int i = 0; i < k; i++) club.insert(0);

    sort(movies.begin(), movies.end(), [](movie &left, movie &right) {
        return left.second < right.second;
    });

    int watched = 0;
    for (movie &m: movies) {
        auto p = club.lower_bound(m.first);
        if (p != club.end()) {
            watched++;
            club.erase(p);
            club.insert(m.second);
        }
    }

    cout << watched << "\n";


    return 0;
}
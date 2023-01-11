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

    int n, a, b;
    cin >> n;
    vector<movie> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        movies[i] = {a, b};
    }

    sort(movies.begin(), movies.end(), [](movie &left, movie &right) {
        return left.second < right.second;
    });

    int watched = 0;
    int last_end = 0;
    for (movie &m: movies) {
        if (m.first >= last_end) {
            watched++;
            last_end = m.second;
        }
    }

    cout << watched << "\n";

    return 0;
}
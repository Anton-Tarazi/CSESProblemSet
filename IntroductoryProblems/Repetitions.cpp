#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    int max_rep = 1;
    int current_rep = 0;
    char last_char = 0;

    for (char &c: s) {
        if (c == last_char) {
            current_rep++;
        } else {
            max_rep = max(max_rep, current_rep);
            current_rep = 1;
            last_char = c;
        }

    }
    max_rep = max(max_rep, current_rep);

    cout << max_rep << "\n";

    return 0;
}
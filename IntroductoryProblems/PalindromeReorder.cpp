#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int letters[26] = {0};
    string s;
    cin >> s;

    for (char &c: s) {
        letters[c - 'A']++;
    }

    int mid = -1;
    for (int i = 0; i < 26; i++) {
        if (letters[i] % 2 == 1) {
            if (mid == -1) {
                mid = i;
            } else {
                cout << "NO SOLUTION\n";
            }
        }

        letters[i] /= 2;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < letters[i]; j++) {
            cout << (char) (i + 'A');
        }
    }

    if (mid != -1)
        cout << (char) (mid + 'A');

    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < letters[i]; j++) {
            cout << (char) (i + 'A');
        }
    }

    cout << "\n";

    return 0;
}
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
    int mod = n % 4;
    if (mod == 1 || mod == 2) {
        cout << "NO\n";
    } else if (mod == 3) {
        cout << "YES\n";

        cout << n / 2 + 1 << "\n";
        cout << "1 2 ";
        for (int i = 4; i <= n; i += 4) {
            cout << i << " " << i + 3 << " ";
        }
        cout << "\n";

        cout << n / 2 << "\n";
        cout << "3 ";
        for (int i = 4; i <= n; i += 4) {
            cout << i + 1 << " " << i + 2 << " ";
        }
        cout << "\n";

    } else {
        cout << "YES\n";

        cout << n / 2 << "\n";
        for (int i = 1; i <= n; i += 4) {
            cout << i << " " << i + 3 << " ";
        }
        cout << "\n";


        cout << n / 2 << "\n";
        for (int i = 1; i <= n; i += 4) {
            cout << i + 1 << " " << i + 2 << " ";
        }
        cout << "\n";

    }

    return 0;
}
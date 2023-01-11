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

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    int mid = n / 2;
    for (int i = 1; i <= mid; i++) {
        cout << i + mid << " ";
        cout << i << " ";
    }

    if (n % 2 == 1) cout << n;
    cout << "\n";

    return 0;
}
#include <bits/stdc++.h>

using namespace std;


int subtract_digits(int n) {
    if (n == 0) {
        return 0;
    }

    int max_digit = -1;
    int copy = n;
    while (copy != 0) {
        int digit = copy % 10;
        max_digit = max(max_digit, digit);
        copy /= 10;
    }

    return 1 + subtract_digits(n - max_digit);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    cout << subtract_digits(n) << "\n";

    return 0;
}
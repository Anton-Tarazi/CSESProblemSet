#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    long long n;
    long long count = 0;
    cin >> n;
    long long div = 5;

    while (div <= n) {
        count += n / div;
        div *= 5L;
    }

    cout << count << "\n";

    return 0;
}
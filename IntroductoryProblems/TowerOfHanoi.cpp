#include <bits/stdc++.h>

using namespace std;

void solve(int n, int source, int mid, int dest) {
    if (n == 0) return;

    solve(n - 1, source, dest, mid);
    cout << source << " " << dest << "\n";
    solve(n - 1, mid, source, dest);

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

    cout << (1 << n) - 1 << "\n";
    solve(n, 1, 2, 3);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> applicant;
#define P first
#define A second


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a, b, x, y;
    cin >> a >> b >> n;

    vector<applicant> applicants(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        applicants[i] = {x, y};
    }


    return 0;
}
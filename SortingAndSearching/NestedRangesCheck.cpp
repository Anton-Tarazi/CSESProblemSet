#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> range;

int main() { //TODO: finish!
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a, b;
    cin >> n;
    vector<range> ranges(n);
    map<range, int> pos;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ranges[i] = range(a, b);
        pos[ranges[i]] = i;
    }

    sort(ranges.begin(), ranges.end());

    vector<bool> contained(n, false);
    vector<bool> contains(n, false);




    for (int i = 0; i < n; i++) {
        cout << ranges[i].first << ranges[i].second << " ";
    }


    return 0;
}
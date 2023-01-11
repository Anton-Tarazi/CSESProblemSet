#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int x, n, p;
    cin >> x >> n;

    map<int, int> lights;
    multiset<int> sizes;
    sizes.insert(x);
    lights[0] = x;

    for (int i = 0; i < n; i++) {
        cin >> p;

        auto entry = --lights.lower_bound(p);
        int start = entry->first;
        int end = entry->second;

        lights.erase(entry);
        sizes.erase(sizes.find(end - start));

        lights[start] = p;
        lights[p] = end;
        sizes.insert(p - start);
        sizes.insert(end - p);

        cout << *sizes.rbegin() << " ";

    }

    cout << "\n";


    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> customer;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a, b;
    cin >> n;
    vector<customer> customers(2 * n);

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        customers[i] = customer(a, 1);
        customers[i + n] = customer(b, -1);
    }

    sort(customers.begin(), customers.end());

    int max_customers = 0;
    int current_customers = 0;

    for (customer &c: customers) {
        cout << c.first << " " << c.second << "\n";
        current_customers += c.second;
        max_customers = max(max_customers, current_customers);
    }

    cout << max_customers << "\n";

    return 0;
}
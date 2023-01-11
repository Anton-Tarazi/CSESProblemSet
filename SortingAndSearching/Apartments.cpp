#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int m, n, k, a, b;

    cin >> n >> m >> k;

    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int i = 0; i < n; i++) {
        cin >> a;
        applicants[i] = a;
    }

    for (int i = 0; i < m; i++) {
        cin >> b;
        apartments[i] = b;
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int apt_pointer = 0;

    int count = 0;
    for (int &applicant: applicants) {
        while (apt_pointer < m && apartments[apt_pointer] < applicant - k) {
            apt_pointer++;
        }

        if (apt_pointer < m && apartments[apt_pointer] <= applicant + k) {
            count++;
            apt_pointer++;
        }

    }

    cout << count << "\n";


    return 0;
}
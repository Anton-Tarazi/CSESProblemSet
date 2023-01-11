#include <bits/stdc++.h>

using namespace std;

vector<string> generate_code(int n) {
    if (n == 0) {
        return {""};
    }

    vector<string> smaller_code = generate_code(n - 1);
    int order = 0;
    vector<string> code;

    for (string &s: smaller_code) {
        if (order) {
            code.push_back(s + "0");
            code.push_back(s + "1");
            order = 0;
        } else {
            code.push_back(s + "1");
            code.push_back(s + "0");
            order = 1;
        }
    }

    return code;
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

    vector<string> codes = generate_code(n);
    for (string &s: codes) {
        cout << s << "\n";
    }


    return 0;
}
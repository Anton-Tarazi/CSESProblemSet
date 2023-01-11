#include <bits/stdc++.h>

using namespace std;

vector<string> perms;


void permute(string path, unsigned long long size, int* counts) {
    if (path.length() == size) {
        perms.push_back(path);
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            path.push_back((char) (i + 'a'));
            counts[i]--;
            permute(path, size, counts);
            path.pop_back();
            counts[i]++;
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    string s;
    int counts[26] = {0};
    cin >> s;
    for (char &c: s) {
        counts[c - 'a']++;
    }

    permute("", s.size(), counts);
    cout << perms.size() << "\n";
    for (string &perm: perms) {
        cout << perm << "\n";
    }

    return 0;
}
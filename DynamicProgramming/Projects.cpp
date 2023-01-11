#include <bits/stdc++.h>

using namespace std;

struct Project {
    int start;
    int end;
    long long reward;

    bool operator <(const Project &other) const {
        return end < other.end;
    }

    bool operator ()(const int other) const {
        return end < other;
    }
};

struct ProjectsComparator {

    bool operator ()(Project left, int right) {
        return left.end < right;
    }

    bool operator()(int left, Project right) {
        return left < right.end;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a, b, c;
    cin >> n;

    vector<Project> projects(n + 1);
    vector<long long> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        projects[i] = {a, b, c};
    }

    sort(projects.begin(), projects.end());

    for (int i = 1; i <= n; i++) {
        long long dont_pick = dp[i - 1];

        int start = projects[i].start;
        auto prev_possible = lower_bound(projects.begin(), projects.end(),
                                         start, ProjectsComparator());
        long long pos = prev_possible - projects.begin();
        long long pick = dp[pos - 1] + projects[i].reward;

        dp[i] = max(dont_pick, pick);
    }

    cout << dp[n] << "\n";


    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct Matrix {
    int size;
    vector<vector<long long>> data;

    Matrix(int n) {
        size = n;
        data = vector<vector<long long>>(n, vector<long long>(n));

    }

    Matrix operator *(Matrix other) {
        Matrix product = Matrix(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    product.data[i][k] += (data[i][j] * other.data[j][k]) % MOD;
                    product.data[i][k] %= MOD;
                }
            }
        }

        return product;
    }

    void identity() {
        for (int i = 0; i < size; i++) {
            data[i][i] = 1;
        }
    }
};


Matrix matrix_exponent(Matrix &a, long long b) {
    Matrix result(a.size);
    result.identity();

    while (b > 0) {
        if (b & 1) result = (result * a);
        a = (a * a);
        b >>= 1;
    }

    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m, k, a, b;
    cin >> n >> m >> k;

    Matrix adjacency_mat(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjacency_mat.data[a - 1][b - 1]++;
    }

    Matrix kth_power = matrix_exponent(adjacency_mat, k);
    cout << kth_power.data[0][n - 1] << "\n";


    return 0;
}
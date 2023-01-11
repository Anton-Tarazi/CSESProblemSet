#include <bits/stdc++.h>

using namespace std;

constexpr long long INF = 2e18;

struct Matrix {
    int size;
    vector<vector<long long>> data;

    Matrix(int n) {
        size = n;
        data = vector<vector<long long>>(n, vector<long long>(n));

    }

    Matrix operator *(Matrix other) {
        Matrix product = get_inf(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    product.data[i][j] = min(product.data[i][j], data[i][k] + other.data[k][j]);
                }
            }
        }

        return product;
    }

    void set_diag(long long val) {
        for (int i = 0; i < size; i++)
            data[i][i] = val;
    }

    static Matrix get_inf(int n) {
        Matrix result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.data[i][j] = INF;
            }
        }
        return result;
    }

};


Matrix matrix_exponent(Matrix &a, long long b) {
    Matrix result = Matrix::get_inf(a.size);
    result.set_diag(0);


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
    long long c;
    cin >> n >> m >> k;

    Matrix adjacency_mat = Matrix::get_inf(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--, b--;
        adjacency_mat.data[a][b] = min(adjacency_mat.data[a][b], c);
    }

    Matrix kth_power = matrix_exponent(adjacency_mat, k);
    cout << (kth_power.data[0][n - 1] != INF ? kth_power.data[0][n - 1] : -1) << "\n";


    return 0;
}
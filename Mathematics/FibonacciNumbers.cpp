#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;


struct Matrix {
    long long data[2][2] = {{0, 0}, {0, 0}};
    Matrix operator *(Matrix other) {
        Matrix product = Matrix();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    product.data[i][k] += data[i][j] * other.data[j][k];
                    product.data[i][k] %= MOD;
                }
            }
        }

        return product;
    }
};


Matrix matrix_exponent(Matrix a, long long b) {
    Matrix result;
    result.data[0][0] = result.data[1][1] = 1;

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

    long long n;
    cin >> n;

    Matrix base;
    base.data[0][1] = base.data[1][0] = base.data[1][1] = 1;

    Matrix result = matrix_exponent(base, n);
    cout << result.data[0][1] << "\n";


    return 0;
}
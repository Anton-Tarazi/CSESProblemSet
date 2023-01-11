#include <bits/stdc++.h>

using namespace std;

#define DOTS 6
const int MOD = 1e9 + 7;


struct Matrix {

    long long data[DOTS][DOTS]{};

    Matrix operator *(Matrix &other) {
        Matrix product = Matrix();
        for (int i = 0; i < DOTS; i++) {
            for (int j = 0; j < DOTS; j++) {
                for (int k = 0; k < DOTS; k++) {
                    product.data[i][k] += data[i][j] * other.data[j][k];
                    product.data[i][k] %= MOD;
                }
            }
        }

        return product;
    }
};


Matrix matrix_exponent(Matrix &a, long long b) {
    Matrix result;
    for (int i = 0; i < DOTS; i++)
        result.data[i][i] = 1;

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
    base.data[0][1] = base.data[1][2] = base.data[2][3] =
            base.data[3][4] = base.data[4][5] = 1;
    base.data[5][0] = base.data[5][1] = base.data[5][2] =
            base.data[5][3] = base.data[5][4] = base.data[5][5] = 1;


    Matrix result = matrix_exponent(base, n);

    cout << result.data[DOTS - 1][DOTS - 1] << "\n";

    return 0;
}
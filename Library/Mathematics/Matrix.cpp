struct Matrix {
    int r, c;
    vvi mat;
    
    Matrix(int r, int c) : r(r), c(c) {
        mat.assign(r, vi(c, 0));
    }
    
    Matrix(int n) : r(n), c(n) {
        mat.assign(n, vi(n, 0));
        for (int i = 0; i < n; i++) mat[i][i] = 1;
    }
    
    Matrix operator*(const Matrix &other) const {
        Matrix res(r, other.c);
        for (int i = 0; i < r; i++) {
            for (int k = 0; k < c; k++) {
                if (mat[i][k] == 0) continue;
                for (int j = 0; j < other.c; j++)
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
            }
        }
        return res;
    }
    
    Matrix operator^(int p) const {
        Matrix res(r);
        Matrix base = *this;
        while (p > 0) {
            if (p & 1) res = res * base;
            base = base * base;
            p >>= 1;
        }
        return res;
    }
};

struct matrix {
    ll m[105][105];
};
matrix original;
matrix matrix_mul(ll sz, matrix a, matrix b) { ///sz = prev koto gula number er upor dependent
    matrix c;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            c.m[i][j] = 0;
        }
    }
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                c.m[i][j] = (c.m[i][j] + (a.m[i][k] * b.m[k][j]) % MOD) % MOD;
            }
        }
    }
    return c;
}
matrix matrix_bigmod(ll sz, matrix a, ll p) {
    if (p == 1) return a;
    matrix fin = matrix_bigmod(sz, a, p / 2);
    if (p % 2) return matrix_mul(sz, matrix_mul(sz, fin, fin), original);
    return matrix_mul(sz, fin, fin);
}
ll fib(ll n, ll mod) {
    if (n <= 1) return n;
    out(n)
    original.m[0][0] = 0;
    original.m[0][1] = 1;
    original.m[1][0] = 1;
    original.m[1][1] = 1;
    matrix res = matrix_bigmod(original, n - 1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%lld ", res.m[i][j]);
        }
        printf("\n");
    }
    return res.m[1][1];
}
/*
| 01000 |   | fn-m   |   | fn-m+1 |
| 00100 |   | fn-m+1 |   | fn-m+2 |
| ..... | X | ...... | = | ...... |
| 10001 |   | fn     |   | fn+1   |
*/
ll make_matrix(ll sz, ll n, ll mod) { ///fib[n]%mod where fib is dependent on prev sz terms
    ll j = 1;
    for (int i = 0; i < sz - 1; i++) {
        original.m[i][j] = 1;
        j++;
    }
    original.m[sz - 1][0] = 1;
    original.m[sz - 1][sz - 1] = 1;
    matrix res = matrix_bigmod(sz, original, n - 1);
    return res.m[sz-1][sz-1];
}

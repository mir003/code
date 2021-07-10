ll t, n, m;
vector<ll>A[510];
ll sum[510][510];
ll rsum(ll a, ll b, ll c, ll d) {
    if(c>n || d>m) return 0;
    ll res = sum[c][d];
    if (a - 1 >= 0) res -= sum[a - 1][d];
    if (b - 1 >= 0) res -= sum[c][b - 1];
    if (a - 1 >= 0 && b   - 1 >= 0) res += sum[a - 1][b - 1];
    return res;
}
int solve() {
    in2(n, m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ll x;
            in1(x);
            A[i].pb(x);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum[i][j] = A[i][j];
            if (i - 1 >= 0) sum[i][j] += sum[i - 1][j];
            if (j - 1 >= 0) sum[i][j] += sum[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0) sum[i][j] -= sum[i - 1][j - 1];
        }
    }
    return 0;
}

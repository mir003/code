const int N = 5010;
ll n, a[N], mem[N][N];
ll dp(ll l, ll r, ll del) {
    ll &ret = mem[l][r];
    if (l > r) return ret = 0;
    if (~ret) return ret;
    ll mn = MAX, id;
    for (int i = l; i <= r; i++) {
        if (a[i] < mn) {
            id = i;
            mn = a[i];
        }
    }
    return ret = min(r - l + 1, dp(l, id - 1, mn) + dp(id + 1, r, mn) + mn - del);
}
int main() {
    in1(n);
    for (int i = 0; i < n; i++) {
        in1(a[i]);
    }
    memn(mem);
    printf("%lld\n", dp(0, n - 1, 0));
    return 0;
}

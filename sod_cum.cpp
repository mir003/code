///cumulative SOD upto n=10e12///O(sqrt(n))
void solve() {
    ll n,ans = 0;
    ll i,j;

    scanf("%lld",&n);
    for (i = 1; i * i <= n; ++i) {
        j = n / i;
        ans += (i + j) * (j - i + 1) / 2;
        ans += i * (j - i);
    }
    printf("%lld\n", ans);
}

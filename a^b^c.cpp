///fermat's little theorem -> a^(b^c) % MOD
/// where MOD is a prime number
ll power2(ll a, ll b, ll c) {
    ll x = bigmod(b, c, MOD-1);
    return bigmod(a, x, MOD);
}
/*
*/

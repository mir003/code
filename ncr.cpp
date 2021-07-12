ll ncr(ll x, ll y) {
    f[0]=1;
    for(ll i=1; i<=N-10; i++)
        f[i]=(f[i-1]*i)%MOD;
    return (f[x]*bigmod((f[y]*f[x-y])%MOD, MOD-2, MOD))%MOD;
}

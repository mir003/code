ll ncr(ll n, ll r) {
    if(r==0 || r==n)
        return 1;
    if(mem[n][r])
        return mem[n][r];
    return mem[n][r]= ncr(n-1, r-1)+ncr(n-1, r);
}

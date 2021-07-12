ll fun() {
    in1(n);
    for (int i = 0; i < n; i++)
        in1(a[i]);
    ll g=a[n-1], res=0;
    for(int i=n-2; i>=0; i--) {
        ll k = lcm(a[i], g);
        g=__gcd(g, a[i]);
        res=__gcd(res, k);
    }
    return res;
}


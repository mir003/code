ll SOD(ll num) {
    primefactor(num);
    ll res=1;
    ll sz=pf.size();
    for(ll i=0; i<sz; i++) {
        ll a=prime[pf[i]];
        ll r=freq[pf[i]];
        res*=(round(pow(a,r+1)-1))/(a-1);
    }
    return res;
}

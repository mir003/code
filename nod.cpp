ll NOD(ll num) {
    primefactor(num);
    ll res=1;
    ll sz=pf.size();
    for(ll i=0; i<sz; i++) {
        res*=(freq[pf[i]]+1);
        freq[pf[i]]=0;
    }
    pf.clear();
    return res;
}

ll query(ll lo, ll hi, ll x) {
    ll mid=(lo+hi)/2;
    if(mid+1<last&&f(mid+1,x)>f(mid,x))
        return query(mid+1,hi,x);
    if(mid-1>=0&&f(mid-1,x)>f(mid,x))
        return query(lo,mid-1,x);
    return f(mid,x);
}
void ts() {
    ll high = 1e9, low = 0, m1, m2;
    for (int i = 0; i < 100; i++) {
        ll d = (high - low) / 3;
        m1 = low + d;
        m2 = m1+d;
        if (fun(m1)==fun(m2)) {
            low=m1;
            high=m2;
        }
        if (mss(m1) < mss(m2)) {
            high = m2;
        } else
            low = m1;
    }

}

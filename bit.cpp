ll sum(ll indx) {
    ll s=0;
    while(indx>0) {
        s+=tree[indx];
        indx-=(indx & -indx);
    }
    return s;
}
void update(ll indx, ll value) {
    while(indx<=n) {
        tree[indx]+=value;
        indx+=(indx & -indx);
    }
}

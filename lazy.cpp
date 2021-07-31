void build(ll l, ll r, ll pos) {
    if(l==r) {
        tree[pos]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(l, mid, 2*pos);
    build(mid+1, r, 2*pos+1);
    tree[pos]=tree[2*pos]+tree[2*pos+1];
    return;
}
void lazy(ll l, ll r, ll pos) {

    tree[pos]+=((r-l+1)*lz[pos]);
    if(l!=r) {
        lz[2*pos]+=lz[pos];
        lz[2*pos+1]+=lz[pos];
    }
    lz[pos]=0;

    return;
}
void update(ll l, ll r, ll pos, ll L, ll R, ll val) {
    lazy(l, r, pos);
    if(l>R || r<L)
        return;
    if(l>=L && r<=R) {
        tree[pos]+=(r-l+1)*val;
        if(l!=r) {
            lz[2*pos]+=val;
            lz[2*pos+1]+=val;
        }
        return;
    }
    ll mid=(l+r)/2;
    update(l, mid, 2*pos, L, R, val);
    update(mid+1, r, 2*pos+1, L, R, val);
    tree[pos]=tree[2*pos]+tree[2*pos+1];
    return;
}
ll query(ll l, ll r, ll pos, ll L, ll R) {
    lazy(l, r, pos);
    if(l>R || r<L)
        return 0;
    if(l>=L && r<=R)
        return tree[pos];
    ll mid=(l+r)/2;
    return query(l, mid, 2*pos, L, R)+query(mid+1, r, 2*pos+1, L, R);
}

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
void update(ll l, ll r, ll pos, ll L, ll R) { ///range increment by 1
    if(l>R || r<L)
        return;
    if(l>=L && r<=R) {
        tree[pos]+=(r-l+1);
        return;
    }
    ll mid=(l+r)/2;
    update(l, mid, 2*pos, L, R);
    update(mid+1, r, 2*pos+1, L, R);
    tree[pos]=tree[2*pos]+tree[2*pos+1];
    return;
}
ll query(ll l, ll r, ll pos, ll P) {
    if(l>P || r<P)
        return 0;
    if(l==r && l==P)
        return tree[pos];
    ll mid=(l+r)/2;
    return query(l, mid, 2*pos, P)+query(mid+1, r, 2*pos+1, P);
}
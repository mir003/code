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
void update(ll l, ll r, ll pos, ll P, ll val) { ///point update
    if(l>P || r<P)
        return;
    if(l==P && l==r) {
        tree[pos]+=val;
        return;
    }
    ll mid=(l+r)/2;
    update(l, mid, 2*pos, P, val);
    update(mid+1, r, 2*pos+1, P, val);
    tree[pos]=tree[2*pos]+tree[2*pos+1];
    return;
}
ll query(ll l, ll r, ll pos, ll L, ll R) {///range query
    if(l>R || r<L)
        return 0;
    if(l>=L && r<=R)
        return tree[pos];
    ll mid=(l+r)/2;
    return query(l, mid, 2*pos, P)+query(mid+1, r, 2*pos+1, P);
}

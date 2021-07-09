ll t, c, n, m, tree[2010][2010], a[510][510], len, I, J, S;
void seg_sum(ll l, ll r, ll pos, ll X) {
    tree[X][pos] = tree[2*X][pos]+tree[2*X+1][pos];
    if(l==r) {
        return;
    }
    ll mid=(l+r)/2;
    seg_sum(l, mid, 2*pos, X);
    seg_sum(mid+1, r, 2*pos+1, X);
}
void build(ll l, ll r, ll pos, ll POS, ll ROW) {
    if(l==r) {
        tree[POS][pos]=a[ROW][l];
        return;
    }
    ll mid=(l+r)/2;
    build(l, mid, 2*pos, POS, ROW);
    build(mid+1, r, 2*pos+1, POS, ROW);
    tree[POS][pos] = tree[POS][2*pos]+tree[POS][2*pos+1];
    return;
}
void build_main(ll l, ll r, ll pos) {
    if(l==r) {
        build(1, n, 1, pos, l);
        return;
    }
    ll mid=(l+r)/2;
    build_main(l, mid, 2*pos);
    build_main(mid+1, r, 2*pos+1);
    seg_sum(1, n, 1, pos);
}
ll query(ll l, ll r, ll pos, ll C1, ll C2, ll POS) {
    if(r<C1 || l>C2)
        return 0;
    if(l>=C1 && r<=C2) { ///segment valid
        return tree[POS][pos];
    }
    ll mid=(l+r)/2;
    return query(l, mid, 2*pos, C1, C2, POS) + query(mid+1, r, 2*pos+1, C1, C2, POS);
}
ll query_main(ll l, ll r, ll pos, ll R1, ll R2, ll C1, ll C2) {
    if(r<R1 || l>R2)
        return 0;
    if(l>=R1 && r<=R2) {
        return query(1, n, 1, C1, C2, pos);
    }
    ll mid=(l+r)/2;
    return query_main(l, mid, 2*pos, R1, R2, C1, C2)+query_main(mid+1, r, 2*pos+1, R1, R2, C1, C2);
}

ll avail, root[N],new_root,pre;

struct d {
    ll lc, rc, v;
};
d tree[20*N];

void update(ll l, ll r, ll pr, ll nr, ll pos, ll val) {
    if(l==r) {
        tree[nr].v=tree[pr].v+val;
        return;
    }
    ll mid= (l+r)/2;
    if(pos<=mid) { /// pos is inside l---mid
        tree[nr].rc=tree[pr].rc;
        tree[nr].lc=++avail;///new node
        update(l, mid, tree[pr].lc, tree[nr].lc, pos, val);
    } else {
        tree[nr].lc=tree[pr].lc;
        tree[nr].rc=++avail;///new node
        update(mid+1, r, tree[pr].rc, tree[nr].rc, pos, val);
    }
    tree[nr].v= tree[ tree[nr].lc ].v + tree[ tree[nr].rc ].v;
}
ll query(ll nr, ll l, ll r, ll L, ll R) {
    if(l>R || r<L)
        return 0;
    if(l>=L && r<=R)
        return tree[nr].v;
    ll mid=(l+r)/2;
    return query(tree[nr].lc, l, mid, L, R)+query(tree[nr].rc, mid+1, r, L, R);
}
void persistant(ll indx) {
    pre=root[sz];
    new_root=++avail;
    root[++sz]=new_root;
    update(1, n, pre, new_root, indx,1);

}

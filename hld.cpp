///HLD**************************************
vector<ll>adj[N];
ll n, m, q, par[N], lv[N], stsz[N], sc[N], node_head[N], new_pos, cost[N], indx[N], res[N], root=1;
ll tree[4 * N], lz[4 * N];

void lazy(ll l, ll r, ll pos) {
    if(lz[pos]==0) return;
    tree[pos] =  lz[pos];
    if (l != r) {
        lz[2 * pos] = lz[pos];
        lz[2 * pos + 1] = lz[pos];
    }
    lz[pos] = 0;
    return;
}
void update(ll l, ll r, ll pos, ll L, ll R, ll val) {
    lazy(l, r, pos);
    if (l > R || r < L)
        return;
    if (l >= L && r <= R) {
        tree[pos] = val;
        if (l != r) {
            lz[2 * pos] = val;
            lz[2 * pos + 1] = val;
        }
        return;
    }
    ll mid = (l + r) / 2;
    update(l, mid, 2 * pos, L, R, val);
    update(mid + 1, r, 2 * pos + 1, L, R, val);
    tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
    return;
}
ll query(ll l, ll r, ll pos, ll L, ll R) {
    lazy(l, r, pos);
    if (l > R || r < L)
        return 0;
    if (l >= L && r <= R)
        return tree[pos];
    ll mid = (l + r) / 2;
    return query(l, mid, 2 * pos, L, R) + query(mid + 1, r, 2 * pos + 1, L, R);
}
ll uc = 1;
pii range[N];
ll dfs(ll now, ll pre) { ///dfs(1,0)
    ll cnt = 1, sz = adj[now].size(), mx = 0, special = 0;
    for (int i = 0; i < sz; i++) {
        ll node = adj[now][i];
        if (node != pre) {
            lv[node] = lv[now] + 1;
            cnt += dfs(node, now);
            if (stsz[node] > mx) {
                mx = stsz[node];
                special = node;
            }
        }
    }
    sc[now] = special;
    return stsz[now] = cnt;
}
void dfs2(ll now, ll pre) {
    range[now].first = indx[now];
    // out(now)
    // out(range[now].first)
    range[now].second = indx[now];
    for (auto u : adj[now]) {
        if (u != pre) {
            dfs2(u, now);
            // out(u)
            range[now].second = max(range[now].second, range[u].second);
            // out(range[now].second)
        }
    }
    // out(range[now].first) out(range[now].second)
}

void HLD(ll pre, ll now, ll head) { ///HLD(1,1,1)
    node_head[now] = head;
    indx[now] = ++new_pos;
    par[now] = pre;
    //update(1, n, 1, new_pos, new_pos, 0);
    if (sc[now] != 0)
        HLD(now, sc[now], head);
    ll sz = adj[now].size();
    for (int i = 0; i < sz; i++) {
        ll node = adj[now][i];
        if (node != sc[now] && node != pre) {
            HLD(now, node, node);
        }
    }
}

void go_up(ll u, ll v, ll val) { ///update path
    // out(u) out(v)
    if (node_head[u] == node_head[v]) {
        // cout<<"h1"<<endl;
        (lv[u] < lv[v] ? update(1, n, 1, indx[u], indx[v], val) : update(1, n, 1, indx[v], indx[u], val));
        return;
    }
    if (lv[node_head[u]] > lv[node_head[v]]) {
        // cout<<"h2"<<endl;
        update(1, n, 1, indx[node_head[u]], indx[u], val);
        go_up(par[node_head[u]], v, val);
    } else {
        // cout<<"h3"<<endl;
        update(1, n, 1, indx[node_head[v]], indx[v], val);
        go_up(u, par[node_head[v]], val);
    }
}
int solve() {
    FAST
    cin >> n;
    for (int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(root, 0);
    HLD(0, root, root);
    dfs2(root, 0);
    // for (int i = 1; i <= n; i++) {
    //  cout << i << " " << indx[i] << " " << node_head[i] <<" "<<lv[i]<< endl;
    //  cout << range[i].first << " " << range[i].second << endl;
    // }
    cin >> m;
    while (m--) {
        ll f, x, val;
        cin >> f >> x;
        if (f == 1) {
            update(1, n, 1, range[x].first, range[x].second, 1);
        } else if(f==2) {
            // out(root);
            // out(x)
            go_up(root, x, -1);
        } else {
            ll res = query(1, n, 1, indx[x], indx[x]);
            if(res!=1) res=0;

            printf("%d\n", res);
        }
    }
    return 0;
}
/*
23
0 1 2 1 1 1 5 4 2 2 2 3 11 11 9 9 16 16 18 15 14 14 13
*/

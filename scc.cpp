ll t, n, m, cc;
ll vis[N];
vector<ll>adj[N], radj[N];
// if u->v and v->u then u,v connected
// dfs(radjaph) and dfs(trans radjaph), trans radjaph -> reversed edges
vector<int> order, component;

void dfs1 (int v) {
    vis[v] = 1;
    for (size_t i = 0; i < adj[v].size(); i++)
        if (!vis[ adj[v][i] ])
            dfs1 (adj[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    vis[v] = 1;
    component.push_back (v);
    for (size_t i = 0; i < radj[v].size(); i++)
        if (!vis[ radj[v][i] ])
            dfs2 (radj[v][i]);
}

int solve() {
    in1(t);
    while (t--) {
        ll res = 0;
        in2(n, m);
        for (int i = 0; i < m; i++) {
            ll u, v;
            in2(u, v);
            if (u != v) {
                adj[u].pb(v);
                radj[v].pb(u);
            }
        }
        memz(vis);
        order.clear();
        for (int i = 1; i <= n; i++)
            if (!vis[i]) dfs1 (i);
        memz(vis);
        for (int i = 0; i < n; i++) {
            int v = order[n - 1 - i];
            if (!vis[v]) {
                dfs2 (v);
                if ((ll)component.size() == 1) {
                    for (auto u : component) {
                        if (!adj[u].empty()) res++;
                    }
                }
                component.clear();
            }
        }
        TC(cc);
        printf("%lld\n", res);
        for(int i=1; i<=n; i++) {
            adj[i].clear();
            radj[i].clear();
        }
    }
    return 0;
}

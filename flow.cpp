<snippet>
	<content><![CDATA[
ll m, S, T, k, n, c, lv[N]; ///S = source, T= sink
struct edge {
    ll to, rev, flow, cap;
};
vector<edge>adj[N];
void add_edge(ll u, ll v, ll Cap) {
    edge a = {v, (int)adj[v].size(), 0, Cap};
    edge b = {u, (int)adj[u].size(), 0, 0};///if graph bidirectional then capacity=Cap in this line
    adj[u].pb(a);
    adj[v].pb(b);
}
ll send_flow(ll s, ll mn) { ///send_flow(S, MAX)
    if (s == T) return mn;
    for (auto &u : adj[s]) { /// u = s--> v
        ll v = u.to, Cap = u.cap - u.flow;
        if (lv[v] == lv[s] + 1 && Cap > 0) {
            ll Flow = send_flow(v, min(mn, Cap));
            if (Flow > 0) {
                u.flow += Flow;
                adj[v][u.rev].flow -= Flow;
                return Flow;
            }
        }
    }
    return 0;///executes when dead edge comes
}
bool make_level_graph() {
    queue<ll>q;
    q.push(S);
    memz(lv);
    lv[S] = 1;
    while (!q.empty()) {
        ll s = q.front();
        q.pop();
        for (auto u : adj[s]) {
            ll v = u.to;
            ll Cap = u.cap - u.flow;
            if (lv[v] == 0 && Cap > 0) {
                lv[v] = lv[s] + 1;
                q.push(v);
            }
        }
    }
    if (lv[T] == 0) return 0;
    return 1;
}
ll dinic()
{
    ll ret = 0;
    while (make_level_graph()) {
        while (ll max_flow = send_flow(S, MAX)) {
            ret += max_flow;
        }
    }
    return ret;
}

int solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll u, v, cap;
        cin >> u >> v >> cap;
        add_edge(u, v, cap);
    }
    S = 1;
    T = n;
    printf("%lld\n", dinic());

    return 0;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>flow</tabTrigger> 
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

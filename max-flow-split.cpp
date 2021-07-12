const ll N = 110;
ll t, n, m;
///MAX FLOW
ll S, T, k, c, lv[N], res, TC;///S = source, T= sink
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
bool make_level_graph() {
    queue<ll>q;
    q.push(S);
    memz(lv);
    lv[S]=1;
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        ll sz= adj[u].size();
        for(int i=0; i<sz; i++) {
            ll v = adj[u][i].to;
            ll Cap = adj[u][i].cap-adj[u][i].flow;
            if(lv[v]==0 && Cap>0) {
                lv[v]=lv[u]+1;
                q.push(v);
            }
        }
    }
    if(lv[T]==0)
        return 0;
    return 1;
}

ll send_flow(ll u, ll mn) { ///send_flow(S, MAX)
    if(u==T) {
        return mn;
    }
    ll sz= adj[u].size();
    for(int i=0; i<sz; i++) { /// adj[u][v] = u--> v
        ll v = adj[u][i].to, Cap = adj[u][i].cap-adj[u][i].flow;
        if(lv[v]==lv[u]+1 && Cap>0) {
            ll Flow = send_flow(v, min(mn, Cap));
            if(Flow>0) {
                adj[u][i].flow+=Flow;
                adj[v][adj[u][i].rev].flow-=Flow;
                return Flow;
            }
        }
    }
    return 0;///executes when dead edge comes
}
ll dinic() {
    res=0;
    while(make_level_graph()) {
        while(ll max_flow=send_flow(S, MAX)) {
            res+=max_flow;
        }
    }
    return res;
}
void Clear() {
    for(int i=1; i<=n; i++) {
        adj[i].clear();
        adj[n+i].clear();
    }
}
int main() {
    in1(t);
    while(t--) {
        in2(n,m);
        for(int i=2; i<=n-1; i++) {
            ll a;
            in1(a);
            add_edge(i, n+i,a);///split node
            add_edge(n+i, i,a); ///split node
        }
        add_edge(1, n+1, MAX);
        add_edge(n+1, 1, MAX);
        add_edge(n, n+n, MAX);
        add_edge(n+n, n, MAX);
        for(int i=0; i<m; i++) {
            ll u,v,cap;
            in2(u,v);
            in1(cap);
            add_edge(n+u, v, cap);
            add_edge(n+v, u, cap);
        }
        S = 1;
        T = n+n;
        tc(TC);
        printf("%lld\n", dinic());
        Clear();
    }
    return 0;
}

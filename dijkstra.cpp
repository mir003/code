ll n, m, par[N];
vector<ll>adj[N], cost[N];
ll d[N];
void dijkstra(ll s) {
    priority_queue<pii> pq;
    pq.push({0, s});
    for (int i = 1; i <= n; i++) {
        d[i] = MAX;
    }
    d[s] = 0;
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll c = -pq.top().first;
        pq.pop();
        if (d[u] < c) continue;
        ll sz = adj[u].size();
        for (int i = 0; i < sz; i++) {
            ll v = adj[u][i];
            if (d[v] > d[u] + cost[u][i]) {
                d[v] = d[u] + cost[u][i];
                par[v] = u;
                pq.push({ -d[v], v});
            }
        }
    }
}
void path(ll s) {///shortest path from 1 to n
    if (s == 0) return;
    path(par[s]);
    printf("%lld ", s);
}

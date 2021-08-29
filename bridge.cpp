ll tim, disc[N], low[N], vis[N], cl;
vector<ll>adj[N];
vector< pair<ll, ll> >res;
void bridge(ll s, ll pre){
    disc[s]=++tim;
    low[s]=tim;
    for(auto u:adj[s]){
        if(u!=pre){
            if(disc[u]==0){
                bridge(u, s);
            }
            low[s]=min(low[s], low[u]);
            if(low[u]>disc[s]){
                res.pb({u,v});
            }
        }
    }
}

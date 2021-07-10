ll t, c, n, m,res, x,y,a,root=1, low[10010], disc[10010];
vector<ll>adj[10010];
bool vis[10010];
bool ap[10010];
void articulation_point(ll u, ll par, ll child) {
    vis[u]=1;
    disc[u] = a++;
    low[u]=disc[u];
    ll sz=adj[u].size();
    for(int i=0; i<sz; i++) {
        ll v= adj[u][i];
        if(v!=par) {
            if(vis[v]) { ///back-edge
                low[u] = min(low[u], disc[v]);
            } else { ///dfs tree edge
                articulation_point(v, u, 0);
                low[u] = min(low[u], low[v]);
                child++;
                if(u==root) {
                    if( ap[u]==0 && child>1) {
                        ap[u]=1;
                        res++;
                    }
                } else if(ap[u]==0 && disc[u]<= low[v]) {
                    ap[u]=1;
                    res++;
                }
            }
        }
    }
}

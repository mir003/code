void dfs(ll s) {
    vis[s]=1;
    for(auto u:adj[s]) {
        if(vis[u]==0) {
            dfs(u);
        }
    }
}

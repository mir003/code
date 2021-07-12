vector<ll>adj[N];
ll mem[N][3][11], nxt[N], fb[N];
void dfs(ll s, ll par) {
    ll pre=0;
    for(auto u:adj[s]) {
        if(u!=par) {
            if(fb[s]==0)
                fb[s]=u;
            dfs(u, s);
            nxt[pre]=u;
            pre=u;
        }
    }
}
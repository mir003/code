const ll  N = 100010;
ll par[N], res[N], clev[N], dis[N][25], col[N], stsz[N], u, v, n, m;
vector<ll>adj[N];
bool taken[N];

ll subtree_size(ll now, ll pre) {
    ll ret=1;
    for(auto u:adj[now]) {
        if(u!=pre && taken[u]==0) {
            ret+=subtree_size(u, now);
        }
    }
    return stsz[now]=ret;
}

ll find_centroid(ll now, ll pre, ll sz) {
    int big=0;
    for(auto u:adj[now]) {
        if(u!=pre && taken[u]==0) {
            if(stsz[u]>sz)
                big=u;
        }
    }
    if(big)
        return find_centroid(big, now, sz);
    else
        return now;
}

void dist(ll now, ll pre, ll level) {
    for(auto u:adj[now]) {
        if(taken[u]==0 && u!=pre) {
            dis[u][level] = dis[now][level]+1;
            dist(u, now, level);
        }
    }
}
void C_D(ll pre, ll now) { ///C_D(0, 1);
    ll sub_sz = subtree_size(now, 0);
    ll centroid = find_centroid(now, 0, sub_sz/2);
    taken[centroid]=1;
    par[centroid]=pre;
    clev[centroid] = clev[pre]+1;
    dist(centroid, 0, clev[centroid]);
    for(auto u:adj[centroid]) {
        if(taken[u]==0) {
            C_D(centroid, u);
        }
    }
}
void paint(ll node, ll now) { ///paint(v,v);
    if(now==0)
        return;
    ll d = dis[node][clev[now]];
    if(res[now]>d) {
        res[now]=d;
    }
    paint(node, par[now]);
}
ll result(ll node, ll now, ll r) { ///result(v, par[v], res[v])
    if(now==0)
        return r;
    ll d = dis[node][clev[now]];
    if(res[now]+d<r)
        return result(node, par[now], res[now]+d);
    else
        return result(node, par[now], r);
}

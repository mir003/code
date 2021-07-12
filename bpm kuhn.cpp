ll a[M], b[M];
int lf[M], rt[M];
vector<int> adj[M];
bool vis[M];
bool kuhn(int x) {
    for (auto y : adj[x]) {
        if (vis[y])continue;
        vis[y] = 1;
        if (rt[y] == -1 || kuhn(rt[y])) {
            rt[y] = x;
            lf[x] = y;
            return true;
        }
    }
    return false;
}
int bpm(int n) {
    memn(lf);
    memn(rt);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memz(vis);
        if (kuhn(i))cnt++;
    }
    return cnt;
}
int solve() {

    int n, p, m, x, y;

    scanf("%d%d%d", &n, &m, &p);

    for (int i = 0; i < p; i++) {
        scanf("%d%d", &x, &y);
        adj[x].pb(n+y);
        adj[n+y].pb(x);

    }

    printf("%d\n", bpm(n));
    for (int i = 1; i <= n; i++) {
        if(lf[i]!=-1) printf("%d %d\n", i, lf[i]-n);
    }

    return 0;
}

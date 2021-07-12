vector< int > graph[N];
int n, m, match[N], dist[N];
int NIL = 0;
bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for (i = 1; i <= n; i++) {
        if (match[i] == NIL) {
            dist[i] = 0;
            Q.push(i);
        } else dist[i] = MAX;
    }
    dist[NIL] = MAX;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        if (u != NIL) {
            len = graph[u].size();
            for (i = 0; i < len; i++) {
                v = graph[u][i];
                if (dist[match[v]] == MAX) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL] != MAX);
}

bool dfs(int u) {
    int i, v, len;
    if (u != NIL) {
        len = graph[u].size();
        for (i = 0; i < len; i++) {
            v = graph[u][i];
            if (dist[match[v]] == dist[u] + 1) {
                if (dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = MAX;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in graph
    // All nodes on left and right should be distinct
    while (bfs())
        for (i = 1; i <= n; i++)
            if (match[i] == NIL && dfs(i))
                matching++;
    return matching;
}

void clear() {
    for(int j=0; j<M; j++) graph[j].clear();
    memz(match);
}

int solve() {

    int p, x, y;

    scanf("%d%d%d", &n, &m, &p);

    for(int i=0; i<p; i++) {
        scanf("%d%d", &x, &y);
        graph[x].pb(n + y);
        graph[n + y].pb(x);
    }

    printf("%d\n", hopcroft_karp());
    for(int i=1; i<=n; i++) {
        if(match[i]) {
            printf("%d %d\n", i, match[i]-n);
        }
    }

    return 0;
}

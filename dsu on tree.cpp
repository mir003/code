const ll N = 300010,  M = 2005;
const double eps = 1e-9;
const double pi = 4 * atan(1);
ll t, n, m;

ll sz[N], bigone[N], big[N], lvl[N];
vector<ll>qq;
vector < ll > adj[N], q[N];
deque<ll>res[N];

void find_size(ll pre, ll s, ll lv) {
    sz[s] = 1;
    lvl[s] = lv;
    ll mx = -1;
    bigone[s] = -1;
    for (auto u : adj[s]) {
        if (u == pre) continue;
        find_size(s, u, lv + 1);
        sz[s] += sz[u];
        if (sz[u] > mx) {
            bigone[s] = u;
            mx = sz[u];
        }
    }
}
ll frq[N];
void add(ll pre, ll s, ll val) {
    if (val == 1) {
        frq[lvl[s]]++;
    } else {
        frq[lvl[s]]--;
    }
    for (auto u : adj[s]) {
        if (u == pre || big[u]) continue;
        add(s, u, val);
    }
}

void dfs(ll pre, ll s, ll keep) {

    for (auto u : adj[s]) {
        if (u == pre || u == bigone[s]) continue;
        dfs(s, u, 0);
    }
    if (bigone[s] != -1) {
        dfs(s, bigone[s], 1);
        big[bigone[s]] = 1;
    }
    add(pre, s, 1);

    for(auto u:q[s]) {
        res[s].pb(frq[u]);
    }

    if (bigone[s] != -1) {
        big[bigone[s]] = 0; /// jodi keep == 0 hoy taile se bigchild soho sobai k muche dibe eksathe
    }
    if (keep == 0) {
        add(pre, s, -1);
    }
}

int solve() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    cin >> m;
    find_size(1, 1, 1);
    for (int i = 0; i < m; i++) {
        ll u, d;
        cin >> u >> d;
        qq.pb(u);
        q[u].pb(d+1);
    }
    dfs(1, 1, 0);
    for(auto u:qq) {
        ll ret = res[u].front();
        res[u].pop_front();
        printf("%lld\n", ret);
    }
    return 0;
}

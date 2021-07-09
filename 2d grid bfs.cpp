ll n, m, vis[1010][1010], lev[1010][1010], desx, desy, stx, sty;
string s[1010], k = "LRUD",res;
ll dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}; ///right, left, down, up
bool bfs(ll x, ll y) {
    queue<pii>q;
    q.push({x, y});
    vis[x][y] = 1;
    lev[x][y] = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (x == desx && y == desy) {
            return 1;
        }
        for (int i = 0; i < 4; i++) {
            ll nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && s[nx][ny] != '#' ) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
                lev[nx][ny] = lev[x][y] + 1;

            }
        }
    }
    return 0;
}
void path(ll x, ll y) {
    if(x==stx && y==sty) return;
    vis[x][y]=1;
    for (int i = 0; i < 4; i++) {
        ll nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && s[nx][ny] != '#'  && lev[nx][ny] == lev[x][y] - 1) {
            path(nx, ny);
            res.pb(k[i]);
            return;

        }
    }
}

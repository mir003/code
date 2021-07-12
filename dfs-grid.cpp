ll dx[]= {0,1,-1,0}, dy[]= {1, 0, 0, -1};
void dfs(ll x, ll y) {
    vis[x][y]=1;
    for(int i=0; i<4; i++) {
        ll nx=x+dx[i], ny=y+dy[i];
        if(nx> && nx<=n && ny>0 && ny>=m && vis[nx][ny]==0) {
            dfs(nx, ny);
        }
    }
}

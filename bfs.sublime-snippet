<snippet>
	<content><![CDATA[
ll n, lev[N];
vector<ll>adj[N];
void bfs(ll s) {
	queue<ll>q;
	q.push(s);
	lev[s] = 1;
	while (!q.empty()) {
		ll s = q.front();
		q.pop();
		for (auto u : adj[s]) {
			if (lev[u] == 0) {
				q.push(u);
				lev[u] = lev[s] + 1;
			}
		}
	}
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>bfs</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

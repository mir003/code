<snippet>
	<content><![CDATA[
ll t, n, m, vis[N], col[N], f;
vector<ll>adj[N], v[2];
void bicoloring(ll s) {
	vis[s] = 1;
	for (auto u : adj[s]) {
		if (vis[u] == 0) {
			col[u] = col[s] ^ 1;
			bicoloring(u);
			if (f) return;
		}
		else if (col[u] == col[s]) {
			f = 1;///impossible
			return;
		}
	}
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	 <tabTrigger>bicoloring</tabTrigger> 
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

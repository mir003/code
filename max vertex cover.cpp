<snippet>
	<content><![CDATA[
void dfs(ll s) {
	if (mem[1][s]) return;
	mem[1][s] = 1;
	for (auto u : adj[s]) {
		if (mem[1][u] == 0) {
			dfs(u);
			mem[1][s] += mem[0][u];
			mem[0][s] += max(mem[0][u], mem[1][u]);
		}
	}
	return;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>mvc</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

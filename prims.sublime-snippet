<snippet>
	<content><![CDATA[
ll n;
bool vis[N];
vector<ll>adj[N], cost[N];
struct info
{
	ll u, v, w;
};
vector<info>mst;
priority_queue<pair<ll, pair<ll, ll>>>pq;
void Prims() {
	for (int i = 0; i < n; i++) {
		vis[i] = 0;
	}
	int ok = 0;
	vis[0] = 1;
	int sz = adj[0].size();
	for (int i = 0; i < sz; i++) {
		pq.push({ -cost[0][i], {0, adj[0][i]}});
	}
	while (!pq.empty() && ok < n) {
		auto top = pq.top();
		pq.pop();
		ll u = top.second.first, v = top.second.second, w = -top.first;
		if (vis[v] == 0) {
			vis[v] = 1;
			mst.pb({u, v, w});
			ok++;
			int sz = adj[v].size();
			for (int i = 0; i < sz; i++) {
				pq.push({ -cost[v][i], {v, adj[v][i]}});
			}
		}
	}
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>mst_prims</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

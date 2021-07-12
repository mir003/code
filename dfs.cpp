<snippet>
	<content><![CDATA[
void dfs(ll s)
{
	vis[s]=1;
	for(auto u:adj[s])
	{
		if(vis[u]==0)
		{
			dfs(u);
		}
	}
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

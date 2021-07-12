<snippet>
	<content><![CDATA[
ll  lev[N], p[N][25];
vector<ll>adj[N];

void dfs(ll s, ll pre)
{
    for(auto u:adj[s])
    {
        if(u!=pre)
        {
            lev[u]=lev[s]+1;
            p[u][0]=s;
            dfs(u,s);
        }
    }
    return;
}
void make_sparse_table()///have to call in the main function
{
    dfs(1, 1);
    for(ll i=1; (1<<i)<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(p[j][i-1])
                p[j][i]=p[p[j][i-1]][i-1];
        }
    }
    return;
}
ll query(ll a, ll b)
{
    for(ll i=20; i>=0; i--)
    {
        if(lev[a]-(1<<i)>=lev[b])
            a=p[a][i];
    }
    for(ll i=20; i>=0; i--)
    {
        if(lev[b]-(1<<i)>=lev[a])
            b=p[b][i];
    }
    for(ll i=20; i>=0; i--)
        if(p[a][i]>0 && p[a][i]!=p[b][i])
        {
            a=p[a][i];
            b=p[b][i];
        }
    if(a==b)
        return a;
    return p[a][0];
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	 <tabTrigger>lca</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

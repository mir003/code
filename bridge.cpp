<snippet>
	<content><![CDATA[
ll tim, disc[N], low[N], vis[N], cl;
vector<ll>adj[N];
vector< pair<ll, ll> >res;
void bridge(ll u, ll par)///increase cl in every testcase
{
    vis[u]=cl;
    disc[u]= tim++;
    low[u]=disc[u];
    for(auto v:adj[u])
    {
        if(v!=par)
        {
            if(vis[v]==cl)///backage
            {
                low[u] = min(low[u], disc[v]);
            }
            else
            {
                bridge(v, u, 0);
                low[u] = min(low[u], low[v]);
                if(disc[u]<low[v] )
                {
                    if(u<v)
                        res.pb(make_pair(u,v));
                    else
                        res.pb(make_pair(v,u));
                }
            }
        }
    }
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>brigde</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

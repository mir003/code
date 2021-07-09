<snippet>
	<content><![CDATA[
///sibling dp
ll mem[102][102],cost[102][102], son[102], sib[102],n,k, TC;
vector<ll>adj[102];
void sibling(ll now, ll pre)
{
    bool flag=0;
    ll prev = -1;
    for(auto u:adj[now])
    {
        if(u!=pre)
        {
            if(flag)
            {
                sib[prev]=u;
            }
            else
            {
                flag=1;
                son[now]=u;
            }
            prev=u;
            sibling(u, now);
        }
    }
}
ll dp(ll pre, ll now, ll sum)
{
    if(now==0)
        return 0;
    ll &ret = mem[now][sum];
    if(~ret)
        return ret;
    ///new community
    ret = 1+dp(now, son[now], k)+dp(pre, sib[now], sum);
    ///add to old community
    ll rest = sum-cost[pre][now];
    for(ll i=0; i<=rest; i++)
    {
        ret = min(ret, dp(now, son[now], i)+dp(pre, sib[now], rest-i));
    }
    return ret;

}
int main()
{
    ll t;
    in1(t);
    while(t--)
    {
        memn(mem);
        memz(son);
        memz(sib);
        memz(cost);
        in2(n,k);
        for(int i=0; i<n-1; i++)
        {
            ll u,v,w;
            in2(u,v);
            in1(w);
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u][v]=w;
            cost[v][u]=w;
        }
        sibling(1, 1);
        cost[1][1]=1;
        printf("Case %lld: %lld\n", ++TC, 1+dp(1,son[1],k));
        for(int i=1; i<=n; i++)
            adj[i].clear();

    }
    return 0;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

<snippet>
	<content><![CDATA[
ll sum(ll indx)
{
    ll s=0;
    while(indx>0)
    {
        s+=tree[indx];
        indx-=(indx & -indx);
    }
    return s;
}
void update(ll indx, ll value)
{
    while(indx<=n)
    {
        tree[indx]+=value;
        indx+=(indx & -indx);
    }
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>bit</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

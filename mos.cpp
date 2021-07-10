<snippet>
	<content><![CDATA[
///always make a set for a query by deleting or adding elements to previous query's set
///square root decomposition, sort by bn-rt
///complexity O((N+Q) * SQRT(N))
struct info
{
    ll lt, rt, id, bn;
} q[M];
bool ac(info lhs, info rhs)
{
    if(lhs.bn==rhs.bn)
        return lhs.rt<rhs.rt;
    return lhs.bn<rhs.bn;
}
void mos()
{
    int i = 0, j = -1; ///q[]--> lt, rt, id, bn
    for (int ii = 0; ii < m; ii++)
    {
        ll l, r;
        l = q[ii].lt;
        r = q[ii].rt;
        while (j < r) ///right e add
        {
            in(++j);
        }
        while (j > r) ///right e delete
        {
            ex(j--);
        }
        while (i < l) ///left e add
        {
            ex(i++);
        }
        while (i > l) ///left e delete
        {
            in(--i);
        }
        res[q[ii].id] = sum;
    }
}
}]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	 <tabTrigger>mos</tabTrigger> 
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

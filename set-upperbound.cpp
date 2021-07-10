<snippet>
	<content><![CDATA[
ll set_upper_bound(ll val)///greater than val
{
    auto it = st.upper_bound(val);
    if(it==st.end())
    {
        return -1;
    }
    else return *it;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

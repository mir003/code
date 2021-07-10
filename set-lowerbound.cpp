<snippet>
	<content><![CDATA[
ll set_lower_bound(ll val)///less than val
{
    auto it = st.lower_bound(val);
    if(it==st.begin())
        return -1;
    else
    {
        it--;
        return *it;
    }
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

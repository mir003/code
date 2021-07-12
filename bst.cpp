<snippet>
	<content><![CDATA[
const ll N= 100010;
ll n,u,v,a[N];
unordered_map<ll,ll>par,lft,rgt;
set<ll>st;
void BST()
{
    in1(n);
    for(int i=0; i<n; i++)
    {
        in1(a[i]);
        if(i>0)
        {
            set<ll>::iterator it = st.upper_bound(a[i]);
            if(it==st.end() || lft[(*it)])
            {
                it--;
                rgt[*it]++;
            }
            else
            {
                lft[*it]++;
            }
            printf("%lld ", *it);
        }
        st.insert(a[i]);
    }

}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	 <tabTrigger>bst</tabTrigger> 
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

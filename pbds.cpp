<snippet>
	<content><![CDATA[
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<ll>,rb_tree_tag,tree_order_statistics_node_update>orderedSet;///less_equal/greater/greater_equal
orderedSet X;
*os.find_by_order(pos)///returns pointer of pos (o indexed)
os.order_of_key(val)///returns position of value of greater than value
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>
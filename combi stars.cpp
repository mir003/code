<snippet>
	<content><![CDATA[
///stars and bars
number of non decreasing m tpl from 1,2,..n are :: ncr(n+m-1,n)
sum( k tpl >=0) = n --> formula :: ncr(n+k-1, n)
sum( k tpl >0) = n --> formula :: ncr(n-1, k-1)
sum( k tpl >=0) <= n --> formula :: ncr(n+k, k)
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

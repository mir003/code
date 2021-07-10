<snippet>
	<content><![CDATA[
void seive()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i) {
            sod[j] += i;
        }
    }
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>sod-seive</tabTrigger> 
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

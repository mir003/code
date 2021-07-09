<snippet>
	<content><![CDATA[
///all pair GCD sum --> res[n]
void gcd_sum()
{
    eular_seive();
    for(int i=1; i<=N-10; i++)
    {
        for(int j=i; j<=N-10; j+=i)
        {
            calc[j]+=(e[j/i]*i);
        }
    }
    for(int i=1; i<=N-10; i++)
    {
        res[i]=res[i-1]+calc[i];
    }
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

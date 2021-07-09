<snippet>
	<content><![CDATA[
///coin change 1
ll t,tc, n, k, a[55],c[55], cur[10010], pre[10010];

int main()
{
    in1(t);
    while(t--)
    {
        memz(cur);
        memz(pre);
        cur[0]=1;
        pre[0]=1;
        in2(n,k);
        for(int i=0; i<n; i++)
            in1(a[i]);
        for(int i=0; i<n; i++)
            in1(c[i]);
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<=c[i]; j++)
            {
                ll val=(j*a[i]);
                for(int sum=val; sum<=k; sum++)
                {
                    cur[sum]=(cur[sum]+pre[sum-val])%MOD;
                }
            }
            for(int sum=1; sum<=k; sum++)
            {
                pre[sum]=cur[sum];
            }
        }
        TC(tc);
        printf("%lld\n", cur[k]);
    }
    return 0;
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

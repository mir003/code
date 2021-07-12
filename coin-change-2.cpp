<snippet>
	<content><![CDATA[
///coin change 2
const ll N=300010;
ll t,tc, n, k, a[110], mem[10005];

int main()
{
    in1(t);
    while(t--)
    {
        memz(mem);
        mem[0]=1;
        in2(n,k);
        for(int i=0;i<n;i++)
            in1(a[i]);
        for(int i=0;i<n;i++)
        {
            for(int sum=a[i];sum<=k;sum++)
            {
                mem[sum]=(mem[sum]+mem[sum-a[i]])%MOD;
            }
        }
        TC(tc);
        printf("%lld\n", mem[k]);
    }
    return 0;
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

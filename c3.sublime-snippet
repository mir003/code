<snippet>
	<content><![CDATA[
///coin change 3
///solution 1: using count of coins, similar to coin change 2
///cnt[] stores minimum number of coins of ith kind used to make the sum
ll t,tc, n, k, a[105], c[105], cnt[N];
bool mem[100005];

int main()
{
    in1(t);
    while(t--)
    {
        ll res=0;
        memz(mem);
        mem[0]=true;
        in2(n,k);
        for(int i=0; i<n; i++)
            in1(a[i]);
        for(int i=0; i<n; i++)
            in1(c[i]);
        for(int i=0;i<n;i++)
        {
            memz(cnt);
            for(int sum=a[i]; sum<=k; sum++)
            {
                if(mem[sum]==0 && mem[sum-a[i]] && cnt[sum-a[i]]+1<=c[i])
                {
                    mem[sum]=1;
                    cnt[sum]=cnt[sum-a[i]]+1;
                }
            }
        }
        for(int sum=1;sum<=k;sum++)
            res+=mem[sum];
        TC(tc);
        printf("%lld\n", res);
    }
    return 0;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

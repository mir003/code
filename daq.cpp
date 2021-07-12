<snippet>
	<content><![CDATA[
int n, m, a[N], cum[N];
int mem[2][N];
int cost(int x, int y)
{
    return ((cum[y] - cum[x - 1]) * (y - x + 1));
}
void daq(bool p, int l, int r, int optl, int optr)
{
    if (l > r)
    {
        return;
    }
    int mid = (l + r) / 2, opt = optl;
    int &ret = mem[p][mid];
    ret = MAX;
    for (int k = optl; k <= min(mid, optr); k++)
    {
        int val = (mem[p^1][k - 1] + cost(k, mid));
        if (ret > val)
        {
            opt = k;
            ret = val;
        }
    }
    daq(p, l, mid - 1, optl, opt);
    daq(p, mid + 1, r, opt, optr);
}
int solve()
{
    in2(n, m);
    for (int i = 1; i <= n; i++)
    {
        in1(a[i]);
        cum[i] = cum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        mem[0][i] = MAX;
    }
    for (int i = 1; i <= m; i++)
    {
        daq(i%2, 1, n, 1, n);
    }
    printf("%lld\n", mem[m % 2][n]);
    return 0;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	 <tabTrigger>daq</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet wiint trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

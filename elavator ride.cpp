<snippet>
	<content><![CDATA[
ll t, n, x, tc, a[25];
pii mem[(1LL << 20)];

int solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mem[0]={1,0};///first = min number of ride , second = min w of last ride
    for (int i = 1; i < (1LL << n); i++) {
        mem[i] = {MAX, MIN}; 
        for (int j = 0; j < n; j++) {
            if (i & (1LL << j)) {
                ll p = (i ^ (1LL << j));
                pii ret = mem[p];
                if (ret.second + a[j] <= x) {
                    ret.second+=a[j];
                }
                else{
                    ret.first++;
                    ret.second = min(ret.second, a[j]);
                }
                mem[i]=min(mem[i], ret);
            }
        }
    }
    printf("%lld\n", mem[(1LL<<n)-1].first);
    return 0;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	 <tabTrigger>ride</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

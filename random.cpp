<snippet>
	<content><![CDATA[
random_device rd;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());;
int solve() {
    while (m--) {
        ll l, r, res = 0;
        cin >> l >> r;
        for (int i = 0; i < 25; i++) {
            ll rr = (rng()+rng())%MOD;
            ll random = (rr % (r - l + 1)) + l;
            res = max(res, bs(random, r + 1) - bs(random, l));
        }
        // out(res)
        ll b = min(res, ((r - l + 1) - res));
        res = (res - b);
        if (res == 0) res = 1;
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

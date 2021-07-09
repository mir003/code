<snippet>
	<content><![CDATA[
const ll N = 300010;
ll t, n, a[N], f[N], m, k;
vector<pii>v;


int solve() {
	in1(t);
	while (t--) {
		in1(n);
		v.clear();
		for (int i = 0; i < n; i++) {
			ll l, r;
			in2(l, r);
			v.pb({l, -r});
		}
		sort(v.begin(), v.end());
		ll L = 0, R = 1, res = 0, tr=R;
		for (auto u : v) {
			out(R) out(tr)
			ll l = u.first, r = -u.second;
			if (l <= R) {
				tr = max(r, tr);
			}
			else{
				if(R<tr)
				res++;
				R=tr;
				if(l<=R)
				tr=max(r, R);
			}
		}
		res++;
		out(res)///minimum linear connecting segments.

	}
	return 0;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	 <tabTrigger>linear_connecting_seg</tabTrigger> 
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

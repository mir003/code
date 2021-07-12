<snippet>
	<content><![CDATA[
// ax^2+bx+c=0, int x possible kina
bool degree(ll a, ll b, ll c) {
	ll y = b * b - 4 * a * c;
	ll sy = sqrt(y);
	if (sy * sy == y) {
		if ((sy - b) % (2 * a) == 0 || (-sy - b) % (2 * a) == 0) {
			return 1;
		}
	}
	return 0;
} 
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>degree</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

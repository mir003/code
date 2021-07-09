<snippet>
	<content><![CDATA[
/*in the name of Allah the most beneficent the most merciful.*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 1e18
#define MIN -1e18
#define MOD 1000000007
//#define mod2 20071027
//#define MOD 998244353
// #define base 100001
//#define mod 1000074259
#define endl "\n"
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define TC(c) printf("Case #%lld: ", ++c)
#define out(x) cout << #x << " -> " << x << endl;
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE   freopen("input.txt", "r", stdin);  freopen("out.txt", "w", stdout);
using namespace std;
const int N = 5010;
ll n, a[N], mem[N][N];
ll dp(ll l, ll r, ll del) {
	ll &ret = mem[l][r];
	if (l > r) return ret = 0;
	if (~ret) return ret;
	ll mn = MAX, id;
	for (int i = l; i <= r; i++) {
		if (a[i] < mn) {
			id = i;
			mn = a[i];
		}
	}
	return ret = min(r - l + 1, dp(l, id - 1, mn) + dp(id + 1, r, mn) + mn - del);
}
int solve() {
	in1(n);
	for (int i = 0; i < n; i++) {
		in1(a[i]);
	}
	memn(mem);
	printf("%lld\n", dp(0, n - 1, 0));
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return solve();
}


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	 <tabTrigger>dq</tabTrigger> 
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

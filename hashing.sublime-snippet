<snippet>
	<content><![CDATA[
#define mod 1000074259 100003  100019
#define base 139
ll hashing()
{
    ll sum=0;
    for(ll i=0; i<sz; i++)
    {
        sum=(sum+(p[i]*s[i])%mod)%mod;
    }
    return sum;
}
ll add_left(ll pos, ll hv)
{
    return ((s[pos]+hv)*31)%mod;
}
ll add_right(ll pos, ll hv, ll len)
{
    return ((s[pos]*p[len])+hv)%mod;
}
ll del_left(ll f, ll pos, ll hv)
{
    ll ret = ((hv - s[f][pos]) * bb) % MOD;
    if (ret < 0) ret += MOD;
    return ret;
}
ll rhashing(ll f, ll sz, ll len)
{
    ll sum = 0;
    for (ll i = len - 1, j = 0; j < sz; i--, j++)
    {
        sum = (sum + (p[j] * s[f][i]) % MOD) % MOD;
    }
    return sum;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
    <tabTrigger>hash</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

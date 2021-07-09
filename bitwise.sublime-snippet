<snippet>
	<content><![CDATA[
///bitwise operation
ll ison(ll val, ll pos)
{
    return val&(1LL<<pos);
}
ll _not(ll val, ll bitsz)
{
    return (val^((1LL<<bitsz)-1));
}
ll biton(ll val, ll pos)
{
    return (val|(1LL<<pos));
}
ll bitoff(ll val, ll pos)
{
    return (val^(1LL<<pos));
}
ll count(ll val)
{
    ll ret=0;
    for(int pos=0; pos<32; pos++)
    {
        if(val&(1LL<<pos))
            ret++;
    }
    return ret;
}
ll flip_bit(ll num)
{
    ll dig = log2(num)+1, p=1, ret=0;
    for(int i=0;i<dig;i++)
    {
        if(!(num&(1LL<<i))) ret+=p;
        p*=2;
    }
    return ret;
}
ll msb(ll val) {
    return 64 - __builtin_clzll(val) - 1;
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>bitwise</tabTrigger> 
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

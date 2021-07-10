<snippet>
	<content><![CDATA[
///Ax+By=C
void fun(ll A, ll B, ll C, ll &x, ll &y)///result is in x, y
{
    ll gcd = __gcd(A, B);
    ll a=A/gcd;
    ll b=B/gcd;
    if(C%gcd)
    {
        printf("No solution exists.");
    }
    ll c=C/gcd;
    if(__gcd(a,b)==-1)
    {
        a*=-1;
        b*=-1;
        c*=-1;
    }
    ll x, y;
    ll g = extended_euclid(a, b, x,y);
    x*=c;
    y*=c;
}]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>ax+by=c</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

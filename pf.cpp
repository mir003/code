<snippet>
	<content><![CDATA[
vector<ll>pf;
ll freq[100010];///1<=num<=100010
void primefactor(ll num)
{
    seive();/// run only once in main function
    for(ll i=0; prime[i]*prime[i]<=num; i++)
    {
        if(num%prime[i]==0)
        {
            pf.pb(prime[i]);
            while(num%prime[i]==0)
            {
                num/=prime[i];
                freq[prime[i]]++;
            }
        }
    }
    if(num!=1)
    {
        pf.pb(num);
        freq[num]++;
    }
    return;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

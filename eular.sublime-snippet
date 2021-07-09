<snippet>
	<content><![CDATA[
///phi[p^a] = p^a - p^(a-1)
///phi[p1^a1 * p2^a2] = phi[p1^a1] * phi[p2^a2]
ll e[N],n, res[N];
int prime[79000];
bool is_comp[N];
void eular_seive()///e[i] = number of coprimes <= i
{
    ll sz=0;
    for(int i=2; i<=N-10; i++)
    {
        if(!is_comp[i])
        {
            e[i]=i-1;
            prime[sz]=i;
            sz++;
        }
        for(int j=0; j<sz && i*prime[j]<=N-10 ; j++)
        {
            is_comp[i*prime[j]]=1;
            if(i%prime[j])
            {
                e[i*prime[j]]=e[i]*e[prime[j]];
            }
            else
            {
                e[i*prime[j]]=prime[j]*e[i];
                break;
            }
        }
    }
    e[1]=1;
    ///sum(lcm(i,n))=(n*(res[n]+1))/2) where i=(1-n)
    for(ll i=1; i<=N-10; i++)
        for(ll j=i; j<=N-10; j+=i)
        {
            res[j]+=(i*e[i]);
        }
    ///sum of coprimes < n = (n*e[n])/2
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

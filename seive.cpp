<snippet>
	<content><![CDATA[
vector<ll>prime;
bool is_comp[N];
void seive()
{
    is_comp[0]=1;
    is_comp[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!is_comp[i])
            prime.pb(i);
        ll sz=prime.size();
        for(int j=0; j<sz && i*prime[j]<N ; j++)
        {
            is_comp[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>seive</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

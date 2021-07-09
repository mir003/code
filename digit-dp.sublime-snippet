<snippet>
	<content><![CDATA[
///sum of range, mod=998244353, where number of distinct digits<=k***********
pair<ll, ll> digitdp(ll pos,bool first,bool small, ll digit, ll mask)
{
    ll dis=0;
    for(int i=0; i<10; i++)
        if(mask&(1<<i))
            dis++;
    if(dis>k) return {0, 0};
    if(pos>=n) return {1, digit};
    if(mem[pos][first][small][digit][mask].second!=-1) return mem[pos][first][small][digit][mask];
    ll to=9;
    if(!small) to=s[pos]-'0';
    ll ret=0, valid=0;
    pair<ll, ll>tmp;
    for(int i=0; i<=to; i++)
    {
        if(i==0) tmp=digitdp(pos+1, first, small | (i<(s[pos]-'0')?1:0), i, first?mask:(mask|(1<<i)));
        else tmp=digitdp(pos+1, 0, small | (i<(s[pos]-'0')?1:0), i, mask|(1<<i));
        ret = (ret+ (tmp.first*((digit*p[n-pos])%MOD)%MOD) + tmp.second)%MOD;
        valid= (valid+tmp.first)%MOD;
    }
    return mem[pos][first][small][digit][mask]= {valid, ret};
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

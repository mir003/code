<snippet>
	<content><![CDATA[
///heavy-light tricks****************************************
ll n, m, q, a[100010], heavy_xtr_val[400], heavy_set_val[400],szz,hsz,x,v;
vector<int>st[100005];
vector<int>indx[100010];
vector<int>heavyset;
vector<int>lightset;
int intersect[400][100010];///heavy, light/heavy
int setmap[100010], h;
void make_intersection_array()
{
    szz = hsz;
    for(int i=0; i<szz; i++)
    {
        ll setnum = heavyset[i];
        ll sz= st[setnum].size();
        for(int j=0; j<sz; j++)
        {
            x = st[setnum][j];
            heavy_xtr_val[setmap[setnum]]+=a[x];
            ll insz= indx[x].size();
            for(int k=0; k<insz; k++)
            {
                if(indx[x][k]!=setnum)
                {
                    intersect[setmap[setnum]][setmap[indx[x][k]]]++;
                }
            }
        }
    }
}
void main_array_update()
{
    ll sz=st[x].size();
    for(int i=0; i<sz; i++)
    {
        a[st[x][i]]+=v;
    }
}
void heavy_xtraa_update()
{
    ll szz= hsz;
    for(int i=0; i<szz; i++)
    {
        heavy_xtr_val[setmap[heavyset[i]]]+=(v*intersect[setmap[heavyset[i]]][setmap[x]]);
    }
}
void update_light()
{
    main_array_update();
    heavy_xtraa_update();
}
void update_heavy()
{
    ll szz= hsz;
    for(int i=0; i<szz; i++)
    {
        if(heavyset[i]==x)
            heavy_set_val[setmap[heavyset[i]]]+=v;
        else
            heavy_xtr_val[setmap[heavyset[i]]]+=(v*intersect[setmap[heavyset[i]]][setmap[x]]);
    }
}
ll sum_heavy()
{
    ll  sz=st[x].size();
    return (heavy_set_val[setmap[x]]*sz)+heavy_xtr_val[setmap[x]];
}
ll sum_light()
{
    ll sum=0, sz=st[x].size();
    for(int i=0; i<sz; i++)
        sum+=a[st[x][i]];
    ll szz= heavyset.size();
    for(int i=0; i<szz; i++)
    {
        sum+=(intersect[setmap[heavyset[i]]][setmap[x]]*heavy_set_val[setmap[heavyset[i]]]);
    }
    return sum;
}
int main()
{
    in3(n, m, q);
    for(int i=1; i<=n; i++)
        in1(a[i]);
    ll sn=sqrt(n);
    for(int i=1; i<=m; i++)
    {
        ll sz;
        in1(sz);
        if(sz<=sn)
        {
            lightset.pb(i);
        }
        else
        {
            heavyset.pb(i);
            setmap[i]=++h;
        }
        for(int j=0; j<sz; j++)
        {
            in1(x);
            st[i].pb(x);
            indx[x].pb(i);
        }
    }
    ll szz=lightset.size();
    for(int i=0; i<szz; i++)
        setmap[lightset[i]]=++h;
    hsz=heavyset.size();
    make_intersection_array();
    while(q--)
    {
        getchar();
        char ch=getchar();
        if(ch=='?')
        {
            in1(x);
            ll sz=st[x].size();
            if(sz<=sn)
                printf("%lld\n", sum_light());
            else
                printf("%lld\n", sum_heavy());
        }
        else
        {
            in2(x,v);
            ll sz=st[x].size();
            if(sz>sn)///heavy
            {
                update_heavy();
            }
            else///light
            {
                update_light();
            }
        }
    }
    return 0;
}]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

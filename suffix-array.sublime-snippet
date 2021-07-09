<snippet>
	<content><![CDATA[
const int N= 10005;
struct info
{
    ll indx, tup[2];///indx --> suffix starts from here
    bool operator < (const info &a) const
    {
        return (tup[0]!=a.tup[0]) ? (tup[0]<a.tup[0]) : (tup[1]<a.tup[1]);
    }
} a[N];
ll Rank[18][N], step;
string s;
void build_suffix_array()
{
    ll n= s.length(), jump;
    for(int i=0; i<n; i++)
    {
        Rank[0][i]=s[i];
        memz(a[i].tup);
    }
    for(step=1, jump=1; jump<=n; step++, jump<<=1)
    {
        for(int i=0; i<n; i++)
        {
            a[i].indx=i;
            a[i].tup[0]=Rank[step-1][i];
            a[i].tup[1]= (i+jump)<n ? Rank[step-1][i+jump]:-1;
        }
        sort(a, a+n);
        Rank[step][a[0].indx]=0;
        for(int i=1; i<n; i++)
        {
            Rank[step][a[i].indx] = (a[i].tup[0]==a[i-1].tup[0] && a[i].tup[1]==a[i-1].tup[1]) ? Rank[step][a[i-1].indx] : i;
        }
    }
}
ll LCP[N];
void build_LCP_array()
{
    build_suffix_array();
    LCP[0]=0;
    ll n= s.length();
    for(int i=1; i<n; i++)
    {
        ll id1= a[i-1].indx;
        ll id2= a[i].indx;
        LCP[i]=0;
        for(int j=step-1; j>=0 && id1<n && id2<n; j--)
        {
            if(Rank[j][id1]==Rank[j][id2])
            {
                LCP[i]+=(1<<j);
                id1+=(1<<j);
                id2+= (1<<j);
            }
        }
    }
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

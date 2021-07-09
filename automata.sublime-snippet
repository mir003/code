<snippet>
	<content><![CDATA[
const ll N = 100005;
struct state
{
    ll len, link,count;
    bool isclone;
    map<char,ll>next;
};
state st[2*N];
ll sz, last,t,TC;
bool terminal[2*N];
vector<ll>lens[N];
void initialize()
{
    last=0;
    st[0].len=0;
    st[0].link=-1;
    sz=1;
}
void automata(char s[])
{
    initialize();
    ll n = strlen(s);
    for(ll i=0; i<n; i++)
    {
        char c = s[i];
        ll cur = sz++;
        st[cur].len= st[last].len+1;
        ll p;
        for(p=last; p!=-1 && !st[p].next[c]; p=st[p].link)
            st[p].next[c]=cur;
        if(p==-1)
            st[cur].link=0;
        else
        {
            ll q = st[p].next[c];
            if(st[p].len+1==st[q].len)
                st[cur].link=q;
            else
            {
                ///make clone of q
                ll clone = sz++;
                st[clone].isclone=1;
                st[clone].len=st[p].len+1;
                lens[st[clone].len].pb(clone);
                st[clone].next=st[q].next;
                st[clone].link=st[q].link;
                for(; p!=-1 && st[p].next[c]==q; p=st[p].link)
                    st[p].next[c]=clone;
                st[q].link=st[cur].link=clone;
            }
        }
        st[cur].count=1;///non-clone count=1
        lens[st[cur].len].pb(cur);
        last = cur;
    }
}
char a[N],b[N];
void make_terminals()
{
    for(ll p=last; p!=-1; p=st[p].link)
        terminal[p]=1;
}
void pref_suf_occurance()///res vector (prefex pos, occurance)
{
    vector<pair<ll,ll>>res;
    automata(a);
    ll n=strlen(a);
    for(ll i=n; i>0; i--)
    {
        ll szz= lens[i].size();
        for(int j=0; j<szz; j++)
        {
            ll cur = lens[i][j];
            st[st[cur].link].count+=st[cur].count;
        }
    }
    make_terminals();
    ll p=0;
    for(ll i=0; i<n; i++)
    {
        p=st[p].next[a[i]];
        if(terminal[p])
        {
            res.pb({i+1, st[p].count});
        }
    }
    n = res.size();
    printf("%d\n",n);
    for(int i=0; i<n; i++)
        printf("%d %d\n",res[i].first, res[i].second);
}
ll occurance(char a[],char b[])///occurance of b in a
{
    automata(a);
    ll n=strlen(a),p=0;
    for(ll i=n; i>0; i--)
    {
        ll szz= lens[i].size();
        for(int j=0; j<szz; j++)
        {
            ll cur = lens[i][j];
            st[st[cur].link].count+=st[cur].count;
        }
    }
    n=strlen(b);
    for(ll i=0; i<n; i++)
    {
        p=st[p].next[b[i]];
        if(!p) return 0;
    }
    return st[p].count;
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>automata</tabTrigger> 
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

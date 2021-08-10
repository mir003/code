/*Only those who endure patiently will be given their reward without limit.*/
#include<bits/stdc++.h>
#define ll long long///never change it to int -_-
#define pb push_back
#define MAX 2e18
#define MIN -2e18
#define MAXi 1e9
#define MINi -1e9
#define MOD 1000000007
///#define mod2 20071027
//#define MOD 998244353
#define base 139
///#define MOD 1000074259
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define in1i(a) scanf("%d", &a)
#define in2i(a, b) scanf("%d%d", &a, &b)
#define TC(c) printf("Case #%lld: ", ++c)
#define out(x) cout << #x << " -> " << x << endl;
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define pi4 pair<pii, pii>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE   freopen("input.txt", "r", stdin);  freopen("out.txt", "w", stdout);
#define coutd cout<<fixed<<setprecision(10)//coutd<<res<<endl;
using namespace std;
const ll N = 800005, M = 105;
ll n, m,par[N],vis[N], mem[N];
vector<ll>v;
vector<pii>in[N];
pair<ll, ll> tree[3*N],lz[3*N];
map<ll, ll>mp;
void lazy(ll l, ll r, ll pos) {
    if(lz[pos].first!=0) {
        if(tree[pos]<lz[pos])
            tree[pos]=lz[pos];
        if(l!=r) {
            lz[2*pos]=max(lz[2*pos], lz[pos]);
            lz[2*pos+1]=max(lz[2*pos+1],lz[pos]);
        }
    }
    lz[pos]= {0, 0};
    return;
}
void update(ll l, ll r, ll pos, ll L, ll R, pii val) {
    lazy(l, r, pos);
    if(l>R || r<L)
        return;
    if(l>=L && r<=R) {
        if(tree[pos]<val) {
            tree[pos]=val;
        }
        if(l!=r) {
            lz[2*pos]=max(lz[2*pos], val);
            lz[2*pos+1]=max(lz[2*pos+1],val);
        }
        return;
    }
    ll mid=(l+r)/2;
    update(l, mid, 2*pos, L, R, val);
    update(mid+1, r, 2*pos+1, L, R, val);
    tree[pos]=max(tree[2*pos],tree[2*pos+1]);
    return;
}
pair<ll,ll> query(ll l, ll r, ll pos, ll L, ll R) {
    lazy(l, r, pos);
    if(l>R || r<L)
        return {0, 0};
    if(l>=L && r<=R)
        return tree[pos];
    ll mid=(l+r)/2;
    return max(query(l, mid, 2*pos, L, R),query(mid+1, r, 2*pos+1, L, R));
}

int main() {
    FAST
    cin>>n>>m;
    for(int i=1; i<=m; i++) {
        ll l, r, k;
        cin>>k>>l>>r;
        in[k].pb({l,r});
        v.pb(l);
        v.pb(r);
    }
    sort(v.begin(), v.end());
    mp[v[0]]=1;
    ll c=1,sz=v.size();
    for(int i=1; i<sz; i++) {
        if(v[i-1]!=v[i]) {
            c++;
            mp[v[i]]=c;
        }
    }
    ll res=0, id=0;
    for(int i=1; i<=n; i++) {
        ll pre = 0;
        for(auto u:in[i]) {
            ll l = mp[u.first], r = mp[u.second];
            pii q = query(1, c, 1, l, r);
            if(q.second==0) {
                mem[i]=max(mem[i],1LL);
            } else {
                if(q.first+1>mem[i]) {
                    mem[i]=max(q.first+1, mem[i]);
                    pre=q.second;
                }
            }
        }
        for(auto u:in[i]) {
            ll l = mp[u.first], r = mp[u.second];
            update(1, c, 1, l, r, {mem[i], i});
        }
        if(mem[i]>res) {
            res=mem[i];
            id=i;
        }
        par[i]=pre;
    }
    while(id!=0) {
        vis[id]=1;
        id=par[id];
    }
    cout<<n-res<<endl;
    for(int i=1; i<=n; i++) {
        if(vis[i]==0) cout<<i<<" ";
    }

    return 0;
}
/*
3 4
1 2 3
2 3 6
3 4 8
1 7 9
*/

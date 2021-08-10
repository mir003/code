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
const ll N = 100005, M = 105;
ll t, n, m,mem[N][M][2], u, v, w,stsz[N],tc, tf;
vector<ll>adj[N],cost[N];
ll dfs(ll s, ll pre) {
    ll ret=1;
    for(auto u:adj[s]) {
        if(u!=pre) {
            ret+=1+dfs(u, s);
        }
    }
    return stsz[s]=ret;
}
ll dp(ll s, ll pre, ll k, ll z) {
    cout<<s<<" "<<pre<<" "<<k<<endl;
    ll &ret = mem[s][k][1], sz=adj[s].size();
    if(ret<MAX) return ret;
    if(k==0 || stsz[s]==1) {
        if(stsz[s]==1) tf++;
        return ret=0;
    }
    for(int ii=0; ii<sz; ii++) {
        ll zz = z^1;
        u =adj[s][ii], w=cost[s][ii];
        if(u!=pre) {
            ll mn =MAX;
            for(int i=1; i<=min(k, stsz[u]); i++) {
                ret = min(ret, (w*i*(m-i))+dp(u, s, i, )+mem[s][k-i][0]);
                for(int j=0; j<=min(tf,m); j++) {
                    mem[]
                }
            }
            ret=min(ret, mn);
            for(int i=1; i<=min(k, stsz[u]); i++) {
                mem[s][i]=(w*i*(m-i))+mem[u][i];
            }
        }
    }
    return ret;
}
int main() {
    cin>>t;
    while(t--) {
        tc++;
        tf=0;
        cin>>n>>m;
        for(int i=0; i<n-1; i++) {
            cin>>u>>v>>w;
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                mem[i][j]=MAX;
            }
        }
        dfs(1, 1);
        cout<<"OK"<<endl;
        cout<<"Case #"<<tc<<": "<<dp(1, 1, m)<<endl;
        for(int i=1; i<=n; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
/*
1
4 2
1 2 2
1 3 3
1 4 4
*/

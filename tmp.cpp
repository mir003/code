/*Only those who endure patiently will be given their reward without limit.*/
#include<bits/stdc++.h>
#define ll long long///never change it to int -_-
#define pb push_back
#define MAX 2e17
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
const ll N = 300005, M = 1005;
ll t, n, m;
vector<ll>adj[N], cost[N];
ll d[N];
void dijkstra(ll s) {
    priority_queue<pii> pq;
    pq.push({0, s});
    for (int i = 1; i <= n; i++) {
        d[i] = MAX;
    }
    d[s] = 0;
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll c = -pq.top().first;
        pq.pop();
        if (d[u] < c) continue;
        ll sz = adj[u].size();
        for (int i = 0; i < sz; i++) {
            ll v = adj[u][i];
            if (d[v] > d[u] + cost[u][i]) {
                d[v] = d[u] + cost[u][i];
                pq.push({ -d[v], v});
            }
        }
    }
}
int main() {
    FAST
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll u, v, w;
        cin>>u>v>>w;
        adj[u].pb(v);
        adj[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
    for(int i=1;i<=n;i++){
        cout<<
    }
    return 0;
}
/*

*/

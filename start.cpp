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
vector<ll>adj[N];
ll n, m, q, par[N], lv[N], stsz[N], sc[N], node_head[N], new_pos, cost[N], indx[N],in[N], root=1;
ll tree[4 * N], lz[4 * N];

//void lazy(ll l, ll r, ll pos) {
//    if(lz[pos]==0) return;
//    tree[pos] +=  (r-l+1)*lz[pos];
//    if (l != r) {
//        lz[2 * pos] += lz[pos];
//        lz[2 * pos + 1] += lz[pos];
//    }
//    lz[pos] = 0;
//    return;
//}
void update(ll l, ll r, ll pos, ll L, ll R, ll val) {
//    lazy(l, r, pos);
    if (l > R || r < L)
        return;
    if (l >= L && r <= R) {
        tree[pos] ^= 1;
//        if (l != r) {
//            lz[2 * pos] += val;
//            lz[2 * pos + 1] += val;
//        }
        return;
    }
    ll mid = (l + r) / 2;
    update(l, mid, 2 * pos, L, R, val);
    update(mid + 1, r, 2 * pos + 1, L, R, val);
    tree[pos] = tree[2 * pos]+tree[2 * pos + 1];
    return;
}
ll query(ll l, ll r, ll pos, ll L, ll R, ll val) {
//    lazy(l, r, pos);
//    if (l > R || r < L)
//        return 0;
    if (l==r) {
        if(tree[pos]==val) return l;
        return MAX;
    }
    ll mid = (l + r) / 2;
    if(tree[2*pos]>=val) {
        return query(l, mid, 2 * pos, L, R, val);
    }
    return query(mid + 1, r, 2 * pos + 1, L, R, val-tree[2*pos]);
}
ll dfs(ll now, ll pre) { ///dfs(1,0)
    ll cnt = 1, sz = adj[now].size(), mx = 0, special = 0;
    for (auto node:adj[now]) {
        if (node != pre) {
            lv[node] = lv[now] + 1;
            cnt += dfs(node, now);
            if (stsz[node] > mx) {
                mx = stsz[node];
                special = node;
            }
        }
    }
    sc[now] = special;
    return stsz[now] = cnt;
}
void HLD(ll pre, ll now, ll head) { ///HLD(1,1,1)
    node_head[now] = head;
    indx[now] = ++new_pos;
    in[new_pos]=now;
    par[now] = pre;
    //update(1, n, 1, new_pos, new_pos, 0);
    if (sc[now] != 0)
        HLD(now, sc[now], head);
    ll sz = adj[now].size();
    for (int i = 0; i < sz; i++) {
        ll node = adj[now][i];
        if (node != sc[now] && node != pre) {
            HLD(now, node, node);
        }
    }
}

ll go_up(ll u) {
    if (node_head[u] == 1) {
        return query(1, n, 1, indx[1], indx[u], 1);
    }
    return min(query(1, n, 1, indx[node_head[u]], indx[u], 1), go_up(par[node_head[u]]));
}
int main() {
    FAST
    cin >> n>>m;
    for (int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(root, 0);
    HLD(0, root, root);
//    dfs2(root, 0);
    while (m--) {
        ll u, v;
        cin>>u>>v;
        if(u==0) {
            update(1, n, 1, indx[v], indx[v], 1);
        } else {
            ll res = go_up(v);
            if(res==MAX) res=-1;
            else res= in[res];
            cout<<res<<endl;
        }
    }
    return 0;
}
/*

*/


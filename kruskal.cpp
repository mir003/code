int n, u, v, w, par[100010];
struct info {
    int u, v, w;
};
vector<info>e, mst;
bool ac(info lhs, info rhs) {
    return lhs.w < rhs.w;
}
ll find_parent(ll a) {
    if (par[a] == a) return a;
    return par[a] = find_parent(par[a]);
}
void kruskal() {
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    sort(e.begin(), e.end(), ac);
    for (auto p : e) {
        int pu = find_parent(p.u), pv = find_parent(p.v);
        if (pu != pv) {
            par[pu] = pv;
            mst.pb(p);
        }
    }
}

ll par[N], res[N], stsz[N], u, v, n, m;
vector<ll>adj[N];
bool taken[N];

ll subtree_size(ll now, ll pre) {
    ll ret=1;
    for(auto u:adj[now]) {
        if(u!=pre && taken[u]==0) {
            ret+=subtree_size(u, now);
        }
    }
    return stsz[now]=ret;
}

ll find_centroid(ll now, ll pre, ll sz) {
    int big=0;
    for(auto u:adj[now]) {
        if(u!=pre && taken[u]==0) {
            if(stsz[u]>sz)
                big=u;
        }
    }
    if(big)
        return find_centroid(big, now, sz);
    else
        return now;
}


set<ll>st, st2;
ll freq[N], freq2[N];
void solve(ll now, ll pre, ll centroid,  ll gcd) {
    res[gcd]++;
    if(now!=centroid) {
        st.insert(gcd);
        freq[gcd]++;
    }
    for(auto u:adj[now]) {
        if(taken[u]==0 && u!=pre) {
            solve(u, now, centroid, __gcd(a[u], gcd));
            if(now==centroid) {
                for(auto it:st) {
                    for(auto it2:st2) {
                        ll gcd2 = __gcd(it, it2);
                        res[gcd2]+=(freq[it]*freq2[it2]);
                    }
                }
                for(auto it:st) {
                    st2.insert(it);
                    freq2[it]+=freq[it];
                    freq[it]=0;
                }
                st.clear();
            }

        }
    }
}

void C_D(ll pre, ll now) { ///C_D(0, 1);
    ll sub_sz = subtree_size(now, 0);
    ll centroid = find_centroid(now, 0, sub_sz/2);
    taken[centroid]=1;
    par[centroid]=pre;
    for(auto it:st2)
        freq2[it]=0;
    st2.clear();
    solve(centroid, 0, centroid, a[centroid]);
    for(auto u:adj[centroid]) {
        if(taken[u]==0) {
            C_D(centroid, u);
        }
    }
}

vector< pair<ll, ll> >q;
ll p,n=8,cost[10][10],mx,m;
bool valid(ll i, ll j) {
    ll k, sz=q.size();
    f(k,sz)
    if(q[k].first==i || q[k].second==j || q[k].first+q[k].second==i+j || i-q[k].first==j-q[k].second)return 0;
    return 1;
}
void backtrack(ll i, ll j) {
    p++;
    if(i==n || j==n)return;
    if(q.size()==n)return;
    if(valid(i,j)) {
        q.push_back(make_pair(i,j));
        m+=cost[i][j];
        ll sz=q.size();
        if(sz==n)return;
        backtrack(i+1, 0);
        if(sz==q.size())q.pop_back();
    }
    if(q.size()<n)backtrack(i,j+1);
}

///sparse table for rmq O(1)**********
ll n, a[N], st[N][20], lg[N];
void b() {
    for(ll i=0; i<n; i++) {
        st[i][0]=a[i];
    }
    for(ll j=1; (1LL<<j)<=n; j++) {
        for(ll i=0; i+(1LL<<j)-1<n; i++) {
            st[i][j]=min(st[i][j-1],st[i+(1LL<<(j-1))][j-1]);
        }
    }
}
ll q(ll l, ll r) {
    if(r>l) return MAX;//invalid for min=MAX, invalid for max=MIN, etc etc
    ll sz= r-l+1;
    ll k=lg[sz];
    ll x= st[l][k];
    sz-=(1LL<<k);
    if(sz>0) {
        k=lg[sz]+1;
        ll y= r-(1LL<<k)+1;
        return min(x,st[y][k]);
    } else return x;
}

int main() {
    lg[1] = 0;
    for (int i = 2; i <= N-5; i++)
        lg[i] = lg[i/2] + 1;
    in1(n);
    for(int i=0; i<n; i++)
        in1(a[i]);
    ll l, r;
    b();
    while(cin>>l>>r) {
        cout<<l<<" "<<r<<" res "<<q(l,r)<<endl;
    }
    return 0;
}

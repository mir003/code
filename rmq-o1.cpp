///sparse table for rmq O(1)**********
ll n, a[N], st[N][20], st2[N][20], lg[N];
void b() {
    for(ll i=0; i<n; i++) {
        st[i][0]=a[i];
    }
    for(ll j=1; (1LL<<j)<=n; j++) {
        for(ll i=0; i+(1LL<<j)-1<n; i++) {
            st[i][j]=st[i][j-1]<st[i+(1LL<<(j-1))][j-1]?st[i][j-1]:st[i+(1LL<<(j-1))][j-1];
        }
    }
}
ll q(ll l, ll r) {
    ll sz= r-l+1;
    ll k=lg[sz];
    ll x= st[l][k];
    sz-=(1LL<<k);
    if(sz>0) {
        k=lg[sz]+1;
        ll y= r-(1LL<<k)+1;
        return x<st[y][k]?x:st[y][k];
    } else return x;
}
void b2() {
    for(ll i=0; i<n; i++) {
        st2[i][0]=a[i];
    }
    for(ll j=1; (1LL<<j)<=n; j++) {
        for(ll i=0; i+(1LL<<j)-1<n; i++) {
            st2[i][j]=st2[i][j-1]>st2[i+(1LL<<(j-1))][j-1]?st2[i][j-1]:st2[i+(1LL<<(j-1))][j-1];
        }
    }
}
ll q2(ll l, ll r) {
    ll sz= r-l+1;
    ll k=lg[sz];///log[sz]
    ll x= st2[l][k];
    sz-=(1LL<<k);
    if(sz>0) {
        k=lg[sz]+1;
        ll y= r-(1LL<<k)+1;
        return x>st2[y][k]?x:st2[y][k];
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
    b2();
    while(cin>>l>>r) {
        cout<<l<<" "<<r<<" res "<<q(l,r)<<endl;
        cout<<l<<" "<<r<<" res "<<q2(l,r)<<endl;
    }
    return 0;
}

/*Only those who endure patiently will be given their reward without limit.*/
#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define MAX 2e8
#define MIN -2e8
#define MOD 1000000007
///#define mod2 20071027
///#define MOD 998244353
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
#define pi4 pair<pii, pii
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE   freopen("input.txt", "r", stdin);  freopen("out.txt", "w", stdout);
#define coutd cout<<fixed<<setprecision(10)//coutd<<res<<endl;
using namespace std;
const ll N = 200010, M = 3010;
ll n, m, k;
int a[N][6],b[6];
int tree[33][3*N][2];
void build(ll l, ll r, ll pos, ll mask) {
    if(l==r) {
        ll sum=0;
        for(int i=0; i<k; i++) {
            if(mask&(1LL<<i)) {
                sum+=a[l][i];
            } else sum-=a[l][i];
        }
        tree[mask][pos][0]=sum;
        tree[mask][pos][1]=sum;
        return;
    }
    ll mid=(l+r)/2;
    build(l, mid, 2*pos, mask);
    build(mid+1, r, 2*pos+1, mask);
    tree[mask][pos][0]=min(tree[mask][2*pos][0], tree[mask][2*pos+1][0]);
    tree[mask][pos][1]=max(tree[mask][2*pos][1], tree[mask][2*pos+1][1]);
    return;
}
void update(ll l, ll r, ll pos, ll P, ll mask) {
    if(l>P || r<P)
        return;
    if(l==r && l==P) {
        ll sum=0;
        for(int i=0; i<k; i++) {
            if(mask&(1LL<<i)) {
                sum+=b[i];
            } else sum-=b[i];
        }
        tree[mask][pos][0]=sum;
        tree[mask][pos][1]=sum;
        return;
    }
    ll mid=(l+r)/2;
    update(l, mid, 2*pos, P, mask);
    update(mid+1, r, 2*pos+1, P, mask);
    tree[mask][pos][0]=min(tree[mask][2*pos][0], tree[mask][2*pos+1][0]);
    tree[mask][pos][1]=max(tree[mask][2*pos][1], tree[mask][2*pos+1][1]);
    return;
}
ll minq(ll l, ll r, ll pos, ll L, ll R, ll mask) {
    if(l>R || r<L)
        return MAX;
    if(l>=L && r<=R)
        return tree[mask][pos][0];
    ll mid=(l+r)/2;
    return min(minq(l, mid, 2*pos, L,R,mask), minq(mid+1, r, 2*pos+1, L, R, mask));
}
ll maxq(ll l, ll r, ll pos, ll L, ll R, ll mask) {
    if(l>R || r<L)
        return MIN;
    if(l>=L && r<=R)
        return tree[mask][pos][1];
    ll mid=(l+r)/2;
    return max(maxq(l, mid, 2*pos, L,R,mask), maxq(mid+1, r, 2*pos+1, L, R, mask));
}
int main() {
    in2i(n,k);
    for(int i=1; i<=n; i++) {
        for(int j=0; j<k; j++) {
            in1i(a[i][j]);
        }
    }
    for(int mask=0; mask<(1LL<<k); mask++)
        build(1, n, 1, mask);
    in1i(m);
    while(m--) {
        ll f;
        in1i(f);
        if(f==1) {
            ll x;
            in1i(x);
            for(int i=0; i<k; i++) {
                in1i(b[i]);
            }
            for(int mask=0; mask<(1LL<<k); mask++)
                update(1, n, 1, x, mask);

        } else {
            ll l, r;
            in2i(l,r);
            ll ret=MIN;
            for(int mask=0; mask<(1LL<<k); mask++){
                ret=max(maxq(1, n, 1, l, r, mask)-minq(1, n, 1, l, r, mask), ret);
            }
            printf("%d\n",ret);
        }
    }
    return 0;
}
/*

*/

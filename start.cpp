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
const ll N = 200010, M = 1005;
ll t;
///sparse table for rmq O(1)**********
ll n, a[N], st[N][20], lg[N];
void build() {
    for(ll i=0; i<n; i++) {
        st[i][0]=a[i];
    }
    for(ll j=1; (1LL<<j)<=n; j++) {
        for(ll i=0; i+(1LL<<j)-1<n; i++) {
            st[i][j]=min(st[i][j-1],st[i+(1LL<<(j-1))][j-1]);
        }
    }
}
ll query(ll l, ll r) {
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
    FAST
    lg[1] = 0;
    for (int i = 2; i <= N-5; i++)
        lg[i] = lg[i/2] + 1;

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    build();
    ll high = n, low=0, mid,ans=-1;
    while(high>=low) {
        mid=(high+low)/2;
        if(fun(mid)) {
            high=mid-1;
            ans=mid;
        } else low=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/

/*Only those who endure patiently will be given their reward without limit.*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 2e18
#define MIN -1e18
//#define MOD 1000000007
//#define mod2 20071027
#define MOD 998244353
#define base 139
//#define MOD 1000074259
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define TC(c) printf("Case #%lld: ", ++c)
#define out(x) cout << #x << " -> " << x << endl;
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define pi4 pair<pii, pii
#define endl "\n"
#define all(x) x.begin(), x.end()
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE   freopen("input.txt", "r", stdin);  freopen("out.txt", "w", stdout);
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<ll>,rb_tree_tag,tree_order_statistics_node_update>orderedSet;///less_equal/greater/greater_equal
//*os.find_by_order(pos)///returns pointer of pos (o indexed)
//os.order_of_key(val)///returns position of value of greater than value
using namespace std;
const ll N = 300010, M = 3010;
orderedSet os[N];
ll n, m, a[N], b[N],indx[N];
ll sum(ll indx, ll val) {
    ll s=0;
    while(indx>0) {
        s+=tree[indx];
        indx-=(indx & -indx);
    }
    return s;
}
void update(ll indx, ll value) {
    while(indx<=n) {
        tree[indx]+=value;
        indx+=(indx & -indx);
    }
}
int main() {
    FAST
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        indx[a[i]];
    }
    for(int i=1; i<=n; i++) {
        cin>>b[i];
        a[i]=indx[b[i]];
        update(i, a[i]);
        indx[b[i]]=i;
    }


    return 0;
}
/*

*/

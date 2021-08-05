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
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<ll>,rb_tree_tag,tree_order_statistics_node_update>orderedSet;///less_equal/greater/greater_equal
orderedSet st;
//*os.find_by_order(pos)///returns pointer of pos (o indexed)
//os.order_of_key(val)///returns position of value of greater than value

const ll N = 100001, M = 1005;
ll t, n;
vector<ll>prime;
bool is_comp[N];
void seive() {
    is_comp[0]=1;
    is_comp[1]=1;
    for(int i=2; i<N; i++) {
        if(!is_comp[i])
            prime.pb(i);
        ll sz=prime.size();
        for(int j=0; j<sz && i*prime[j]<N ; j++) {
            is_comp[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}
random_device rd;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    seive();
    for(auto u:prime) st.insert(u);
    cin>>n;
    ll cur=1;
    while(!st.empty()) {
        ll l = 0, r = (ll)st.size()-1;
        ll rr = (rng()+rng())%MOD, cnt=0;
        ll random = (rr % (r - l + 1)) + l;
        cout<<"B "<<*st.find_by_order(random)<<endl;
        cin>>cnt;
        cout<<"B "<<*st.find_by_order(random)<<endl;
        cin>>cnt;
        if(cnt){

        }
    }
    return 0;
}
/*

*/

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
const ll N = 300010, M = 55;
ll n, m, k, freq[N],cnt;
queue<ll>q[N], finq;
int main() {
    FAST
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        cin>>k;
        for(int j=0; j<k; j++) {
            ll p;
            cin>>p;
            q[i].push(p);
        }
        finq.push(i);
    }
    memn(freq);
    while(!finq.empty()) {
        ll u = finq.front();
        finq.pop();
        ll tp  = q[u].front();
        if(freq[tp]!=u && freq[tp]!=-1) {
            q[u].pop();
            q[freq[tp]].pop();
            if(!q[u].empty()) finq.push(u);
            if(!q[freq[tp]].empty()) finq.push(freq[tp]);
        } else {
            freq[tp]=u;
        }
    }
    for(int i=0; i<m; i++) {
        if(!q[i].empty()) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
/*

*/

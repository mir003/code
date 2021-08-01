/*Only those who endure patiently will be given their reward without limit.*/
/* problem : https://codeforces.com/contest/282/problem/B */
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
const ll N = 1000010, M = 1005;
ll n, x[N], y[N];
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pii,null_type, less<pii>,rb_tree_tag,tree_order_statistics_node_update>orderedSet;///less_equal/greater/greater_equal
orderedSet X;
//*os.find_by_order(pos)///returns pointer of pos (o indexed)
//os.order_of_key(val)///returns position of value of greater than value


random_device rd;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());;
///random knapsack
orderedSet bag, fre;
ll res[N];
int main() {
    FAST
    cin>>n;
    ll p=0, q=0;
    for(int i=0; i<n; i++) {
        cin>>x[i]>>y[i];
        fre.insert({x[i],i});
        q+=y[i];
    }
    auto it = fre.find_by_order(0);
    while(!fre.empty() && q-p>500) {
        int i = it->second;
        p+=x[i];
        q-=y[i];
        bag.insert({y[i], i});
        res[i]=1;
        fre.erase(*it);
        it = fre.find_by_order(0);
    }
    for(int i=0; i<1000; i++) {
        if(!bag.empty() && p>q && p-q>500) {
            int sz = bag.size(), ri = (rng()+rng())%sz;
            auto it = bag.find_by_order(ri);
            int i = it->second;
            p-=x[i];
            q+=y[i];
            res[i]=0;
            fre.insert({y[i], i});
            bag.erase(*it);
        }
        if(abs(p-q)<=500) {
            break;
        }
        if(!fre.empty() && q>p && q-p>500) {
            int sz = fre.size(), rj = (rng()+rng())%sz;
            auto it = fre.find_by_order(rj);
            int i = it->second;
            q-=y[i];
            p+=x[i];
            res[i]=1;
            bag.insert({x[i], i});
            fre.erase(*it);
        }
        if(abs(p-q)<=500) {
            break;
        }
    }
    if(abs(p-q)>500){
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(res[i]) cout<<"A";
        else cout<<"G";
    }
    return 0;
}
/*

*/

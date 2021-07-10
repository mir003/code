/*Only those who endure patiently will be given their reward without limit.*/
#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define MAX 2e18
#define MIN -2e18
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
const ll N = 200010, M = 80000;
ll t, n,k,a[N],res;
int main() {
    FAST
    cin>>t;
    while(t--) {
        cin>>n;
        ll g=0;
        res=0;
        for(int i=0; i<n; i++) {
            cin>>a[i];
            g=__gcd(a[i], g);
        }
        set<ll>st;
        for(int i=0; i<n; i++) {
            a[i]/=g;
            if(a[i]!=1) {
                st.insert(i);
            }
        }
        while(!st.empty()) {
            res++;
            set<ll>tmp;
            ll pre=a[0];
            for(auto u=st.begin(); u!=st.end(); u++) {
                auto it=u;
                it++;
                if(it==st.end()) break;
//                cout<<(*u)<<" "<<(*it)<<endl;
                if((*it)!=(*u)+1) a[*u]=1;
                else {
                    a[*u]=__gcd(a[*u], a[*it]);
                    if(a[*u]!=1) {
                        tmp.insert(*u);
                    }
                }
            }
            if(st.find(0)!=st.end() && st.find(n-1)!=st.end()) {
                a[n-1]=__gcd(a[n-1], pre);
                if(a[n-1]!=1) {
                    tmp.insert(n-1);
                }
            }
            st=tmp;
        }
        cout<<res<<endl;

    }
    return 0;
}
/*
1
4
16 24 10 5
*/

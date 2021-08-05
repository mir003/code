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
const ll N = 100001, M = 1005;
ll t, n, m;
vector<ll>prime;
bool is_comp[N];
void seive() {
    is_comp[0]=1;
    is_comp[1]=1;
    for(int i=2; i<=n; i++) {
        if(!is_comp[i])
            prime.pb(i);
        ll sz=prime.size();
        for(int j=0; j<sz && i*prime[j]<=n ; j++) {
            is_comp[i*prime[j]]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}

ll pw[25];
bool vis[N];
void del(int u) {
    for(int i=u; i<=n; i+=u) {
        if(vis[i]==0) m--;
        vis[i]=1;
    }
    return;
}
int main() {
    cin>>n;
    seive();
    m=n;
    if(n==1) {
        cout<<"C 1"<<endl;
        cout<<flush;
        return 0;
    }
    ll cur=1,cnt, sz= (ll)prime.size(), ss=sqrt(n);
    ll k=0, sq=sqrt(sz);
    for(int i=sz-1; i>=0 && prime[i]>ss; i--) {
        k++;
        del(prime[i]);
        cout<<"B "<<prime[i]<<endl;
        cout<<flush;
        cin>>cnt;
        if(k==sq || (i==0 || prime[i-1]<ss)) {
            cout<<"A 1"<<endl;
            cout<<flush;
            cin>>cnt;
            if(m!=cnt) {
                for(int j=0; j<k; j++) {
                    cout<<"A "<<prime[i+j]<<endl;
                    cout<<flush;
                    cin>>cnt;
                    if(cnt) {
                        cur*=prime[i+j];
                    }
                }
                break;
            }
            k=0;
        }
    }
    for(auto p:prime) {
        if(p>n/cur || p>ss) break;
        cout<<"B "<<p<<endl;
        cout<<flush;
        cin>>cnt;
        cout<<"B "<<p<<endl;
        cout<<flush;
        cin>>cnt;
        if(cnt) {
            ll high=0, low=0, ans=0;
            pw[0]=p;
            for(int i=1; i<20; i++) {
                if(pw[i-1]*p>n/cur) break;
                pw[i]=pw[i-1]*p;
                high=i;
            }
            while(high>=low) {
                ll mid=(high+low)/2;
                cout<<"B "<<pw[mid]<<endl;
                cout<<flush;
                cin>>cnt;
                if(cnt) {
                    ans=mid;
                    low=mid+1;
                } else high=mid-1;
            }
            cur*=pw[ans];
        }
    }

    cout<<"C "<<cur<<endl;
    cout<<flush;
    return 0;
}
/*

*/

///solution 2: using coin decompose
///similar to coin change 1
const ll N=300010;
ll t,tc, n, k, c, a[105];
vector<ll>coin;
bool pre[100005], cur[100005];

int main() {
    in1(t);
    while(t--) {
        ll res=0;
        memz(pre);
        memz(cur);
        coin.clear();
        pre[0]=true;
        cur[0]=true;
        in2(n,k);
        for(int i=0; i<n; i++)
            in1(a[i]);
        for(int i=0; i<n; i++) {
            in1(c);
            ll p=1;
            while(c-p>=0) {
                coin.pb(a[i]*p);
                c-=p;
                p*=2;
            }
            if(c)
                coin.pb(a[i]*c);

        }
        for(ll val:coin) {
            for(int sum=val; sum<=k; sum++) {
                cur[sum] |=pre[sum-val];
            }
            for(int sum=1; sum<=k; sum++)
                pre[sum]=cur[sum];
        }
        for(int sum=1; sum<=k; sum++)
            res+=pre[sum];
        TC(tc);
        printf("%lld\n", res);
    }
    return 0;
}

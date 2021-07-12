ll n,res[10000000],a[10000000],lis[10000000],sz;
ll bs_lis(ll q, ll sz) {
    ll high=sz,low=0,mid,ans;
    while(high>=low) {
        mid=(high+low)/2;
        if(q<lis[mid]) {
            high=mid-1;
        } else {
            ans= mid+1;
            low=mid+1;
        }
    }
    return ans;
}
void LIS() { ///a is the main array
    lis[0]=MIN;
    for(int i=1; i<=n; i++) {
        lis[i]=MAX;
    }
    for(ll i=0; i<n; i++) {
        ll ans = bs_lis(a[i],n+1);
        if(lis[ans]==MAX)
            res[ans]=a[i];
        lis[ans]=a[i];
    }
    for(ll i=1; i<=n; i++) {
        if(lis[i]!=MAX)
            cout<<res[i]<<endl;
    }
}

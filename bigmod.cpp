///mod inverse --> bigmod(num, mod-2, mod) where mod and num are coprime
ll bigmod(ll num, ll power, ll mod) {
    if(power==0)return 1;
    ll x=bigmod(num,power/2,mod);
    x= (x*x)%mod;
    if(power%2) x= (x*num)%mod ;
    return x;
}

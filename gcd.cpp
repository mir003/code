ll GCD(ll a, ll b) {
    if(a%b==0)return b;
    return GCD(b,a%b);
}

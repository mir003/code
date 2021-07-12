ll fp(ll a) {
    if(par[a]==a) return a;
    return par[a]=fp(par[a]);
}

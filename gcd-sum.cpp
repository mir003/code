///all pair GCD sum --> res[n]
void gcd_sum() {
    eular_seive();
    for(int i=1; i<=N-10; i++) {
        for(int j=i; j<=N-10; j+=i) {
            calc[j]+=(e[j/i]*i);
        }
    }
    for(int i=1; i<=N-10; i++) {
        res[i]=res[i-1]+calc[i];
    }
}

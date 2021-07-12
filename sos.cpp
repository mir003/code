const ll B=20;
void sos() { ///O(3^n)
    /// iterate over all the masks
    for (int mask = 0; mask < (1<<B); mask++) {
        F[mask] = A[0];
        /// iterate over all the subsets of the mask
        for(int i = mask; i > 0; i = (i-1) & mask) {
            F[mask] += A[i];
        }
    }
}
void fun() {
    for(ll mask=0; mask<(1LL<<B); mask++)
        F[mask]=a[mask];///a[mask]=value of masked subset
    ///SOS --> calculate for sub mask
    for(ll pos=0; pos<B; pos++) { ///bit=B
        for(ll mask=0; mask<(1LL<<B); mask++) {
            if(mask&(1LL<<pos))
                F[mask]+=F[mask^(1LL<<pos)];///subset sum
        }
    }
    ///reverse SOS -> calculate for super mask
    for(ll pos=0; pos<B; pos++) {
        for(ll mask=(1LL<<B)-1; mask>=0; mask--) {
            if(!(mask&(1LL<<pos))) {
                F[mask]=max(F[mask],F[mask^(1LL<<pos)]);
            }
        }
    }
    ///solve
    for(ll mask=0; mask<N; mask++) {
        if(a[mask]) {
            ll mx=0;
            ll msk = (mask^(N-1));
            for(int pos=0; pos<21; pos++) {
                if(msk&(1LL<<pos))
                    mx=max(F[msk], F[msk^(1LL<<pos)]);
            }
            res=max(res, F[mask]+mx);
        }
    }

}

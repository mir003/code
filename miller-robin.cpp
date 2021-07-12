mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using LL = long long;

LL mulmod(LL a, LL b, LL base) {
    LL rv = 0;
    a %= base;

    while (b) {
        if (b & 1) rv = (rv + a) % base;
        a = (a + a) % base;
        b /= 2;
    }
    return rv % base;
}

LL bpow(LL a, LL b, LL base) {
    LL rv = 1;
    while (b) {
        if (b & 1) rv = mulmod(rv, a, base);
        a = mulmod(a, a, base);
        b /= 2;
    }
    return rv % base;
}


bool Miller(LL p, int iteration) {
    if (p == 2) return true;
    if (p < 2) return false;
    if (p % 2 == 0) return false;


    LL s = p - 1;
    while (s % 2 == 0) s /= 2;

    for (int i = 0; i < iteration; i++) {
        LL a = rng() % (p - 1) + 1, temp = s;
        LL mod = bpow(a, temp, p);
        while (temp != p - 1 and mod != 1 and mod != p - 1) {
            mod = mulmod(mod, mod, p);
            temp = temp * 2;
        }
        if (mod != p - 1 and temp % 2 == 0) {
            return false;
        }
    }
    return true;
}


int main() {

    cout<<"Is prime "<<Miller(29996224275833LL,20)<<endl;
    return 0;
}

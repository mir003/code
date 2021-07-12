// ax^2+bx+c=0, int x possible kina
bool degree(ll a, ll b, ll c) {
    ll y = b * b - 4 * a * c;
    ll sy = sqrt(y);
    if (sy * sy == y) {
        if ((sy - b) % (2 * a) == 0 || (-sy - b) % (2 * a) == 0) {
            return 1;
        }
    }
    return 0;
}


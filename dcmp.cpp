inline int dcmp (double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}


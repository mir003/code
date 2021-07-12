void permute() {
    int p[] = {1, 2, 3};
    do {
        for (int i = 0; i < 3; i++)
            printf("%lld ", p[i]);
        printf("\n");
    } while (next_permutation(p, p + 3));
}

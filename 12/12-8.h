int *make_array(int elem, int val) {
    int *p;
    int i;
    p = (int *)malloc(sizeof(int) * elem);
    for (i = 0; i < elem; i++)
        *(p + i) = val;
    return p;
}

void show_array(const int ar[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i % 8 == 0)
            puts("\n");
        printf("%d ", ar[i]);
    }
}

int cmp(const void *arg1, const void *arg2) {
    return *(int*)arg1 < *(int*)arg2;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int end = gSize < sSize ? gSize : sSize;
    int ans = 0;
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int j = 0;
    for (int i = 0; i < gSize; ++i) {
        if (j >= sSize)
            break;
        if (s[j] >= g[i]) {
            ++ans;
            ++j;
        }
    }

    return ans;
}

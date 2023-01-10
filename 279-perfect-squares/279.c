#define min(a,b) ((a) < (b) ? (a) : (b))

int numSquares(int n){
    int f[n + 1];
    int perfects[n];
    int perfectSize = 1;

    perfects[0] = 1;
    f[0] = INT_MAX;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = INT_MAX;
    }

    for (int i = 2; i <= n; ++i) {
        if ((i * i) <= n) {
            f[i * i] = 1;
            perfects[perfectSize++] = i * i;
        } else {
            break;
        }
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (f[i] == 1)
            continue;
        for (int j = perfectSize - 1; j >= 0; j--) {
            int p = perfects[j];
            if (p <= i)
                f[i] = min(f[i], f[i - p] + 1);
        }
    }

    return f[n];
}


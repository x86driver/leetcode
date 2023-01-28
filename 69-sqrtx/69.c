int mySqrt(int x){
    int left = -1;
    int right = x;
    while (left < right) {
        long long mid = (left + right + 1) / 2;
        if ((mid * mid) <= x)
            left = mid;
        else
            right = mid - 1;
    }

    if (right == -1)
        return 0;
    return right;
}

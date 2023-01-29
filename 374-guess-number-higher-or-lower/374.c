/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
    unsigned int left = 1;
    unsigned int right = n;
    while (left < right) {
        unsigned long long mid = (left + right) / 2;
        int ret = guess(mid);
        if (ret == 0)
            return mid;
        else if (ret == -1)
            right = mid;
        else if (ret == 1)
            left = mid + 1;
    }

    return right;
}

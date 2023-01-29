bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int left = -1;
    int right = matrixSize - 1;

    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (matrix[mid][0] <= target)
            left = mid;
        else
            right = mid - 1;
    }

    if (right < 0)
        return false;
    if (matrix[right][0] == target)
        return true;

    int col = right;
    left = 0;
    right = matrixColSize[col] - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        if (matrix[col][mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }

    return matrix[col][right] == target;
}

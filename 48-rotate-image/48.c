void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int const N = matrixSize;

    int A = 0;
    int B = 0;
    int C = 0;

    for (int j = 0; j < N / 2 + 1; ++j) {
        for (int i = j; i < N-1-j; ++i) {
            A = matrix[i][N-1-j];
            B = matrix[N-1-j][N-1-i];
            C = matrix[N-1-i][j];

            matrix[i][N-1-j] = matrix[j][i];
            matrix[N-1-j][N-1-i] = A;
            matrix[N-1-i][j] = B;
            matrix[j][i] = C;
        }
    }
}

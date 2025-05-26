void print(int m, int n, int** mat) { //print func used for debugging in case of test case errors
    printf("\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void setZeroes(int** mat, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int row = 0;
    int col = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (mat[i][j] == 0) {
                if (i == 0) {
                    row = 1;
                } else if (j == 0) {
                    col = 1;
                } else {

                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
    }

    for (int i = m - 1; i > 0; i--) {
        if (mat[i][0] == 0) {

            for (int j = 1; j < n; j++) {
                mat[i][j] = 0;
            }
        }
    }

    for (int j = n - 1; j > 0; j--) {
        if (mat[0][j] == 0) {

            for (int i = 1; i < m; i++) {
                mat[i][j] = 0;
            }
        }
    }

    if (mat[0][0] == 0 || (row && col)) {
        for (int i = 0; i < m; i++) {
            mat[i][0] = 0;
        }
        for (int j = 0; j < n; j++) {
            mat[0][j] = 0;
        }
    } else {
        if (row) {

            for (int j = 0; j < n; j++) {
                mat[0][j] = 0;
            }

        } else if (col) {
            for (int i = 0; i < m; i++) {
                mat[i][0] = 0;
            }
        } else {
        }
    }
}

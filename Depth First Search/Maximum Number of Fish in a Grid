int find(int* parent, int** grid, int gridSize, int* gridColSize, int x,
         int y) {
    if (parent[x * gridColSize[0] + y] != x * gridColSize[0] + y) {
        parent[x * gridColSize[0] + y] =
            find(parent, grid, gridSize, gridColSize,
                 parent[x * gridColSize[0] + y] / gridColSize[0],
                 parent[x * gridColSize[0] + y] % gridColSize[0]);
    }
    return parent[x * gridColSize[0] + y];
}
void unionf(int* parent, int* size, int** grid, int gridSize, int* gridColSize,
            int rootx, int rooty, int* value) {
    if (rootx != rooty) {
        if (size[rootx] >= size[rooty]) {
            parent[rooty] = rootx;
            size[rootx]++;
            value[rootx] += value[rooty];

        } else {
            parent[rootx] = rooty;
            size[rooty]++;
            value[rooty] += value[rootx];
        }
    }
}
int findMaxFish(int** grid, int gridSize, int* gridColSize) {
    int* parent = malloc(sizeof(int) * ((gridSize * gridColSize[0]) + 1));
    for (int i = 0; i < gridSize * gridColSize[0]; i++) {
        parent[i] = i;
    }
    int* size = calloc((gridSize * gridColSize[0]) + 1, sizeof(int));
    int* value = malloc(sizeof(int) * ((gridSize * gridColSize[0]) + 1));
    for (int i = 0; i < gridSize * gridColSize[0]; i++) {
        value[i] = grid[i / gridColSize[0]][i % gridColSize[0]];
    }
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j]) {
                for (int k = 0; k < 4; k++) {
                    int row = i + dir[k][0];
                    int col = j + dir[k][1];
                    if (!(row < 0 || col < 0 || row >= gridSize ||
                          col >= gridColSize[0])) {
                        if (grid[row][col]) {
                            int rootx =
                                find(parent, grid, gridSize, gridColSize, i, j);
                            int rooty = find(parent, grid, gridSize,
                                             gridColSize, row, col);

                            unionf(parent, size, grid, gridSize, gridColSize,
                                   rootx, rooty, value);
                        }
                    }
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < gridSize * gridColSize[0]; i++) {
        if (value[i] > max) {
            max = value[i];
        }
    }
    return max;
}

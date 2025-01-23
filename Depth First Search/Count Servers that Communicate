int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int dfs(int** grid, int gridSize, int* gridColSize, int** visited, int i, int j,
        int r, int c) {
    int count = 0;
    // int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[0]) {
        printf("outofbounds\n");
        return 0;
    }
    if (grid[i][j] && !visited[i][j]) {
        visited[i][j] = 1;
        count += 1;
        for (int k = 0; k < 4; k++) {
            count += dfs(grid, gridSize, gridColSize, visited, i + dir[k][0],
                         j + dir[k][1], dir[k][0], dir[k][1]);
        }
    } else {
        if (!visited[i][j]) {
            count +=
                dfs(grid, gridSize, gridColSize, visited, i + r, j + c, r, c);
        }
    }

    printf("%d\n", count);
    return count;
}
int countServers(int** grid, int gridSize, int* gridColSize) {

    int** visited = calloc(gridSize, sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        visited[i] = calloc(gridColSize[0], sizeof(int));
    }
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] && !visited[i][j]) {
                visited[i][j] = 1;
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    cnt +=
                        dfs(grid, gridSize, gridColSize, visited, i + dir[k][0],
                            j + dir[k][1], dir[k][0], dir[k][1]);
                }
                if (cnt) {
                    count += (cnt + 1);
                }
            }
        }
    }

    return count;
}

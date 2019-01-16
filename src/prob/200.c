void DFS(char **grid, int gridRowSize, int gridColSize, int x, int y){
    if (grid[x][y] == '0')return;
    grid[x][y] = '0';

    if (x)                   DFS(grid, gridRowSize, gridColSize, x - 1, y);
    if (x + 1 < gridRowSize) DFS(grid, gridRowSize, gridColSize, x + 1, y);
    if (y)                   DFS(grid, gridRowSize, gridColSize, x, y - 1);
    if (y + 1 < gridColSize) DFS(grid, gridRowSize, gridColSize, x, y + 1);
}
int numIslands(char **grid, int gridRowSize, int gridColSize)
{
    int count = 0;
    for (int i = 0; i < gridRowSize; ++i)
        for (int j = 0; j < gridColSize; ++j)
            if (grid[i][j] == '1'){
                ++count;
                DFS(grid, gridRowSize, gridColSize, i, j);
            }
    return count;
}

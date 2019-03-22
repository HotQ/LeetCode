/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function (grid) {
    var gridRowSize = grid.length, gridColSize = grid[0].length;
    for (var i = gridRowSize - 2; i >= 0; --i) grid[i][gridColSize - 1] += grid[i + 1][gridColSize - 1];
    for (var j = gridColSize - 2; j >= 0; --j) grid[gridRowSize - 1][j] += grid[gridRowSize - 1][j + 1];
    for (var i = gridRowSize - 2; i >= 0; --i) 
        for (var j = gridColSize - 2; j >= 0; --j) 
            grid[i][j] += grid[i + 1][j] < grid[i][j + 1] ? grid[i + 1][j] : grid[i][j + 1];
    return grid[0][0];
};

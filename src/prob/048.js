/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
    var size = matrix.length, size1 = size - 1;
    for (var x = 0; x < size / 2; ++x) {
        for (var y = x; y < size1 - x; ++y) {
            var temp = matrix[size1 - y][x];
            matrix[size1 - y][x] = matrix[size1 - x][size1 - y];
            matrix[size1 - x][size1 - y] = matrix[y][size1 - x];
            matrix[y][size1 - x] = matrix[x][y];
            matrix[x][y] = temp;
        }
    }
};


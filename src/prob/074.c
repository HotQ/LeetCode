#include <stdbool.h>
#include <stdlib.h>
bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize, int target)
{
    if (matrix == NULL || matrixRowSize == 0 || matrixColSize == 0) return false;
    int lo = 0, hi = matrixRowSize * matrixColSize, mid;
    while (lo < hi){
        mid = (lo + hi) / 2;
        if (matrix[mid / matrixColSize][mid % matrixColSize] < target) lo = mid + 1;
        else hi = mid;
    }
    if (lo < matrixRowSize * matrixColSize && matrix[lo / matrixColSize][lo % matrixColSize] == target) return true;
    else return false;
}

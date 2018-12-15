#include "array.h"

INDEX binarySearch(int *array, INDEX lo, INDEX hi, int target)
{
    // [lo, hi)
    while (lo < hi){
        INDEX mid = lo + (hi - lo) / 2;
        if (array[mid] < target) lo = mid + 1;
        else                     hi = mid;
    }
    return lo;
}

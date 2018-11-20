#include <stdbool.h>
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x >= 0 && x <= 9)
        return true;

    int head = 0,
        tail = 0,
        digits[11];

    for (; x > 0; ++tail, x /= 10)
        digits[tail] = x % 10;
    --tail;
    while (tail - head >= 1)
        if (digits[tail--] != digits[head++])
            return false;

    return true;
}

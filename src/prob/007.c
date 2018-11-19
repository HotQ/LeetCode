int reverse(int x)
{
    long res = 0,
         flag = (x > 0) ? 1 : -1;
    int min = 0x80000000,
        max = 0x7fffffff;

    x = x * flag;

    while (x > 0)
    {
        res = res * 10 + x % 10;
        x = x / 10;
    }
    res *= flag;
    return (res < min || res > max) ? 0 : res;
}

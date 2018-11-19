int myAtoi(char *str)
{
    int i = 0,
        res = 0,
        sign;

    int min = 0x80000000,
        max = 0x7fffffff;

    while (str[i] == ' ') ++i;

    switch (str[i])
    {
    case '-':
    case '+':
        ++i;
        sign = 44 - str[i];
        break;
    case '\0':
        return 0;
    default:
        if (str[i] >= '0' && str[i] <= '9')
        {
            sign = 1;
            break;
        }
        else
            return 0;
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        if ((max / 10 < res) || ((max - 10 * res) < (str[i] - '0' - (sign == -1))))
            if (sign == 1) return max;
            else           return min;


        res = res * 10 + (str[i] - '0');
        ++i;
    }
    return res * sign;
}

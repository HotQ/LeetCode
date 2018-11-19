char *convert(char *s, int numRows)
{
    int len = strlen(s),
        step = 2 * numRows - 2;
    char *res = (char *)malloc((len + 1) * sizeof(char));
    res[len] = '\0';

    // n=1
    if((len == 1) || (numRows == 1)){
        strcpy(res,s);
        return res;
    }

    // n>1
    int i = 0, j = 0;

    // 1st row of convertedStr
    while (i < len)
    {
        res[j++] = s[i];
        i += step;
    }
    // 2nd row to the next line to last
    for (int r = 1; r <= numRows - 2; ++r)
    {
        i = r;
        while (i < len)
        {
            res[j++] = s[i];
            int sub = i + 2 * (numRows - r - 1);
            if (sub < len)
                res[j++] = s[sub];
            i += step;
        }
    }
    // last one
    i = numRows - 1;
    while (i < len)
    {
        res[j++] = s[i];
        i += step;
    }

    return res;
}

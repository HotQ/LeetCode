#include <string.h>

int _getWeight(char c)
{
    switch (c)
    {
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    }
    return -1;
}

int romanToInt(char *s)
{
    int strLen = strlen(s),
        i = 0,
        res = 0,
        weight = 0,
        priorWeight = 0;
    if (strLen == 1)
    {
        return _getWeight(s[i++]);
    }
    if (strLen > 1)
    {
        weight = _getWeight(s[i++]);
        res += weight;
    }

    while (s[i] != '\0')
    {
        priorWeight = weight;
        weight = _getWeight(s[i++]);
        if (priorWeight < weight)
            res = res- 2 * priorWeight + weight;    
        else
            res += weight;
    }
    return res;
}

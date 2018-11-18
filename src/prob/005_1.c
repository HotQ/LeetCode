char *longestPalindrome(char *s)
{
    int len = 0,
        l, r, i = 0,
        maxLen = 0,
        maxl = 0, maxr = 0;

    while (s[len] != '\0')
    {        
        // odd
        l = r = len;

        while (l >= 0 && s[r] != '\0')
        {
            if (s[l] == s[r])
            {
                if (r - l + 1 > maxLen)
                {
                    maxLen = r - l + 1;
                    maxl = l;
                    maxr = r;
                }
                --l;
                ++r;
            }
            else break;
        }

        // even
        l = len;
        r = len + 1;
        while (l >= 0 && s[r] != '\0')
        {
            if (s[l] == s[r])
            {
                if (r - l + 1 > maxLen)
                {
                    maxLen = r - l + 1;
                    maxl = l;
                    maxr = r;
                }
                --l; 
                ++r;
            }
            else break;
        }
        ++len;
    }
    char *res = (char *)malloc((maxLen + 1) * sizeof(char));
    strncpy(res, s + maxl, maxLen);
    res[maxLen] = '\0';
    return res;
}

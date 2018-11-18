char *longestPalindrome(char *s)
{
    // pretreatment
    char *s_new = (char *)malloc(3001 * sizeof(char));
    int n = strlen(s),
        cnt = 0,
        *p = (int *)malloc(3001 * sizeof(int));

    s_new[cnt++] = '$';
    s_new[cnt++] = '#';
    for (int i = 0; i < n; i++)
    {
        s_new[cnt++] = s[i];
        s_new[cnt++] = '#';
    }
    s_new[cnt] = '\0';

    // process
    int mx = 1, id = 1;
    p[0] = 0;
    for (int i = 1; i < cnt; i++)
    {
        if (i < mx)
            p[i] = (p[2 * id - i] < mx - i) ? p[2 * id - i] : mx - i;
        else
            p[i] = 1;
        while (s_new[i + p[i]] == s_new[i - p[i]]) 
            p[i]++;
        if (i + p[i] > mx) 
        {
            mx = p[i] + i;
            id = i;
        }
    }

    // output
    int ans = p[0], index = 0;
    for (int i = 1; i < cnt; i++)
        if (p[i] > ans)
        {
            ans = p[i];
            index = i;
        }

    char *res = (char *)malloc(ans * sizeof(char));
    strncpy(res, s + index / 2 - ans / 2 , ans - 1);
    res[ans-1] = '\0';

    return res;
}

int strStr(char *s, char *p){
    int i = 0, j = 0, k = -1,
        sLen = strlen(s),
        pLen = strlen(p),
        *next = (int *)malloc(sizeof(int) * pLen);

    next[0] = -1;

    while (j < pLen - 1)
        if (k == -1 || p[j] == p[k]){
            ++k;
            ++j;
            next[j] = k;
        }
        else
            k = next[k];
    
    i = j = 0;

    while (i < sLen && j < pLen)
        if (j == -1 || s[i] == p[j]){
            i++;
            j++;
        }
        else
            j = next[j];

    free(next);
    if (j == pLen) return i - j;
    else return -1;
}

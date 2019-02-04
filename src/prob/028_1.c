int strStr(char *haystack, char *needle)
{
    int l1 = strlen(haystack),
        l2 = strlen(needle);
    if(l2 == 0) return 0;
    bool matchNQ = true;
    for (int i = 0; i <= l1 - l2; ++i) {
        for (int j = 0; j < l2; ++j) 
            if (haystack[i + j] != needle[j])  matchNQ = false;
        if (matchNQ) return i;
        matchNQ = true;
    }
    return -1;
}

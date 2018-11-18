int lengthOfLongestSubstring(char *s)
{
    int ind[256] = {[0 ... 255] = -2};
    int head = 0,
        tail = 0,
        max = 0;

    while (s[tail] != '\0')
    {
        // c: order in alphabet
        int c = s[tail];

        if (ind[c] >= head)
            head = ind[c] + 1;

        ind[c] = tail;

        if (max < (tail - head + 1))
            max = tail - head + 1;

        ++tail;
    }
    return max;
}

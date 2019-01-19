bool isPalindrome(char *s)
{
    int lo = 0,
        hi = strlen(s) - 1;

    while (lo < hi){
        if ((s[lo] < 'a' || s[lo] > 'z') && (s[lo] < '0' || s[lo] > '9')){
            if (s[lo] >= 'A' && s[lo] <= 'Z')s[lo] += 32;
            else ++lo;
            continue;
        }
        if ((s[hi] < 'a' || s[hi] > 'z') && (s[hi] < '0' || s[hi] > '9')){
            if (s[hi] >= 'A' && s[hi] <= 'Z')s[hi] += 32;
            else--hi;
            continue;
        }
        if (s[lo] == s[hi]){ ++lo; --hi; }
        else return false;
    }
    return true;
}

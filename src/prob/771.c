int numJewelsInStones(char *J, char *S){
    int res = 0;
    while (*S){
        char *t = J;
        while (*t){
            if (*t == *S)
                ++res;
            ++t;
        }
        ++S;
    }
    return res;
}

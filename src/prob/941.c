bool validMountainArray(int *A, int ASize){
    int top = -1;
    for (int i = 1; i < ASize; ++i)
        if (A[i] > A[i - 1]) top = i;
        else break;
    if (top < 0 || top == ASize - 1) 
        return false;
    for (int i = top + 1; i < ASize; ++i)
        if (A[i] >= A[i - 1])
            return false;
    return true;
}

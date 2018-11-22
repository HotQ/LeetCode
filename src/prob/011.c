int maxArea(int *height, int heightSize)
{
    int i = 0,
        j = heightSize - 1,
        res = 0;

    while (i < j)
    {
        int crtMaxArea = (j - i) * (height[j] > height[i] ? height[i] : height[j]);
        if (crtMaxArea > res)
            res = crtMaxArea;
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return res;
}

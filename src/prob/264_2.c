#define min(dest, n1, n2, n3) { int res = (n1 < n2 ? n1 : n2); dest = res < n3 ? res : n3; }

int nthUglyNumber(int n)
{
    int uglyNumbers[1690] = {1},
        p2 = 0, p3 = 0, p5 = 0;
    for (int i = 1; i < n; ++i) {
        int t2 = uglyNumbers[p2] * 2,
            t3 = uglyNumbers[p3] * 3,
            t5 = uglyNumbers[p5] * 5;
        min(uglyNumbers[i], t2, t3, t5);
        if (uglyNumbers[i] == t2) ++p2;
        if (uglyNumbers[i] == t3) ++p3;
        if (uglyNumbers[i] == t5) ++p5;
    }
    return uglyNumbers[n - 1];
}

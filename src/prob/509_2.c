void dot22(int p[2][2], int q[2][2]){
    int temp[2][2] = {{p[0][0] * q[0][0] + p[0][1] * q[1][0], p[0][0] * q[0][1] + p[0][1] * q[1][1]},
                      {p[1][0] * q[0][0] + p[1][1] * q[1][0], p[1][0] * q[0][1] + p[1][1] * q[1][1]}};
    memcpy(p, temp, 4 * sizeof(int));
}
void matpow22(int mat[2][2], int N){
    if (N == 1) return;
    int f[2][2] = {{1, 1}, {1, 0}};
    matpow22(mat, N / 2);
    dot22(mat, mat);
    if (N % 2) dot22(mat, f);
    return;
}
int fib(int N){
    if (N == 0) return 0;
    if (N == 1) return 1;

    int mat[2][2] = {{1, 1}, {1, 0}};
    matpow22(mat, N-1);
    return mat[0][0];
}
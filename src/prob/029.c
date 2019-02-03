int divide(int dividend, int divisor)
{
    if (dividend == 0)  return 0;
    if (divisor == 1) return dividend;

    long long flag = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1,
              ldividend = dividend > 0 ? dividend : -1 * (long long)dividend,
              ldivisor  = divisor  > 0 ? divisor  : -1 * (long long)divisor,
              crt = ldivisor,
              subans = 1,
              ans = 0;
    if (ldividend < ldivisor) return 0;

    while (1)

        if (crt <= ldividend - crt) {
            crt = crt << 1;
            subans = subans << 1;
        }
        else if (crt <= ldividend - ldivisor) {
            ldividend -= crt; ans += subans;
            subans = 1; crt = ldivisor;
        }
        else {
            ans += subans;
            if (flag * ans > 2147483647) return 2147483647;
            return flag * ans;
        }
}

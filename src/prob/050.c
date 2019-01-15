double myPow(double x, int n) {
	if (n == 0) return 1.0;
	if (n == 1) return x;
	if (n == -1) return 1 / x;
	double temp = myPow(x, n / 2);
	return temp * temp * (n % 2 == 0 ? 1 : (n > 0 ? x : 1 / x));
}

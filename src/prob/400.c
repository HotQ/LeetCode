int findNthDigit(int n) {
	int auxi[] = { 0,9,189, 2889, 38889, 488889, 5888889, 68888889, 788888889, },
		base[] = { 0,1,10,100,1000,10000,100000,1000000,10000000,100000000, },
		lo = 0, hi = 9, dgt, num, dgi;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (auxi[mid] < n) lo = mid + 1;
		else               hi = mid;
	}
	dgt = n - auxi[lo - 1];
	num = (dgt - 1) / lo + base[lo];
	dgi = dgt % lo;

	if (dgi == 0) return num % 10;
	for (int p = 1; p <= dgi; ++p) {
		dgt = num / base[lo + 1 - p];
		num = num - dgt * base[lo + 1 - p];
	}
	return dgt;
}

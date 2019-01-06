char* reverseWords(char* s) {
	char *w = s,
		*w1 = s,
		*w2;
	while (1) {
		if (*w == '\0') return s;
		while (*w != ' ') { 
			++w; 
			if (*w == '\0') break;
		}
		if (*w == ' ' || *w == '\0') {
			w2 = w - 1;
			while (w1 < w2) {
				char c = *w1;
				*w1 = *w2;
				*w2 = c;
				++w1;
				--w2;
			}
		}
		if (*w == '\0') return s;
		w1 = ++w;
	}
	return s;
}

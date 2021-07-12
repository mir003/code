void fastscan(int& x) {
    x=0;
	bool neg = false;
	int c = getchar();
	if(c == ' ' || c == '\n')
		c = getchar();
	if(c == '-') {
		neg = true;
		c = getchar();
	}
	for(; c >='0' && c <='9'; c = getchar())
		x = (x<<1) + (x<<3) + c - 48;
	if(neg)
		x *= -1;
}

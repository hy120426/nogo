extern const int deep;
struct qi {
	int i = 0;
	int j = 0;
	int value[10] = {}; //value[几]就是第几层价值，0用不上，比5大的也多余了
	bool operator < (const qi& another) {
		for (int i = 1; i <= deep; i++) {
				if (value[i] > another.value[i]) return 1;
				if (value[i] < another.value[i]) return 0;
		} //这个重载是故意写反的，一开始我想用sort让它帮我排来着，后来改swap了
		return 0;
	}
};
struct position {
	int x;
	int y;
};


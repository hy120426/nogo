extern const int deep;
struct qi {
	int i = 0;
	int j = 0;
	int value[10] = {}; //value[��]���ǵڼ����ֵ��0�ò��ϣ���5���Ҳ������
	bool operator < (const qi& another) {
		for (int i = 1; i <= deep; i++) {
				if (value[i] > another.value[i]) return 1;
				if (value[i] < another.value[i]) return 0;
		} //��������ǹ���д���ģ�һ��ʼ������sort�������������ţ�������swap��
		return 0;
	}
};
struct position {
	int x;
	int y;
};


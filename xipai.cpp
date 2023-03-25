#include"xipai.h"

//����23��˳���ƣ����20��������
void suffle::shuffle_23(int cards[23]) {
	srand(time(NULL));
	for (int i = 22; i >= 0; i--) {
		int r = rand() % 23;
		int t = cards[i];
		cards[i] = cards[r];
		cards[r] = t;
	}
	for (int i = 0; i < 20; i++) {
		result_cards[i] = cards[i];
	}
}

//����20��˳���ƣ����20��������
void suffle::shuffle_20(int cards[20]) {
	srand(time(NULL));
	for (int i = 19; i >= 0; i--) {
		int r = rand() % 20;
		int t = cards[i];
		cards[i] = cards[r];
		cards[r] = t;
	}
	for (int i = 0; i < 20; i++) {
		result_cards[i] = cards[i];
	}
}

//�Ե���ʱ�����ƽ��в���
void suffle::time_card3(int cards[20], int purple_cards[7]) {
	//cards�������˳������������飬pruple_cards�������˳���л�����

	srand(time(NULL));
	for (int i = 6; i >= 0; i--) {
		int r = rand() % 7;
		int t = purple_cards[i];
		purple_cards[i] = purple_cards[r];
		purple_cards[r] = t;
	}
	shuffle_20(cards);
	//�滻�̻Ῠ��
	result_cards[0] = purple_cards[0];
	result_cards[1] = purple_cards[1];
	result_cards[2] = purple_cards[2];

	shuffle_20(result_cards);

	//���ؽ���ǿ��õ�������������������
}

//����8��˳���ƣ����8��������
void suffle::shuffle_8(int cards[8]) {
	srand(time(NULL));
	for (int i = 7; i >= 0; i--) {
		int r = rand() % 8;
		int t = cards[i];
		cards[i] = cards[r];
		cards[r] = t;
	}
	for (int i = 0; i < 8; i++) {
		result_cards8[i] = cards[i];
	}
}
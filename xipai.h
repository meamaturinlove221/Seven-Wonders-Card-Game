#pragma once

#include <time.h>
#include <stdlib.h>

class suffle {
public:
	
	int result_cards[20];
	int result_cards8[8];

	//suffle();

	//����12��˳���ƣ����12��������
	void shuffle_8(int cards[8]);

	//����23��˳���ƣ����20��������
	void shuffle_23(int cards[23]);

	//����20��˳���ƣ����20��������
	void shuffle_20(int cards[20]);

	//�Ե���ʱ�����ƽ��в���
	void time_card3(int cards[20], int purple_cards[7]);
};



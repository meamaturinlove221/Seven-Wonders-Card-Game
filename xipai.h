#pragma once

#include <time.h>
#include <stdlib.h>

class suffle {
public:
	int result_cards[20];

	//导入23张顺序牌，输出20张乱序牌
	void shuffle_23(int cards[23]);

	//导入20张顺序牌，输出20张乱序牌
	void shuffle_20(int cards[20]);

	//对第三时代卡牌进行操作
	void time_card3(int cards[20], int purple_cards[7]);
};



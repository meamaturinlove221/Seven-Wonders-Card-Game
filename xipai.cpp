#include"xipai.h"

//导入23张顺序牌，输出20张乱序牌
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

//导入20张顺序牌，输出20张乱序牌
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

//对第三时代卡牌进行操作
void suffle::time_card3(int cards[20], int purple_cards[7]) {
	//cards导入的是顺序第三世代牌组，pruple_cards导入的是顺序行会牌组

	srand(time(NULL));
	for (int i = 6; i >= 0; i--) {
		int r = rand() % 7;
		int t = purple_cards[i];
		purple_cards[i] = purple_cards[r];
		purple_cards[r] = t;
	}
	shuffle_20(cards);
	//替换商会卡牌
	result_cards[0] = purple_cards[0];
	result_cards[1] = purple_cards[1];
	result_cards[2] = purple_cards[2];

	shuffle_20(result_cards);

	//返回结果是可用第三世代乱序牌序数组
}

//导入8张顺序牌，输出8张乱序牌
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
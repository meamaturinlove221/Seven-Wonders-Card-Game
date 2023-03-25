#pragma once

#include "card.h"

class stage {
public:
	enum players {
		none = 0,
		blue,
		red
	};
	int fight_state;//战争情况
	//数组-场上发展标记
	int wonder_count; //计数-已被建造的奇迹数目
	vector<Time_Card> stage_cards; //场地卡牌表
	bool is_selected_card = false;//是否有卡牌被选中
	Time_Card* selected_card = nullptr;//被选中的卡牌,默认为空

	players last_player;//上回合最后开始回合的玩家
	players choise = none;
	int choosing = 0;//等待玩家选择标记,0未选择

	//结算判定哪方玩家选择开始回合的玩家
	void player_choosing_phase(int TIME);

	void player_choosing_phase_display();
	
	void player_choosing_phase_logic();

	void time1();
	void time2();
	void time3();
};
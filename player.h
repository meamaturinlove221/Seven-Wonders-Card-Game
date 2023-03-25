#include "card.h"

class player {
public:
	//数组-玩家已有牌库
	//数组-玩家已有科技符号及其数量
	//数组-玩家已有发展标记

	int can_pick_wonder_count; //玩家可取的奇迹数

	vector<wonder_card> wonder_cards;//玩家奇迹卡表
	vector<Time_Card> time_cards;//玩家时代卡表
	vector<int> player_technology_signs;//玩家已有科技符号

	//数据统计
	struct resource
	{
		int Clay = 0;//粘土
		int Wood = 0;//木头
		int Stone = 0;//石头
		int Glass = 0;//玻璃
		int Paper = 0;//纸张
		int War_sign = 0;//战争标记
	}Player_Resource = { 0,0,0,0,0 };//基础资源


	int money = 0;
	int score = 0;

	void player_resource_update();//更新玩家数据
	void player_score_update(Time_Card* a_time_card);//更新玩家分数
	void player_score_update(wonder_card* a_wonder_card);//更新玩家分数

	int check_resource(Time_Card* a_time_card);//检查玩家是否能选取时代牌，返回需要的金钱数
	int check_resource(wonder_card* a_wonder_card);//检查玩家是否能建造奇迹牌，返回需要的金钱数
	bool buy_card_with_resource(Time_Card* a_time_card);//尝试建造奇迹牌
	bool build_wonder(wonder_card* a_wonder_card);//尝试建造奇迹牌
};

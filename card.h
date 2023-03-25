#pragma once

#include"base.h"

class Game;
using namespace sf;
using namespace std;

enum Card_Color_list//卡牌颜色
{
	Brown = 0,
	Grey,
	Green,
	Blue,
	Red,
	Yellow,
	Purple
};

struct Time_card_list_node//内含一张时代牌的基础信息
{
	wstring card_name;//卡牌名字
	int color;//颜色
	unsigned int need_resource;//需求资源（二进制状态压缩）
	unsigned int provide_pesoure;//提供资源（二进制状态压缩）
	int card_score;//卡牌提供分数
	int update_avilibale_from;//升级索引
};

struct Wonder_card_list_node//内含一张时代牌的基础信息
{
	wstring card_name;//卡牌名字
	unsigned int need_resource;//需求资源（二进制状态压缩）
	unsigned int provide_pesoure;//提供资源（二进制状态压缩）
	int card_score;//卡牌提供分数
	bool select_again;//是否能提供再次抽卡
	bool destory_card;//是否能使对面的牌失效
};

class Time_Card//时代牌
{
public:

	//与Time_card_list_node的成员对应
	int Card_Bottom_Color;//卡牌种类
	
	unsigned int Card_Need_Resoure;//卡牌需求资源（二进制状态压缩）
	unsigned int Card_Provide_Resoure;//卡牌提供资源（二进制状态压缩）
	int score;//卡牌提供分数
	//int update_from;//卡牌升级索引

	Text Name;//卡牌名字
	Text info;//卡牌详细信息
	bool is_show_info = false;//是否放大卡牌显示详细信息

	int posX;
	int posY;

	int card_id;
	int player_selected;
	Sprite Stime_back;
	Texture Ttime_back;
	Sprite Stime_card;
	Texture Ttime_card;
	

	bool is_truned_up=true;
	bool is_picked = false;
	bool can_pick=false;


	Time_Card();
	~Time_Card();

	//输入对应代号从int中取出对应数值
	int get_Resource(int Resource_num, int from);

	bool clickedCheck(int x, int y);
};


class wonder_card {
public:
	int width = CARD_WONDER_WIDTH;
	int height = CARD_WONDER_HEIGHT;
	int card_id;
	int player_selected;//玩家选择
	int posX;
	int posY;
	bool is_build;//是否建成
	Texture Twonder;//卡牌贴图
	Sprite Swonder; //精灵

	unsigned int Card_Need_Resoure;//卡牌需求资源（二进制状态压缩）
	unsigned int Card_Provide_Resoure;//卡牌提供资源（二进制状态压缩）
	int score;//卡牌提供分数
	bool select_again;//是否能提供再次抽卡
	bool destory_card;//是否能使对面的牌失效

	wonder_card();
	~wonder_card();
	bool clickedCheck(int x, int y);
	//输入对应代号从int中取出对应数值
	int get_Resource(int Resource_num, int from);
};
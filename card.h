#pragma once

#include"base.h"

class Game;
using namespace sf;
using namespace std;

#define CARD_WIDTH 90//卡牌宽度
#define CARD_HEIGHT 160//卡牌高度
#define CHARACTER_SIZE 25//字体大小
#define INFO_SCALE 3//卡牌被点击后放大系数

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

class Time_Card//时代牌
{
public:
	RectangleShape Base;//卡牌底面矩形
	Sprite Card_Cost_Sprite;//卡牌消耗标志精灵
	vector<Sprite>	Card_Sign;//卡牌标记

	//与Time_card_list_node的成员对应
	int Card_Bottom_Color;//卡牌底面颜色
	Text Name;//卡牌名字
	unsigned int Card_Need_Resoure;//卡牌需求资源（二进制状态压缩）
	unsigned int Card_Provide_Resoure;//卡牌提供资源（二进制状态压缩）
	int score;//卡牌提供分数
	int update_from;//卡牌升级索引

	Text info;//卡牌详细信息
	bool is_show_info = false;//是否放大卡牌显示详细信息

public:
	Time_Card(Time_card_list_node a_time_card_basic_info);
	~Time_Card();

	//颜色enum转换为RGB值
	Vector3i Transfrom_Color_enum(int a_color);

	//设定卡牌及其各个元素的设置
	void Set_Card_Condition(Game* a_game);

	//测试 输入对应代号从int中取出对应数值
	int get_Resource(int Resource_num, int from);

	//在指定位置绘制
	void Draw(Vector2i position, Game* a_game);

	//判断鼠标是不是在按钮内
	void checkMouse(Event event, Game* a_game);

	//显示卡牌详细信息
	void show_info_outside(Game* a_game);

	//绘制选中状态的卡牌
	void Draw_selected(Game* a_game);
};

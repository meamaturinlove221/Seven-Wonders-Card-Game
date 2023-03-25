#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
#include <vector>

using namespace sf;
using namespace std;

#define CARD_WIDTH 10//卡牌宽度
#define CARD_HEIGHT 20//卡牌高度

enum technology_sign//科技符号
{
	Triangle = 0b0,//三角
	Wheel,//车轮
	pen_and_ink,//笔墨
	pestle_and_mortar,//药臼
	wifi,
	planetarium //天象仪
};

enum Resource//基础资源
{
	 Clay = 0b0,//粘土
	 Wood ,//木头
	 Stone,//石头
	 Glass,//玻璃
	 Paper,//纸张
	 Money,//金币
	 War_sign//战争标记
};

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
	string card_name;//卡牌名字
	int color;//颜色
	unsigned int need_resource;//需求资源（二进制状态压缩）
	unsigned int provide_pesoure;//提供资源（二进制状态压缩）
	int card_score;//卡牌提供分数
	int update_avilibale_from;//升级索引
};


class Time_Card//时代牌
{
private:
	Sprite Card_Botton_Sprite;//卡牌底面精灵
	Sprite Card_Cost_Sprite;//卡牌消耗标志精灵
	vector<Sprite>	Card_Sign;//卡牌标记

	//与Time_card_list_node的成员对应
	int Card_Botton_Color;//卡牌底面颜色
	string Name;//卡牌名字
	unsigned int Card_Need_Resoure;//卡牌需求资源（二进制状态压缩）
	unsigned int Card_Provide_Resoure;//卡牌提供资源（二进制状态压缩）
	int score;//卡牌提供分数
	int update_from;//卡牌升级索引

	int Card_Width = CARD_WIDTH;//卡牌宽度
	int Card_Height = CARD_HEIGHT;//卡牌高度
	int Card_x;//卡牌位置x坐标
	int Card_y;//卡牌位置y坐标

public:
	Time_Card(Time_card_list_node a_time_card_basic_info);
	~Time_Card();

	//设定卡牌位置
	void Set_Card_Position(int x, int y);

	//纹理传入精灵对象
	void load_source(Texture* texture_put_in);

	//测试 输入对应代号从bitset<25>中取出对应数值
	int get_Resource(int Resource_num, int from);
};

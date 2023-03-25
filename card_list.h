#pragma once

#include"card.h"
#include<string>

struct Time_card_list_node//内含一张时代牌的基础信息
{
	string card_name;//卡牌名字
	int color;//颜色
	Resource need_resource;//需求资源
	Resource provide_pesoure;//提供资源
	int provide_points;//提供分数

};
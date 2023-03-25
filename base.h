#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "xipai.h"

#define WINDOW_WIDTH	1600
#define WINDOW_HEIGHT	900
#define PLAYER_BLUE_LINE 400//蓝色玩家区域
#define PLAYER_RED_LINE 400//红色玩家区域
#define MAX_CARD_IN_LINE 5//一排卡牌最多放几张
#define CARD_BEWTEEN_X 10//卡牌横向间隔距离
#define CARD_BEWTEEN_Y 0//卡牌纵向间隔距离
#define CARD_INFO_X 1300//卡牌具体信息X
#define CARD_INFO_Y 700//卡牌具体信息Y

#define CARD_WIDTH 90//卡牌宽度4
#define CARD_HEIGHT 135//卡牌高度6
#define CHARACTER_SIZE 25//字体大小
#define INFO_SCALE 3//卡牌被点击后放大系数

#define CARD_WONDER_WIDTH  225 //奇迹牌宽
#define CARD_WONDER_HEIGHT  135 //奇迹牌高
#define CARD_WONDER_BETWEEN_X 70
#define CARD_WONDER_BETWEEN_Y 10
#define WONDER_SCALE 0.6

#define RED_PUSH_IN_X_LEFT 1200//红方玩家卡牌放入响应区域
#define RED_PUSH_IN_X_RIGHT 1600
#define RED_PUSH_IN_Y_UP 440
#define RED_PUSH_IN_Y_DOWN 150

#define BLUE_PUSH_IN_X_LEFT 0//蓝方玩家卡牌放入响应区域
#define BLUE_PUSH_IN_X_RIGHT 400
#define BLUE_PUSH_IN_Y_UP 440
#define BLUE_PUSH_IN_Y_DOWN 150

#define RED_SELL_X_LEFT 1200//红方玩家卡牌出售响应区域
#define RED_SELL_X_RIGHT 1350
#define RED_SELL_Y_UP 149
#define RED_SELL_Y_DOWN 0

#define BLUE_SELL_X_LEFT 250//蓝方玩家卡牌出售响应区域
#define BLUE_SELL_X_RIGHT 400
#define BLUE_SELL_Y_UP 149
#define BLUE_SELL_Y_DOWN 0

#define COIN_POSX 250
#define COIN_POSY 0
#define COIN_SIZE 150
#define START_MONEY 10 //双方开局拥有的金钱量

#define MONEY_NUM_RED_X	1275
#define MONEY_NUM_RED_Y	70
#define MONEY_NUM_BLUE_X 325	
#define MONEY_NUM_BLUE_Y 70	

#define TECHNOLOGY_SIZE 42//科技符号大小

#define EVERY_RESOURCE_COST 2//购买一份资源需要的金币数

#define TIME_CARD_SCORE 1//获得一张时代卡加分
#define WONDER_CARD_SCORE 2//建起一张奇迹卡加分
#define MAX_WONDERS 7 //场上最多能建起的奇迹牌

enum technology_sign//科技符号
{
	None = 0,//没有
	Triangle,//三角
	Wheel,//车轮
	pen_and_ink,//笔墨
	pestle_and_mortar,//药臼
	wifi,
	planetarium //天象仪
};

enum Resource//基础资源
{
	Clay = 0b0,//粘土
	Wood,//木头
	Stone,//石头
	Glass,//玻璃
	Paper,//纸张
	Money,//金币
	War_sign//战争标记
};



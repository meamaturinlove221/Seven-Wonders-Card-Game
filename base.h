#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <time.h>
#include <stdlib.h>

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



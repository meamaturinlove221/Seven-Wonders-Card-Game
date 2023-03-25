#pragma once

#include"card.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
#include <vector>

#define PLAYER_BLUE_LINE 400//蓝色玩家区域
#define PLAYER_RED_LINE 400//蓝色玩家区域

using namespace sf;
using namespace std;

class Game
{
public:
	RenderWindow window;//窗口对象
	bool Game_Over;//游戏是否结束
	bool Game_Quit;//游戏是否退出
	bool Is_Game_Begin;//游戏是否开始
	int Is_Game_Over_State;//游戏结束的状态
	int Window_Width;//窗口宽度
	int Window_Height;//窗口高度
	int Stage_Width;//舞台宽度
	int Stage_Height;//舞台高度

	string Background_Image_Name;//背景图片名
	Texture Background_Texture;//背景图片纹理对象
	Sprite Background_Sprite;//背景图片精灵对象

	Game();
	~Game();

	//游戏类对象初始化
	void Game_Initail();

	//加载媒体资源
	void Load_Meida_Data();

	//游戏运行
	void Run();

	//游戏输入
	void Input();

	//总绘制函数
	void Draw();

	//鼠标在玩家区域
	void Draw_of_MouseMoving();
};
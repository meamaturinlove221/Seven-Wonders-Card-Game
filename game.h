#pragma once

#include"stage.h"

#define WINDOW_WIDTH	1600
#define WINDOW_HEIGHT	900
#define PLAYER_BLUE_LINE 400//蓝色玩家区域
#define PLAYER_RED_LINE 400//蓝色玩家区域
#define MAX_CARD_IN_LINE 5//一排卡牌最多放几张
#define CARD_BEWTEEN_X 100//卡牌横向间隔距离
#define CARD_BEWTEEN_Y 200//卡牌纵向间隔距离
#define CARD_INFO_X 1300//卡牌具体信息X
#define CARD_INFO_Y 700//卡牌具体信息Y

using namespace sf;
using namespace std;

extern Time_card_list_node* Time_card_list;

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
	Vector2i Stage_cards_coner;//舞台卡牌分布左顶点

	stage the_stage;//舞台实例

	string Background_Image_Name;//背景图片名
	Texture Background_Texture;//背景图片纹理对象
	Sprite Background_Sprite;//背景图片精灵对象
	Font font;//字体对象

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

	//鼠标在玩家区域
	void Draw_of_MouseMoving();

	//绘制所有在舞台上的卡牌
	void Draw_stage_cards();	

	//总绘制函数
	void Draw();
};
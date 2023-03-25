#pragma once
#include"player.h"

using namespace sf;
using namespace std;


extern Time_card_list_node* Time_card_list;
extern Wonder_card_list_node* Wonder_card_list;

class Game
{
public:
	RenderWindow window;//窗口对象
	int Window_Width;//窗口宽度
	int Window_Height;//窗口高度

	bool Game_Over;//游戏是否结束
	bool Game_Quit;//游戏是否退出
	bool Is_Game_Begin;//游戏是否开始
	int Is_Game_Over_State;//游戏结束的状态

	bool choosing = false;//游戏阶段标记-等待玩家选择,0未选择
	int selecting_wonders; //游戏阶段标记-选择奇迹阶段 1为第一轮，2为第二轮
	int time_phase; //游戏阶段标记-当前时代 1为时代1 2为时代2，3为时代3
	bool destroy_card_mode;//碎牌模式

	int Stage_Width;//舞台宽度
	int Stage_Height;//舞台高度
	Vector2i Stage_cards_coner;//舞台卡牌分布左顶点

	Texture Background_Texture;//背景图片纹理对象
	Sprite Background_Sprite;//背景图片精灵对象
	Font font;//字体对象

	Texture Battle_Texture;//冲突指示物纹理对象
	Sprite Battle_Sprite;//冲突指示物精灵对象
	Texture War_Texture;//战争标记纹理对象
	Sprite War_Sprite;//战争标记精灵对象

	Text action_bar; //快捷信息文字栏
	Text arrow_text;//箭头文字
	Texture Tarrow;//箭头材质
	Sprite Sarrow; //箭头精灵

	//科技符号
	Texture Triangle_Texture;//三角
	Texture	Wheel_Texture;//车轮
	Texture	pen_and_ink_Texture;//笔墨
	Texture pestle_and_mortar_Texture;//药臼
	Sprite Triangle_Sprite;
	Sprite Wheel_Sprite;
	Sprite pen_and_ink_Sprite;
	Sprite pestle_and_mortar_Sprite;

	//资源符号
	Texture Clay_Texture;//粘土
	Texture Glass_Texture;//玻璃
	Texture	Paper_Texture;//纸
	Texture	Stone_Texture;//石头
	Texture Wood_Texture;//木头
	Sprite Clay_Sprite_red;
	Sprite Glass_Sprite_red;
	Sprite Paper_Sprite_red;
	Sprite Stone_Sprite_red;
	Sprite Wood_Sprite_red;
	Sprite Clay_Sprite_blue;
	Sprite Glass_Sprite_blue;
	Sprite Paper_Sprite_blue;
	Sprite Stone_Sprite_blue;
	Sprite Wood_Sprite_blue;

	Text phase_text; //文字-当前阶段

	Text money_num_red;//红色金钱文字
	Text money_num_blue;//蓝色金钱文字

	Text resouce_text_red;//资源文字
	Text resouce_text_blue;

	vector<Sprite*> sprite_to_draw; //draw函数中，需要绘制的精灵指针列表

	enum players {
		none = 0,
		blue,
		red
	};
	players last_player;//上回合最后开始回合的玩家
	players choiser = none; //正在进行选择的玩家

	player red_player, blue_player;

	int time_now;
	int fight_state;//战争情况
	int wonder_count; //计数-已被建造的奇迹数目
	vector<Time_Card> stage_cards; //场地卡牌表
	vector<Time_Card> destoryed_cards; //破坏卡牌表

	int wonders_at_stage;
	int wonders_to_select[8]; //奇迹牌组-id,可能乱序
	wonder_card wonder_cards[8]; //导入的奇迹卡表

	int time_to_select[20]; //时代牌组-id,可能乱序
	Time_Card time_cards[20]; //导入的时代卡表

	bool is_selected_card = false;//是否有卡牌被选中
	Time_Card* selected_card = nullptr;//被选中的卡牌,默认为空
	Sprite Scoin_box_blue;
	Sprite Scoin_box_red;
	Texture Tcoin_box;
	Texture Tcoin;
	Sprite Scoin_blue;
	Sprite Scoin_red;


	Game();
	~Game();

	//游戏类对象初始化
	void Game_Initail();

	//加载基础资源
	void Load_Data();

	//游戏运行
	void Run();

	//鼠标操作属性
	bool leftClicked, rightClicked;
	bool LisPressed = false;
	bool RisPressed = false;
	int LpressX = -1;
	int LpressY = -1;
	int RpressX = -1;
	int RpressY = -1;
	Vector2i mouse_position;//实时鼠标位置
	//游戏输入
	void Input();

	//鼠标在玩家区域
	void Draw_of_MouseMoving();

	//总绘制函数
	void Draw();
	void Draw_select_wonders(); //奇迹选择阶段，绘制场地奇迹牌
	void Draw_times();	//时代阶段，绘制场地时代牌
	void Draw_player_res();//绘制玩家资源图标
	void Draw_player_wonder_cards();//绘制玩家手中奇迹牌
	void Draw_player_time_cards();//绘制玩家手中时代牌
	void Draw_player_tec_sign();//玩家手中的科技符号


	//游戏主逻辑函数
	void logic();
	void check_cards_condition();//检查场地牌情况
	bool select_card(player &a_player);//玩家尝试获取时代牌
	void sell_card(player &a_player);//玩家卖出时代牌
	bool build_wonder_card(player& a_player);//玩家尝试建造奇迹牌
	bool destory_mode(player& a_player);//碎牌模式
	bool is_win();//胜负判断
	//结算判定哪方玩家选择开始回合的玩家
	void player_choosing_phase(int TIME);
	void player_choosing_phase_logic();

	void time1();	//时代函数
};
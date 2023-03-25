#include"stage.h"

void stage::player_choosing_phase(int TIME) {
	//结算判定哪方玩家选择开始回合的玩家
	if (TIME == 1) {
		//随机玩家选择
		srand(time(NULL));
		int r = rand() % 2;
		if (r == 0) {
			choise = blue;
		}
		else {
			choise = red;
		}
	}
	else if (TIME >= 2) {
		//第一判据：战争标记
		if (fight_state > 0) {
			choise = red;
		}
		else if (fight_state < 0) {
			choise = blue;
		}
		//第二判据：最后拿牌（最后进行回合的玩家）
		if (fight_state == 0) {
			choise = last_player;
		}
	}
	choosing = 1;
}
void stage::player_choosing_phase_display()
{
	//if (choosing == 1) {
	//	//展示信息：由红/蓝方选择开始游戏的一方
	//    //展示常驻信息：红/蓝方选择中……
	//	//鼠标在蓝色玩家区域
	//	if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= PLAYER_BLUE_LINE && mouse_position.x >= 0))
	//	{
	//		RectangleShape rect(Vector2f(PLAYER_BLUE_LINE, Window_Height));//设置大小
	//		rect.setPosition(Vector2f(0, 0));//设置位置
	//		rect.setFillColor(Color(0, 0, 255, 158));//设置颜色
	//		window.draw(rect);//绘制rect
	//	}

	//	//鼠标在红色玩家区域
	//	if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= Window_Width && mouse_position.x >= Window_Width - PLAYER_RED_LINE))
	//	{
	//		RectangleShape rect(Vector2f(PLAYER_RED_LINE, Window_Height));//设置大小
	//		rect.setPosition(Vector2f(Window_Width - PLAYER_RED_LINE, 0));//设置位置
	//		rect.setFillColor(Color(255, 0, 0, 158));//设置颜色
	//		window.draw(rect);//绘制rect
	//	}
	//}

}
void stage::player_choosing_phase_logic() {
	do {
		//鼠标点击 修改choise值


	} while (choise == blue || choise == red);
	choosing = 0;
	//开始玩家回合
	if (choise == blue) {
		//player_blue.player_turn;
	}
	else if (choise == red) {
		//player_red.player_turn;
	}
}
void stage::time1() {
	//发牌
	player_choosing_phase(1);//回合选择
}
void stage::time2() {

	//发牌
	player_choosing_phase(2);//回合选择

}
void stage::time3() {
	//发牌
	player_choosing_phase(3);//回合选择

}
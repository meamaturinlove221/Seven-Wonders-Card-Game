#include"game.h"

using namespace sf;
using namespace std;

Game::Game()
{
	Window_Width = WINDOW_WIDTH;
	Window_Height = WINDOW_HEIGHT;
	Uint32 my_style = Style::Close;//窗口风格：禁止改变窗口大小
	window.create(VideoMode(Window_Width, Window_Height), L"七大奇迹：对决", my_style);
	window.setFramerateLimit(60);//设置窗口对象帧数
	window.setPosition(Vector2i(100, 100));//设置窗口位置
	Load_Data();//加载素材
}

Game::~Game() {}

void Game::Load_Data()
{
	if ((!font.loadFromFile("data/fonts/SourceHanSansHWSC-Regular.otf")))//加载字体
	{
		cout << "字体没有找到" << endl;
	}

	//加载背景纹理图片
	if (!Background_Texture.loadFromFile("data/images/table.png"))
	{
		cout << "没有找到" << endl;
	}
	//ss.str("");//清空字符串

	Background_Sprite.setTexture(Background_Texture);

	if (!Tarrow.loadFromFile("data/images/arrow.png"))
	{
		cout << "箭头 " << " 没有找到" << endl;
	}
	Sarrow.setTexture(Tarrow);

	if (!Battle_Texture.loadFromFile("data/images/battle.jpg"))
	{
		cout << "冲突指示物 " << " 没有找到" << endl;
	}
	Battle_Sprite.setTexture(Battle_Texture);
	Battle_Sprite.setOrigin(Battle_Sprite.getLocalBounds().width / 2.0, Battle_Sprite.getLocalBounds().height / 2.0);
	Battle_Sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - Battle_Sprite.getLocalBounds().height / 2.0);

	if (!War_Texture.loadFromFile("data/images/war.png"))
	{
		cout << "战争标记 " << " 没有找到" << endl;
	}
	War_Sprite.setTexture(War_Texture);
	War_Sprite.setScale(1.0 / 6, 1.0 / 6);
	War_Sprite.setOrigin(War_Sprite.getLocalBounds().width / 2.0, War_Sprite.getLocalBounds().height / 2.0);
	War_Sprite.setPosition(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT - Battle_Sprite.getLocalBounds().height / 2.0);

	if (!Triangle_Texture.loadFromFile("data/images/technology/Triangle.png"))
	{
		cout << "三角 " << " 没有找到" << endl;
	}
	if (!pen_and_ink_Texture.loadFromFile("data/images/technology/pen_and_ink.png"))
	{
		cout << "笔墨 " << " 没有找到" << endl;
	}
	if (!pestle_and_mortar_Texture.loadFromFile("data/images/technology/pestle_and_mortar.png"))
	{
		cout << "药臼 " << " 没有找到" << endl;
	}
	if (!Wheel_Texture.loadFromFile("data/images/technology/Wheel.png"))
	{
		cout << "轮子 " << " 没有找到" << endl;
	}
	pestle_and_mortar_Sprite.setTexture(pestle_and_mortar_Texture);
	pen_and_ink_Sprite.setTexture(pen_and_ink_Texture);
	Triangle_Sprite.setTexture(Triangle_Texture);
	Wheel_Sprite.setTexture(Wheel_Texture);
	pestle_and_mortar_Sprite.setScale(1.0 / 5, 1.0 / 5);
	pen_and_ink_Sprite.setScale(1.0 / 6, 1.0 / 6);
	Triangle_Sprite.setScale(1.0 / 6, 1.0 / 6);
	Wheel_Sprite.setScale(1.0 / 6, 1.0 / 6);

	if (!Clay_Texture.loadFromFile("data/images/Clay.png"))
	{
		cout << "粘土 " << " 没有找到" << endl;
	}
	if (!Glass_Texture.loadFromFile("data/images/Glass.png"))
	{
		cout << "玻璃 " << " 没有找到" << endl;
	}
	if (!Paper_Texture.loadFromFile("data/images/Paper.png"))
	{
		cout << "纸 " << " 没有找到" << endl;
	}
	if (!Wood_Texture.loadFromFile("data/images/Wood.png"))
	{
		cout << "木头 " << " 没有找到" << endl;
	}
	if (!Stone_Texture.loadFromFile("data/images/Stone.png"))
	{
		cout << "石头 " << " 没有找到" << endl;
	}
	//红方
	Clay_Sprite_red.setTexture(Clay_Texture);
	Glass_Sprite_red.setTexture(Glass_Texture);
	Paper_Sprite_red.setTexture(Paper_Texture);
	Wood_Sprite_red.setTexture(Wood_Texture);
	Stone_Sprite_red.setTexture(Stone_Texture);
	Clay_Sprite_red.setScale(1.0 / 6, 1.0 / 6);
	Glass_Sprite_red.setScale(1.0 / 6, 1.0 / 6);
	Paper_Sprite_red.setScale(1.0 / 6, 1.0 / 6);
	Wood_Sprite_red.setScale(1.0 / 6, 1.0 / 6);
	Stone_Sprite_red.setScale(1.0 / 6, 1.0 / 6);
	//蓝方
	Clay_Sprite_blue.setTexture(Clay_Texture);
	Glass_Sprite_blue.setTexture(Glass_Texture);
	Paper_Sprite_blue.setTexture(Paper_Texture);
	Wood_Sprite_blue.setTexture(Wood_Texture);
	Stone_Sprite_blue.setTexture(Stone_Texture);
	Clay_Sprite_blue.setScale(1.0 / 6, 1.0 / 6);
	Glass_Sprite_blue.setScale(1.0 / 6, 1.0 / 6);
	Paper_Sprite_blue.setScale(1.0 / 6, 1.0 / 6);
	Wood_Sprite_blue.setScale(1.0 / 6, 1.0 / 6);
	Stone_Sprite_blue.setScale(1.0 / 6, 1.0 / 6);

	action_bar.setFont(font);
	action_bar.setCharacterSize(CHARACTER_SIZE);
	action_bar.setStyle(Text::Regular);
	action_bar.setOrigin(0, 0);
	action_bar.setFillColor(Color(255, 0, 0));
	action_bar.setPosition(WINDOW_WIDTH / 2.0 - 150, 0);

	arrow_text.setFont(font);
	arrow_text.setCharacterSize(CHARACTER_SIZE);
	arrow_text.setStyle(Text::Regular);
	arrow_text.setOrigin(0, 0);
	arrow_text.setFillColor(Color(0, 0, 0));
	arrow_text.setPosition((WINDOW_WIDTH - PLAYER_BLUE_LINE * 2) / 2 - CHARACTER_SIZE * 3 + PLAYER_BLUE_LINE, CHARACTER_SIZE + 25);
	arrow_text.setString(L"当前操作玩家");

	money_num_blue.setFont(font);
	money_num_blue.setCharacterSize(CHARACTER_SIZE);
	money_num_blue.setStyle(Text::Regular);
	money_num_blue.setOrigin(money_num_blue.getLocalBounds().width / 2.0, money_num_blue.getLocalBounds().height / 2.0);
	money_num_blue.setFillColor(Color(0, 0, 0));

	money_num_red.setFont(font);
	money_num_red.setCharacterSize(CHARACTER_SIZE);
	money_num_red.setStyle(Text::Regular);
	money_num_red.setOrigin(money_num_red.getLocalBounds().width / 2.0, money_num_red.getLocalBounds().height / 2.0);
	money_num_red.setFillColor(Color(0, 0, 0));

	money_num_blue.setPosition(COIN_POSX + 75 - 15, COIN_POSY + 75 - 15);
	money_num_red.setPosition(1200 + 75 - 15, COIN_POSY + 75 - 15);

	resouce_text_red.setFont(font);
	resouce_text_red.setCharacterSize(CHARACTER_SIZE);
	resouce_text_red.setStyle(Text::Regular);
	resouce_text_red.setFillColor(Color(0, 0, 0));
	resouce_text_red.setPosition(1160 + TECHNOLOGY_SIZE, 855);

	resouce_text_blue.setFont(font);
	resouce_text_blue.setCharacterSize(CHARACTER_SIZE);
	resouce_text_blue.setStyle(Text::Regular);
	resouce_text_blue.setFillColor(Color(0, 0, 0));
	resouce_text_blue.setPosition(10 + TECHNOLOGY_SIZE, 855);

	if (!Tcoin_box.loadFromFile("data/images/coin_box.png"))
	{
		cout << "硬币盒子贴图 " << " 没有找到" << endl;
	}
	if (!Tcoin.loadFromFile("data/images/coin.png"))
	{
		cout << "硬币贴图 " << " 没有找到" << endl;
	}
	Scoin_box_blue.setTexture(Tcoin_box);
	Scoin_box_blue.setPosition(COIN_POSX, COIN_POSY);
	Scoin_box_red.setTexture(Tcoin_box);
	Scoin_box_red.setPosition(1200, COIN_POSY);

	Scoin_blue.setTexture(Tcoin);
	Scoin_blue.setPosition(COIN_POSX + 75 - 15, COIN_POSY + 75 - 15);
	Scoin_red.setTexture(Tcoin);
	Scoin_red.setPosition(1200 + 75 - 15, COIN_POSY + 75 - 15);

	//初始化奇迹卡组
	for (int i = 0; i < 8; i++) {
		stringstream ss;
		ss << "data/images/wonders/" << i << ".png";

		//加载背景纹理图片
		if (!wonder_cards[i].Twonder.loadFromFile(ss.str()))
		{
			cout << "奇迹卡 " << i << " 没有找到" << endl;
		}
		ss.str("");//清空字符串
		wonder_cards[i].card_id = i;
		wonder_cards[i].player_selected = 0;
		wonder_cards[i].Swonder.setTexture(wonder_cards[i].Twonder);
		wonder_cards[i].Card_Need_Resoure = Wonder_card_list[i].need_resource;
		wonder_cards[i].Card_Provide_Resoure = Wonder_card_list[i].provide_pesoure;
		wonder_cards[i].score = Wonder_card_list[i].card_score;
		wonder_cards[i].select_again = Wonder_card_list[i].select_again;
		wonder_cards[i].destory_card = Wonder_card_list[i].destory_card;
	}

	for (int i = 0; i < 20; i++) {
		stringstream ss;
		ss << "data/images/time/" << i << ".png";

		//加载背景纹理图片
		if (!time_cards[i].Ttime_card.loadFromFile(ss.str()))
		{
			cout << "时代卡 " << i << " 没有找到" << endl;
		}
		if (!time_cards[i].Ttime_back.loadFromFile("data/images/time/back.png"))
		{
			cout << "时代卡背面 " << " 没有找到" << endl;
		}
		ss.str("");//清空字符串
		time_cards[i].card_id = i;
		time_cards[i].player_selected = 0;
		time_cards[i].Stime_card.setTexture(time_cards[i].Ttime_card);
		time_cards[i].Stime_back.setTexture(time_cards[i].Ttime_back);
		time_cards[i].Card_Need_Resoure = Time_card_list[i].need_resource;
		time_cards[i].Card_Provide_Resoure = Time_card_list[i].provide_pesoure;
	}
}

void Game::Game_Initail()  //一局游戏的初始化
{
	Is_Game_Begin = true;
	Game_Quit = false;
	Game_Over = false;
	//该归零的归零
	fight_state = 0;
	wonder_count = 0;
	stage_cards.clear();
	last_player = none;
	destroy_card_mode = false;

	is_selected_card = false;
	selected_card = nullptr;

	//洗牌，获得奇迹数组
	suffle suffled_cards;
	for (int i = 0; i < 8; i++) {
		wonders_to_select[i] = i;
	}
	suffled_cards.shuffle_8(wonders_to_select);
	for (int i = 0; i < 8; i++) {
		wonders_to_select[i] = suffled_cards.result_cards8[i];
	}

	//进入选择奇迹的阶段一
	selecting_wonders = 1;
	wonders_at_stage = 4;
	// 随机出开始选择的玩家
	srand(time(NULL));
	int r = rand() % 2;
	if (r == 0) {
		choiser = blue;
		action_bar.setString(L"等待蓝方选择开始玩家……");
	}
	else {
		choiser = red;
		action_bar.setString(L"等待红方选择开始玩家……");
	}
	choosing = true;
	red_player.money = START_MONEY;
	blue_player.money = START_MONEY;

}

void Game::Input()
{
	Event event;
	mouse_position = Vector2i(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
	while (window.pollEvent(event))
	{

		if (event.type == Event::Closed)
		{
			delete[] Time_card_list;
			delete[] Wonder_card_list;
			window.close();
			Game_Quit = true;
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				LpressX = event.mouseButton.x;
				LpressY = event.mouseButton.y;
				LisPressed = true;

			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				RpressX = event.mouseButton.x;
				RpressY = event.mouseButton.y;
				RisPressed = true;
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (LpressX == event.mouseButton.x && LpressY == event.mouseButton.y)
				{
					leftClicked = true;
					//std::cout << "left" << std::endl;
					LisPressed = false;
				}
			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				if (RpressX == event.mouseButton.x && RpressY == event.mouseButton.y)
				{
					rightClicked = true;
					//std::cout << "Right" << std::endl;
					RisPressed = false;
				}
			}
		}
	}
}

void Game::logic() {
	if (Is_Game_Begin) {
		//选择开始玩家
		if (choosing && LisPressed)
		{
			if (LpressX < PLAYER_BLUE_LINE)
			{
				if (selecting_wonders == 1)
				{
					blue_player.can_pick_wonder_count = 1;
					red_player.can_pick_wonder_count = 2;
				}
				choiser = blue;
				action_bar.setString(L"蓝方玩家正在选择牌。");
				choosing = false;
			}
			if (LpressX > WINDOW_WIDTH - PLAYER_RED_LINE)
			{
				if (selecting_wonders == 1)
				{
					blue_player.can_pick_wonder_count = 2;
					red_player.can_pick_wonder_count = 1;
				}
				choiser = red;
				action_bar.setString(L"红方玩家正在选择牌。");
				choosing = false;
			}
			LisPressed = false;
		}

		//选择奇迹牌 前4张
		if (!choosing && selecting_wonders == 1)
		{
			if (LisPressed) {
				for (int i = 0; i < 4; i++) {
					if (wonder_cards[wonders_to_select[i]].player_selected == 0) {
						if (wonder_cards[wonders_to_select[i]].clickedCheck(LpressX, LpressY)) {
							//玩家建造这张牌
							//对牌的操作
							wonder_cards[wonders_to_select[i]].player_selected = choiser;
							wonder_cards[wonders_to_select[i]].Swonder.setScale(WONDER_SCALE, WONDER_SCALE);
							wonders_at_stage -= 1;
							//将牌划给玩家
							switch (choiser)
							{
							case red: {
								red_player.wonder_cards.push_back(wonder_cards[wonders_to_select[i]]);
								action_bar.setString(L"红方选择成功");
								red_player.can_pick_wonder_count -= 1;
								if (red_player.can_pick_wonder_count <= 0) {
									choiser = blue;
								}
								break;
							}
							case blue: {
								blue_player.wonder_cards.push_back(wonder_cards[wonders_to_select[i]]);
								action_bar.setString(L"蓝方选择成功");
								blue_player.can_pick_wonder_count -= 1;
								if (blue_player.can_pick_wonder_count <= 0) {
									choiser = red;
								}
								break;
							}
							default:
								break;
							}

						}
					}
				}
				LisPressed = false;
			}
			if (wonders_at_stage == 0) {
				selecting_wonders = 2;
				wonders_at_stage = 4;
				switch (choiser)
				{
				case Game::blue: {
					red_player.can_pick_wonder_count = 2;
					blue_player.can_pick_wonder_count = 1;
				}
							   break;
				case Game::red: {
					red_player.can_pick_wonder_count = 1;
					blue_player.can_pick_wonder_count = 2;
				}
							  break;
				default:
					break;
				}
			}
		}
		if (!choosing && selecting_wonders == 2) {
			int c = 0;
			if (LisPressed) {
				for (int i = 4; i < 8; i++) {
					if (wonder_cards[wonders_to_select[i]].player_selected == 0) {
						if (wonder_cards[wonders_to_select[i]].clickedCheck(LpressX, LpressY)) {
							wonder_cards[wonders_to_select[i]].player_selected = choiser;
							wonder_cards[wonders_to_select[i]].Swonder.setScale(WONDER_SCALE, WONDER_SCALE);
							wonders_at_stage -= 1;
							switch (choiser)
							{
							case red: {
								red_player.wonder_cards.push_back(wonder_cards[wonders_to_select[i]]);
								action_bar.setString(L"红方选择成功");
								red_player.can_pick_wonder_count -= 1;
								if (red_player.can_pick_wonder_count <= 0) {
									choiser = blue;
								}
								break;
							}
							case blue: {
								blue_player.wonder_cards.push_back(wonder_cards[wonders_to_select[i]]);
								action_bar.setString(L"蓝方选择成功");
								blue_player.can_pick_wonder_count -= 1;
								if (blue_player.can_pick_wonder_count <= 0) {
									choiser = red;
								}
								break;
							}
							default:
								break;
							}

						}
					}
				}
				LisPressed = false;
			}
			if (wonders_at_stage == 0) {
				time1();
			}
		}

		if (time_now == 1 && !choosing) {
			//检查场地牌情况
			check_cards_condition();

			if (is_selected_card) {
				selected_card->Stime_card.setPosition(mouse_position.x, mouse_position.y);
			}

			if (LisPressed) {
				if (!is_selected_card) {
					if (!destroy_card_mode)
					{
						for (int i = 0; i < 20; i++) {
							if (time_cards[time_to_select[i]].can_pick && time_cards[time_to_select[i]].clickedCheck(LpressX, LpressY)) {
								is_selected_card = true;
								selected_card = &time_cards[time_to_select[i]];
							}
						}
					}
					else
					{
						if (choiser == red)
						{
							for (int i = 0; i < blue_player.time_cards.size(); i++) {
								if (blue_player.time_cards[i].clickedCheck(LpressX, LpressY)) {
									is_selected_card = true;
									selected_card = &blue_player.time_cards[i];
								}
							}
						}
						else
						{
							for (int i = 0; i < red_player.time_cards.size(); i++) {
								if (red_player.time_cards[i].clickedCheck(LpressX, LpressY)) {
									is_selected_card = true;
									selected_card = &red_player.time_cards[i];
								}
							}
						}
					}
				}
				else {
					if (choiser == red)
					{
						if (destroy_card_mode)//碎牌模式
						{
							if (!destory_mode(red_player))
							{
								is_selected_card = false;
							}
							else
							{
								fight_state = blue_player.Player_Resource.War_sign - red_player.Player_Resource.War_sign;
								//切换玩家
								choiser = blue;
								is_selected_card = false;
							}
						}
						if (LpressX >= RED_PUSH_IN_X_LEFT && LpressX <= RED_PUSH_IN_X_RIGHT && LpressY >= RED_PUSH_IN_Y_DOWN && LpressY <= RED_PUSH_IN_Y_UP)
						{
							if (select_card(red_player))
							{
								action_bar.setString(L"红方选择成功");
								//切换玩家
								choiser = blue;
								is_selected_card = false;
							}


						}
						else if (LpressX >= RED_SELL_X_LEFT && LpressX <= RED_SELL_X_RIGHT && LpressY >= RED_SELL_Y_DOWN && LpressY <= RED_SELL_Y_UP)
						{
							sell_card(red_player);
							action_bar.setString(L"红方出售成功");
							//切换玩家
							choiser = blue;
							is_selected_card = false;
						}
						else
						{
							//建造奇迹
							build_wonder_card(red_player);
						}
					}
					else
					{
						if (destroy_card_mode)//碎牌模式
						{
							if (!destory_mode(blue_player))
							{
								is_selected_card = false;
							}
							else
							{
								//切换玩家
								fight_state = blue_player.Player_Resource.War_sign - red_player.Player_Resource.War_sign;
								choiser = red;
								is_selected_card = false;
							}
						}
						if (LpressX >= BLUE_PUSH_IN_X_LEFT && LpressX <= BLUE_PUSH_IN_X_RIGHT && LpressY >= BLUE_PUSH_IN_Y_DOWN && LpressY <= BLUE_PUSH_IN_Y_UP)
						{
							if (select_card(blue_player))
							{
								action_bar.setString(L"蓝方选择成功");
								//切换玩家
								choiser = red;
								is_selected_card = false;
							}

						}
						else if (LpressX >= BLUE_SELL_X_LEFT && LpressX <= BLUE_SELL_X_RIGHT && LpressY >= BLUE_SELL_Y_DOWN && LpressY <= BLUE_SELL_Y_UP)
						{
							sell_card(blue_player);
							action_bar.setString(L"蓝方出售成功");
							//切换玩家
							choiser = red;
							is_selected_card = false;
						}
						else
						{
							//建造奇迹
							build_wonder_card(blue_player);
						}
					}
				}
			}
			LisPressed = false;
		}
		//右键取消选择卡牌
		if (RisPressed && is_selected_card) {

			selected_card->Stime_card.setPosition(selected_card->posX, selected_card->posY);
			is_selected_card = false;
			RisPressed = false;
		}
		//计算战争标记
		fight_state = blue_player.Player_Resource.War_sign - red_player.Player_Resource.War_sign;
		int ft = 0;
		if (fight_state > 4) {
			ft = 4;
		}
		else if (fight_state < -4) {
			ft = -4;
		}
		else {
			ft = fight_state;
		}
		War_Sprite.setPosition(WINDOW_WIDTH / 2.0 + ft * 80, WINDOW_HEIGHT - Battle_Sprite.getLocalBounds().height / 2.0);

		stringstream ss;
		ss << blue_player.money;
		money_num_blue.setString(ss.str());
		ss.str("");//清空字符串
		ss << red_player.money;
		money_num_red.setString(ss.str());
		ss.str("");//清空字符串

		//文字方面的改动
		money_num_blue.setOrigin(money_num_blue.getLocalBounds().width / 2.0, money_num_blue.getLocalBounds().height / 2.0);
		money_num_red.setOrigin(money_num_red.getLocalBounds().width / 2.0, money_num_red.getLocalBounds().height / 2.0);
		money_num_blue.setPosition(MONEY_NUM_BLUE_X, MONEY_NUM_BLUE_Y);
		money_num_red.setPosition(MONEY_NUM_RED_X, MONEY_NUM_RED_Y);

		if (is_win())
		{
			choiser = none;
			Is_Game_Begin = false;
			cout << "is_win" << endl;
		}


	}
	else {

	}
}
void Game::player_choosing_phase(int TIME) {
	//结算判定哪方玩家选择开始回合的玩家
	if (TIME == 1) {
		//随机玩家选择
		srand(time(NULL));
		int r = rand() % 2;
		if (r == 0) {
			choiser = blue;
			action_bar.setString(L"等待蓝方选择开始玩家……");
		}
		else {
			choiser = red;
			action_bar.setString(L"等待红方选择开始玩家……");
		}
	}
	else if (TIME >= 2) {
		//第一判据：战争标记
		if (fight_state > 0) {
			choiser = red;
		}
		else if (fight_state < 0) {
			choiser = blue;
		}
		//第二判据：最后拿牌（最后进行回合的玩家）
		if (fight_state == 0) {
			choiser = last_player;
		}
	}
	choosing = 1;
}
void Game::player_choosing_phase_logic() {
	do {
		//鼠标点击 修改choise值


	} while (choiser == blue || choiser == red);
	choosing = 0;
	//开始玩家回合
	if (choiser == blue) {
		//player_blue.player_turn;
	}
	else if (choiser == red) {
		//player_red.player_turn;
	}
}
void Game::time1() {
	selecting_wonders = -1;
	time_now = 1;//进入时代一
	//洗牌，获得时代数组
	suffle suffled_cards;
	for (int i = 0; i < 20; i++) {
		time_to_select[i] = i;
	}
	suffled_cards.shuffle_20(time_to_select);
	for (int i = 0; i < 20; i++) {
		time_to_select[i] = suffled_cards.result_cards[i];
	}

	//发牌,绘制位置
	for (int i = 0; i < 6; i++) {
		time_cards[time_to_select[i]].posX = 95 + CARD_BEWTEEN_X + PLAYER_BLUE_LINE + (CARD_BEWTEEN_X + CARD_WIDTH) * (i % 6);
		time_cards[time_to_select[i]].posY = 120;
		time_cards[time_to_select[i]].Stime_card.setPosition(time_cards[time_to_select[i]].posX, time_cards[time_to_select[i]].posY);
	}
	for (int i = 6; i < 11; i++) {
		time_cards[time_to_select[i]].posX = 95 + 0.5 * CARD_WIDTH + CARD_BEWTEEN_X + PLAYER_BLUE_LINE + (CARD_BEWTEEN_X + CARD_WIDTH) * ((i - 6) % 6);
		time_cards[time_to_select[i]].posY = 120 + 0.5 * CARD_HEIGHT;
		time_cards[time_to_select[i]].Stime_card.setPosition(time_cards[time_to_select[i]].posX, time_cards[time_to_select[i]].posY);
		time_cards[time_to_select[i]].Stime_back.setPosition(time_cards[time_to_select[i]].posX, time_cards[time_to_select[i]].posY);
		time_cards[time_to_select[i]].is_truned_up = false;
	}
	for (int i = 11; i < 15; i++) {
		time_cards[time_to_select[i]].posX = 95 + CARD_WIDTH + CARD_BEWTEEN_X + PLAYER_BLUE_LINE + (CARD_BEWTEEN_X + CARD_WIDTH) * ((i - 11) % 6);
		time_cards[time_to_select[i]].posY = 120 + CARD_HEIGHT;
		time_cards[time_to_select[i]].Stime_card.setPosition(time_cards[time_to_select[i]].posX, time_cards[time_to_select[i]].posY);
	}
	for (int i = 15; i < 18; i++) {
		time_cards[time_to_select[i]].posX = 95 + 1.5 * CARD_WIDTH + CARD_BEWTEEN_X + PLAYER_BLUE_LINE + (CARD_BEWTEEN_X + CARD_WIDTH) * ((i - 15) % 6);
		time_cards[time_to_select[i]].posY = 120 + 1.5 * CARD_HEIGHT;
		time_cards[time_to_select[i]].Stime_card.setPosition(time_cards[time_to_select[i]].posX, time_cards[time_to_select[i]].posY);
		time_cards[time_to_select[i]].Stime_back.setPosition(time_cards[time_to_select[i]].posX, time_cards[time_to_select[i]].posY);
		time_cards[time_to_select[i]].is_truned_up = false;
	}
	for (int i = 18; i < 20; i++) {
		time_cards[time_to_select[i]].posX = 95 + 2 * CARD_WIDTH + CARD_BEWTEEN_X + PLAYER_BLUE_LINE + (CARD_BEWTEEN_X + CARD_WIDTH) * ((i - 18) % 6);
		time_cards[time_to_select[i]].posY = 120 + 2 * CARD_HEIGHT;
		time_cards[time_to_select[i]].Stime_card.setPosition(time_cards[time_to_select[i]].posX, time_cards[time_to_select[i]].posY);
		time_cards[time_to_select[i]].can_pick = true;
	}

	player_choosing_phase(1);//回合选择
}
void Game::sell_card(player& a_player)//卖出时代牌
{
	a_player.money += 3;
	//destory card
	selected_card->can_pick = false;
	selected_card->is_picked = true;
	is_selected_card = false;
	choiser = blue;
	selected_card->player_selected = 1;
	destoryed_cards.push_back(*selected_card);
}
bool Game::select_card(player& a_player)//玩家尝试获取时代牌
{
	//花费资源购买卡牌
	if (a_player.buy_card_with_resource(selected_card))
	{
		//将牌放入红色玩家牌堆
		selected_card->player_selected = choiser;
		selected_card->can_pick = false;
		selected_card->is_picked = true;
		a_player.time_cards.push_back(*selected_card);
		//更新玩家拥有的资源
		a_player.player_resource_update();
		a_player.player_score_update(selected_card);
		return true;
	}
	else
	{
		action_bar.setString(L"金钱不足");
		selected_card->Stime_card.setPosition(selected_card->posX, selected_card->posY);
		is_selected_card = false;
		RisPressed = false;
		return false;
	}
}
bool Game::build_wonder_card(player& a_player)//玩家尝试建造奇迹牌
{
	int already_build_wonders = 0;//已经建造的奇迹牌数量
	//建造奇迹
	for (int i = 0; i < a_player.wonder_cards.size(); i++)
	{
		if (LpressX >= a_player.wonder_cards[i].posX && LpressX <= a_player.wonder_cards[i].posX + CARD_WONDER_WIDTH * WONDER_SCALE &&
			LpressY >= a_player.wonder_cards[i].posY && LpressY <= a_player.wonder_cards[i].posY + CARD_WONDER_HEIGHT * WONDER_SCALE)
		{
			for (int i = 0; i < red_player.wonder_cards.size(); i++)
			{
				if (red_player.wonder_cards[i].is_build)
				{
					already_build_wonders++;
				}
			}
			for (int i = 0; i < blue_player.wonder_cards.size(); i++)
			{
				if (blue_player.wonder_cards[i].is_build)
				{
					already_build_wonders++;
				}
			}
			if (already_build_wonders >= MAX_WONDERS)
			{
				action_bar.setString(L"已建造奇迹数量大于7 无法建造");
				selected_card->Stime_card.setPosition(selected_card->posX, selected_card->posY);
				is_selected_card = false;
				RisPressed = false;
				return false;
			}
			else
			{
				if (a_player.build_wonder(&a_player.wonder_cards[i]))
				{
					a_player.wonder_cards[i].is_build = true;
					a_player.player_resource_update();
					a_player.player_score_update(&a_player.wonder_cards[i]);
					selected_card->can_pick = false;
					selected_card->is_picked = true;
					selected_card->player_selected = 1;
					destoryed_cards.push_back(*selected_card);

					if (a_player.wonder_cards[i].select_again)
					{
						//如果建造的时代牌有再次选牌的效果
						if (&a_player == &blue_player)
						{
							action_bar.setString(L"蓝方建造奇迹，可以再次选牌");
						}
						else
						{
							action_bar.setString(L"红方建造奇迹，可以再次选牌");
						}
						is_selected_card = false;
					}
					else if (a_player.wonder_cards[i].destory_card)
					{
						if (&a_player == &blue_player)
						{
							if (red_player.time_cards.size() == 0)
							{
								//对面手上没有时代牌
								action_bar.setString(L"蓝方建造奇迹，对手没有时代牌可以销毁");
								destroy_card_mode = false;
								//切换玩家
								if (choiser == blue)
								{
									choiser = red;
									is_selected_card = false;
								}
								else
								{
									choiser = blue;
									is_selected_card = false;
								}
							}
							else
							{
								action_bar.setString(L"蓝方建造奇迹，可以销毁一张对手时代牌");
								destroy_card_mode = true;
							}
						}
						else
						{
							if (blue_player.time_cards.size() == 0)
							{
								//对面手上没有时代牌
								action_bar.setString(L"红方建造奇迹，对手没有时代牌可以销毁");
								destroy_card_mode = false;
								//切换玩家
								if (choiser == blue)
								{
									choiser = red;
									is_selected_card = false;
								}
								else
								{
									choiser = blue;
									is_selected_card = false;
								}
							}
							else
							{
								action_bar.setString(L"红方建造奇迹，可以销毁一张对手时代牌");
								destroy_card_mode = true;
							}
						}
					}
					else
					{
						if (&a_player == &blue_player)
						{
							action_bar.setString(L"蓝方建造奇迹");
						}
						else
						{
							action_bar.setString(L"红方建造奇迹");
						}
						//切换玩家
						if (choiser == blue)
						{
							choiser = red;
							is_selected_card = false;
						}
						else
						{
							choiser = blue;
							is_selected_card = false;
						}
					}
					return true;
				}
				else
				{
					action_bar.setString(L"建造奇迹资源不足");
					selected_card->Stime_card.setPosition(selected_card->posX, selected_card->posY);
					is_selected_card = false;
					RisPressed = false;
					return false;
				}
			}

		}
	}
	return false;
}
void Game::check_cards_condition()//检查场地牌情况
{
	if (time_cards[time_to_select[6]].is_picked && !time_cards[time_to_select[0]].is_picked) {
		time_cards[time_to_select[0]].can_pick = true;
		time_cards[time_to_select[0]].is_truned_up = true;
	}
	for (int i = 1; i < 5; i++) {
		if (time_cards[time_to_select[i + 5]].is_picked && time_cards[time_to_select[i + 6]].is_picked && !time_cards[time_to_select[i]].is_picked) {
			time_cards[time_to_select[i]].can_pick = true;
			time_cards[time_to_select[i]].is_truned_up = true;
		}
	}
	if (time_cards[time_to_select[10]].is_picked && !time_cards[time_to_select[5]].is_picked) {
		time_cards[time_to_select[5]].can_pick = true;
		time_cards[time_to_select[5]].is_truned_up = true;
	}
	if (time_cards[time_to_select[11]].is_picked && !time_cards[time_to_select[6]].is_picked) {
		time_cards[time_to_select[6]].can_pick = true;
		time_cards[time_to_select[6]].is_truned_up = true;
	}
	for (int i = 7; i < 10; i++) {
		if (time_cards[time_to_select[i + 4]].is_picked && time_cards[time_to_select[i + 5]].is_picked && !time_cards[time_to_select[i]].is_picked) {
			time_cards[time_to_select[i]].can_pick = true;
			time_cards[time_to_select[i]].is_truned_up = true;
		}
	}
	if (time_cards[time_to_select[15]].is_picked && !time_cards[time_to_select[11]].is_picked) {
		time_cards[time_to_select[11]].can_pick = true;
		time_cards[time_to_select[11]].is_truned_up = true;
	}
	for (int i = 12; i < 14; i++) {
		if (time_cards[time_to_select[i + 3]].is_picked && time_cards[time_to_select[i + 4]].is_picked && !time_cards[time_to_select[i]].is_picked) {
			time_cards[time_to_select[i]].can_pick = true;
			time_cards[time_to_select[i]].is_truned_up = true;
		}
	}
	if (time_cards[time_to_select[14]].is_picked && !time_cards[time_to_select[10]].is_picked) {
		time_cards[time_to_select[10]].can_pick = true;
		time_cards[time_to_select[10]].is_truned_up = true;
	}
	if (time_cards[time_to_select[17]].is_picked && !time_cards[time_to_select[14]].is_picked) {
		time_cards[time_to_select[14]].can_pick = true;
		time_cards[time_to_select[14]].is_truned_up = true;
	}
	if (time_cards[time_to_select[18]].is_picked && !time_cards[time_to_select[15]].is_picked) {
		time_cards[time_to_select[15]].can_pick = true;
		time_cards[time_to_select[15]].is_truned_up = true;
	}
	if (time_cards[time_to_select[18]].is_picked && time_cards[time_to_select[19]].is_picked && !time_cards[time_to_select[16]].is_picked) {
		time_cards[time_to_select[16]].can_pick = true;
		time_cards[time_to_select[16]].is_truned_up = true;
	}
	if (time_cards[time_to_select[19]].is_picked && !time_cards[time_to_select[17]].is_picked) {
		time_cards[time_to_select[17]].can_pick = true;
		time_cards[time_to_select[17]].is_truned_up = true;
	}
}
bool Game::destory_mode(player& a_player)
{
	vector<Time_Card>::iterator iter;
	if (&a_player == &red_player)
	{
		for (iter = blue_player.time_cards.begin(); iter != blue_player.time_cards.end(); iter++)
		{
			if (iter->card_id == selected_card->card_id)
			{
				//销毁牌
				blue_player.score -= iter->score;
				blue_player.time_cards.erase(iter);
				destroy_card_mode = false;
				blue_player.player_resource_update();
				red_player.player_resource_update();
				return true;
			}
		}

	}
	else
	{
		for (iter = red_player.time_cards.begin(); iter != red_player.time_cards.end(); iter++)
		{
			if (iter->card_id == selected_card->card_id)
			{
				//销毁牌
				red_player.score -= iter->score;
				red_player.time_cards.erase(iter);
				destroy_card_mode = false;
				blue_player.player_resource_update();
				red_player.player_resource_update();
				return true;
			}
		}
	}
	return false;
}
bool Game::is_win()//false没有胜利 true出现胜利
{
	//战争胜利
	if (abs(fight_state) >= 4)
	{
		if (fight_state >= 4)
		{
			action_bar.setString(L"蓝方战争胜利");
			return true;
		}
		else
		{
			action_bar.setString(L"红方战争胜利");
			return true;
		}
	}

	//科技胜利
	if (red_player.player_technology_signs.size() >= 3)
	{
		action_bar.setString(L"红方科技胜利");
		return true;
	}
	if (blue_player.player_technology_signs.size() >= 3)
	{
		action_bar.setString(L"蓝方科技胜利");
		return true;
	}

	//分数胜利
	if (time_cards[time_to_select[0]].is_picked == true &&
		time_cards[time_to_select[1]].is_picked == true &&
		time_cards[time_to_select[2]].is_picked == true &&
		time_cards[time_to_select[3]].is_picked == true &&
		time_cards[time_to_select[4]].is_picked == true &&
		time_cards[time_to_select[5]].is_picked == true
		)//最后一张牌被选择
	{
		int red_score = red_player.score;
		int blue_score = blue_player.score;

		//红方
		red_score += red_player.time_cards.size() * TIME_CARD_SCORE;
		for (int i = 0; i < red_player.wonder_cards.size(); i++)
		{
			if (red_player.wonder_cards[i].is_build)
			{
				red_score += WONDER_CARD_SCORE;
			}
		}
		//蓝方
		blue_score += blue_player.time_cards.size() * TIME_CARD_SCORE;
		for (int i = 0; i < blue_player.wonder_cards.size(); i++)
		{
			if (blue_player.wonder_cards[i].is_build)
			{
				blue_score += WONDER_CARD_SCORE;
			}
		}

		if (red_score > blue_score)
		{
			action_bar.setString(L"红方分数胜利");
			return true;
		}
		else if (red_score < blue_score)
		{
			action_bar.setString(L"蓝方分数胜利");
			return true;
		}
		else
		{
			action_bar.setString(L"平局");
			return true;
		}
	}
	return false;
}

void Game::Run()
{
	do
	{
		Game_Initail();
		while (window.isOpen() && Game_Over == false)
		{
			Input();
			logic();
			Draw();



		}
	} while (!Game_Quit);
}

void Game::Draw()
{
	window.clear(Color(255, 255, 255, 0));
	sprite_to_draw.clear();
	sprite_to_draw.insert(sprite_to_draw.begin(), &Background_Sprite);
	sprite_to_draw.push_back(&Battle_Sprite);
	sprite_to_draw.push_back(&Scoin_box_blue);
	sprite_to_draw.push_back(&Scoin_box_red);
	sprite_to_draw.push_back(&Scoin_blue);
	sprite_to_draw.push_back(&Scoin_red);

	//奇迹选择阶段，绘制场地奇迹牌
	Draw_select_wonders();
	//时代阶段，绘制场地时代牌
	if (time_now == 1) {
		Draw_times();
		//绘制玩家资源图标
		Draw_player_res();
	}

	//玩家手中的奇迹牌
	Draw_player_wonder_cards();

	//玩家手中的时代牌
	Draw_player_time_cards();

	//玩家手中的科技符号
	Draw_player_tec_sign();

	//遍历绘制精灵
	for (int i = 0; i < sprite_to_draw.size(); i++) {
		window.draw(*sprite_to_draw[i]);
	}

	Draw_of_MouseMoving();

	if (choiser == blue) {
		Sarrow.setPosition(PLAYER_BLUE_LINE, CHARACTER_SIZE + 5);
		window.draw(Sarrow);
	}
	if (choiser == red) {
		Sarrow.rotate(180);
		Sarrow.setPosition(WINDOW_WIDTH - PLAYER_BLUE_LINE, (CHARACTER_SIZE + 75));
		window.draw(Sarrow);
		Sarrow.rotate(180);
	}

	if (selecting_wonders == -1)
	{
		window.draw(resouce_text_blue);
		window.draw(resouce_text_red);
	}

	window.draw(War_Sprite);
	window.draw(action_bar);
	window.draw(arrow_text);
	window.draw(money_num_blue);
	window.draw(money_num_red);
	window.display();
}
void Game::Draw_of_MouseMoving()
{
	Vector2i mouse_position = Mouse::getPosition(window);//获取鼠标相对于窗口的位置坐标

	if (choosing)
	{
		//鼠标在蓝色玩家区域
		if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= PLAYER_BLUE_LINE && mouse_position.x >= 0))
		{
			action_bar.setString(L"选择蓝色玩家开始选牌。");
			RectangleShape rect(Vector2f(PLAYER_BLUE_LINE, Window_Height));//设置大小
			rect.setPosition(Vector2f(0, 0));//设置位置
			rect.setFillColor(Color(0, 0, 255, 158));//设置颜色
			window.draw(rect);//绘制rect
		}
		else
		{ //鼠标在红色玩家区域
			if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= Window_Width && mouse_position.x >= Window_Width - PLAYER_RED_LINE))
			{
				action_bar.setString(L"选择红色玩家开始选牌。");
				RectangleShape rect(Vector2f(PLAYER_RED_LINE, Window_Height));//设置大小
				rect.setPosition(Vector2f(Window_Width - PLAYER_RED_LINE, 0));//设置位置
				rect.setFillColor(Color(255, 0, 0, 158));//设置颜色
				window.draw(rect);//绘制rect
			}
			else {
				if (choiser == 2) {
					action_bar.setString(L"等待红方选择开始玩家……");
				}
				else if (choiser == 1) {
					action_bar.setString(L"等待蓝方选择开始玩家……");
				}
			}
		}
	}

	if (!choosing && (selecting_wonders == 2 || selecting_wonders == 1))
	{
		for (int i = 0; i < 8; i++)
		{
			if (wonder_cards[wonders_to_select[i]].player_selected == 0)
			{
				if (wonder_cards[wonders_to_select[i]].clickedCheck(mouse_position.x, mouse_position.y))
				{
					RectangleShape rect(Vector2f(CARD_WONDER_WIDTH, CARD_WONDER_HEIGHT));
					rect.setPosition(Vector2f(wonder_cards[wonders_to_select[i]].posX, wonder_cards[wonders_to_select[i]].posY));
					rect.setFillColor(Color(255, 255, 255, 175));
					window.draw(rect);
				}
			}
		}
	}

	if (time_now == 1 && !choosing)
	{
		for (int i = 0; i < 20; i++) {
			if (time_cards[time_to_select[i]].can_pick && time_cards[time_to_select[i]].clickedCheck(mouse_position.x, mouse_position.y) && is_selected_card == false)
			{
				if (Is_Game_Begin) {
					RectangleShape rect(Vector2f(CARD_WIDTH, CARD_HEIGHT));//设置大小
					rect.setPosition(Vector2f(time_cards[time_to_select[i]].posX, time_cards[time_to_select[i]].posY));//设置位置
					rect.setFillColor(Color(255, 255, 255, 175));//设置颜色
					window.draw(rect);//绘制rect
				}
			}
		}

		if (is_selected_card)
		{
			if (choiser == red)
			{
				for (int i = 0; i < red_player.wonder_cards.size(); i++)
				{
					if (red_player.wonder_cards[i].clickedCheck(mouse_position.x, mouse_position.y) && red_player.wonder_cards[i].is_build == false)
					{
						RectangleShape rect(Vector2f(CARD_WONDER_WIDTH * WONDER_SCALE, CARD_WONDER_HEIGHT * WONDER_SCALE));
						rect.setPosition(Vector2f(red_player.wonder_cards[i].posX, red_player.wonder_cards[i].posY));
						rect.setFillColor(Color(255, 255, 255, 175));
						window.draw(rect);
					}
				}
				if (mouse_position.x >= RED_PUSH_IN_X_LEFT && mouse_position.x <= RED_PUSH_IN_X_RIGHT &&
					mouse_position.y >= RED_PUSH_IN_Y_DOWN && mouse_position.y <= RED_PUSH_IN_Y_UP)
				{
					RectangleShape rect(Vector2f(RED_PUSH_IN_X_RIGHT - RED_PUSH_IN_X_LEFT, RED_PUSH_IN_Y_DOWN - RED_PUSH_IN_Y_UP));
					rect.setPosition(Vector2f(RED_PUSH_IN_X_LEFT, RED_PUSH_IN_Y_UP));
					rect.setFillColor(Color(255, 255, 255, 175));
					window.draw(rect);
				}
				if (mouse_position.x >= RED_SELL_X_LEFT && mouse_position.x <= RED_SELL_X_RIGHT &&
					mouse_position.y >= RED_SELL_Y_DOWN && mouse_position.y <= RED_SELL_Y_UP)
				{
					RectangleShape rect(Vector2f(RED_SELL_X_RIGHT - RED_SELL_X_LEFT, RED_SELL_Y_DOWN - RED_SELL_Y_UP));
					rect.setPosition(Vector2f(RED_SELL_X_LEFT, RED_SELL_Y_UP));
					rect.setFillColor(Color(255, 255, 255, 175));
					window.draw(rect);
				}
			}
			else if (choiser == blue)
			{
				for (int i = 0; i < blue_player.wonder_cards.size(); i++)
				{
					if (blue_player.wonder_cards[i].clickedCheck(mouse_position.x, mouse_position.y) && blue_player.wonder_cards[i].is_build == false)
					{
						RectangleShape rect(Vector2f(CARD_WONDER_WIDTH * WONDER_SCALE, CARD_WONDER_HEIGHT * WONDER_SCALE));
						rect.setPosition(Vector2f(blue_player.wonder_cards[i].posX, blue_player.wonder_cards[i].posY));
						rect.setFillColor(Color(255, 255, 255, 175));
						window.draw(rect);
					}
				}
				if (mouse_position.x >= BLUE_PUSH_IN_X_LEFT && mouse_position.x <= BLUE_PUSH_IN_X_RIGHT &&
					mouse_position.y >= BLUE_PUSH_IN_Y_DOWN && mouse_position.y <= BLUE_PUSH_IN_Y_UP)
				{
					RectangleShape rect(Vector2f(BLUE_PUSH_IN_X_RIGHT - BLUE_PUSH_IN_X_LEFT, BLUE_PUSH_IN_Y_DOWN - BLUE_PUSH_IN_Y_UP));
					rect.setPosition(Vector2f(BLUE_PUSH_IN_X_LEFT, BLUE_PUSH_IN_Y_UP));
					rect.setFillColor(Color(255, 255, 255, 175));
					window.draw(rect);
				}
				if (mouse_position.x >= BLUE_SELL_X_LEFT && mouse_position.x <= BLUE_SELL_X_RIGHT &&
					mouse_position.y >= BLUE_SELL_Y_DOWN && mouse_position.y <= BLUE_SELL_Y_UP)
				{
					RectangleShape rect(Vector2f(BLUE_SELL_X_RIGHT - BLUE_SELL_X_LEFT, BLUE_SELL_Y_DOWN - BLUE_SELL_Y_UP));
					rect.setPosition(Vector2f(BLUE_SELL_X_LEFT, BLUE_SELL_Y_UP));
					rect.setFillColor(Color(255, 255, 255, 175));
					window.draw(rect);
				}
			}
		}

		if (destroy_card_mode)
		{
			if (choiser == blue)
			{
				for (int i = 0; i < red_player.time_cards.size(); i++)
				{
					if (red_player.time_cards[i].clickedCheck(mouse_position.x, mouse_position.y))
					{
						RectangleShape rect(Vector2f(CARD_WIDTH, CARD_HEIGHT));
						rect.setPosition(Vector2f(red_player.time_cards[i].posX, red_player.time_cards[i].posY));
						rect.setFillColor(Color(255, 255, 255, 175));
						window.draw(rect);
					}
				}
			}
			else if (choiser == red)
			{
				for (int i = 0; i < blue_player.time_cards.size(); i++)
				{
					if (blue_player.time_cards[i].clickedCheck(mouse_position.x, mouse_position.y))
					{
						RectangleShape rect(Vector2f(CARD_WIDTH, CARD_HEIGHT));
						rect.setPosition(Vector2f(blue_player.time_cards[i].posX, blue_player.time_cards[i].posY));
						rect.setFillColor(Color(255, 255, 255, 175));
						window.draw(rect);
					}
				}
			}
		}
	}
}
void Game::Draw_select_wonders()//奇迹选择阶段，绘制场地奇迹牌
{
	switch (selecting_wonders)
	{
	case 1:
	{
		for (int i = 0; i < 4; i++) {
			if (wonder_cards[wonders_to_select[i]].player_selected == 0) {
				sprite_to_draw.push_back(&wonder_cards[wonders_to_select[i]].Swonder);
				wonder_cards[wonders_to_select[i]].posX = PLAYER_BLUE_LINE + (CARD_WONDER_WIDTH + 70) * (i % 2) + 140;
				wonder_cards[wonders_to_select[i]].posY = 200 + (CARD_WONDER_HEIGHT + 70) * (i / 2);
				wonder_cards[wonders_to_select[i]].Swonder.setPosition(wonder_cards[wonders_to_select[i]].posX, wonder_cards[wonders_to_select[i]].posY);
			}
		}
		break;
	}
	case 2:
	{
		for (int i = 4; i < 8; i++) {
			int j = i - 4;
			if (wonder_cards[wonders_to_select[i]].player_selected == 0) {
				sprite_to_draw.push_back(&wonder_cards[wonders_to_select[i]].Swonder);
				wonder_cards[wonders_to_select[i]].posX = PLAYER_BLUE_LINE + (CARD_WONDER_WIDTH + 70) * (i % 2) + 140;
				wonder_cards[wonders_to_select[i]].posY = 200 + (CARD_WONDER_HEIGHT + 70) * (j / 2);
				wonder_cards[wonders_to_select[i]].Swonder.setPosition(wonder_cards[wonders_to_select[i]].posX, wonder_cards[wonders_to_select[i]].posY);
			}
		}
		break;
	}
	default:
		break;
	}
}
void Game::Draw_times()//时代阶段，绘制场地时代牌
{
	for (int i = 0; i < 20; i++) {
		if (time_cards[time_to_select[i]].player_selected == 0) {
			sprite_to_draw.push_back(&time_cards[time_to_select[i]].Stime_card);
			if (!time_cards[time_to_select[i]].is_truned_up) {
				sprite_to_draw.push_back(&time_cards[time_to_select[i]].Stime_back);
			}
		}
	}
}
void Game::Draw_player_res()//绘制玩家资源图标
{
	stringstream ss_red, ss_blue;

	for (int i = 0; i < 5; i++)
	{
		int posX_left = 10 + (TECHNOLOGY_SIZE + 35) * i;
		int posX_right = 1160 + (TECHNOLOGY_SIZE + 35) * i;
		int posY = 850;
		switch (i)
		{
		case Clay:
			Clay_Sprite_blue.setPosition(posX_left, posY);
			sprite_to_draw.push_back(&Clay_Sprite_blue);
			ss_blue << blue_player.Player_Resource.Clay << "     ";

			Clay_Sprite_red.setPosition(posX_right, posY);
			sprite_to_draw.push_back(&Clay_Sprite_red);
			ss_red << red_player.Player_Resource.Clay << "     ";
			break;
		case Wood:
			Wood_Sprite_blue.setPosition(posX_left, posY);
			sprite_to_draw.push_back(&Wood_Sprite_blue);
			ss_blue << blue_player.Player_Resource.Wood << "     ";

			Wood_Sprite_red.setPosition(posX_right, posY);
			sprite_to_draw.push_back(&Wood_Sprite_red);
			ss_red << red_player.Player_Resource.Wood << "     ";
			break;
		case Stone:
			Stone_Sprite_blue.setPosition(posX_left, posY);
			sprite_to_draw.push_back(&Stone_Sprite_blue);
			ss_blue << blue_player.Player_Resource.Stone << "     ";

			Stone_Sprite_red.setPosition(posX_right, posY);
			sprite_to_draw.push_back(&Stone_Sprite_red);
			ss_red << red_player.Player_Resource.Stone << "     ";
			break;
		case Glass:
			Glass_Sprite_blue.setPosition(posX_left, posY);
			sprite_to_draw.push_back(&Glass_Sprite_blue);
			ss_blue << blue_player.Player_Resource.Glass << "     ";

			Glass_Sprite_red.setPosition(posX_right, posY);
			sprite_to_draw.push_back(&Glass_Sprite_red);
			ss_red << red_player.Player_Resource.Glass << "     ";
			break;
		case Paper:
			Paper_Sprite_blue.setPosition(posX_left, posY);
			sprite_to_draw.push_back(&Paper_Sprite_blue);
			ss_blue << blue_player.Player_Resource.Paper << "     ";

			Paper_Sprite_red.setPosition(posX_right, posY);
			sprite_to_draw.push_back(&Paper_Sprite_red);
			ss_red << red_player.Player_Resource.Paper << "     ";
		default:
			break;
		}
	}
	resouce_text_blue.setString(ss_blue.str());
	resouce_text_red.setString(ss_red.str());
}
void Game::Draw_player_wonder_cards()//绘制玩家手中奇迹牌
{
	for (int i = 0; i < red_player.wonder_cards.size(); i++) {
		red_player.wonder_cards[i].posX = 1200 + 40 + (CARD_WONDER_WIDTH * WONDER_SCALE + 55) * (i % 2);
		red_player.wonder_cards[i].posY = 600 + (CARD_WONDER_HEIGHT * WONDER_SCALE + 55) * (i / 2);
		red_player.wonder_cards[i].Swonder.setPosition(red_player.wonder_cards[i].posX, red_player.wonder_cards[i].posY);
		if (!red_player.wonder_cards[i].is_build)
		{
			red_player.wonder_cards[i].Swonder.setColor(Color(175, 175, 175, 255));
		}
		else
		{
			red_player.wonder_cards[i].Swonder.setColor(Color(255, 255, 255, 255));
			red_player.wonder_cards[i].Swonder.setOrigin(red_player.wonder_cards[i].Swonder.getGlobalBounds().width / 2.0, red_player.wonder_cards[i].Swonder.getGlobalBounds().height / 2.0);
			red_player.wonder_cards[i].Swonder.setRotation(90);
		}
		sprite_to_draw.push_back(&red_player.wonder_cards[i].Swonder);
	}

	for (int i = 0; i < blue_player.wonder_cards.size(); i++) {
		blue_player.wonder_cards[i].posX = 40 + (CARD_WONDER_WIDTH * WONDER_SCALE + 55) * (i % 2);
		blue_player.wonder_cards[i].posY = 600 + (CARD_WONDER_HEIGHT * WONDER_SCALE + 55) * (i / 2);
		blue_player.wonder_cards[i].Swonder.setPosition(blue_player.wonder_cards[i].posX, blue_player.wonder_cards[i].posY);
		if (!blue_player.wonder_cards[i].is_build)
		{
			blue_player.wonder_cards[i].Swonder.setColor(Color(175, 175, 175, 255));
		}
		else
		{
			blue_player.wonder_cards[i].Swonder.setColor(Color(255, 255, 255, 255));
			blue_player.wonder_cards[i].Swonder.setOrigin(blue_player.wonder_cards[i].Swonder.getGlobalBounds().width / 2.0, blue_player.wonder_cards[i].Swonder.getGlobalBounds().height / 2.0);
			blue_player.wonder_cards[i].Swonder.setRotation(90);
		}
		sprite_to_draw.push_back(&blue_player.wonder_cards[i].Swonder);
	}
}
void Game::Draw_player_time_cards()//绘制玩家手中时代牌
{
	for (int i = 0; i < red_player.time_cards.size(); i++) {
		red_player.time_cards[i].posX = 1200 + (CARD_WIDTH + 10) * (i % 4);
		red_player.time_cards[i].posY = 150 + (CARD_HEIGHT + 10) * (i / 4);
		red_player.time_cards[i].Stime_card.setPosition(red_player.time_cards[i].posX, red_player.time_cards[i].posY);
		sprite_to_draw.push_back(&red_player.time_cards[i].Stime_card);
	}
	for (int i = 0; i < blue_player.time_cards.size(); i++) {
		blue_player.time_cards[i].posX = 10 + (CARD_WIDTH + 10) * (i % 4);
		blue_player.time_cards[i].posY = 150 + (CARD_HEIGHT + 10) * (i / 4);
		blue_player.time_cards[i].Stime_card.setPosition(blue_player.time_cards[i].posX, blue_player.time_cards[i].posY);
		sprite_to_draw.push_back(&blue_player.time_cards[i].Stime_card);
	}
}
void Game::Draw_player_tec_sign()//玩家手中的科技符号
{
	for (int i = 0; i < red_player.player_technology_signs.size(); i++) {
		int posX = 1500 + (TECHNOLOGY_SIZE + 10) * (i % 2);
		int posY = 10 + (TECHNOLOGY_SIZE + 10) * (i / 2);
		switch (red_player.player_technology_signs[i])
		{
		case Triangle:
			Triangle_Sprite.setPosition(posX, posY);
			sprite_to_draw.push_back(&Triangle_Sprite);
			break;
		case Wheel:
			Wheel_Sprite.setPosition(posX, posY);
			sprite_to_draw.push_back(&Wheel_Sprite);
			break;
		case pen_and_ink:
			pen_and_ink_Sprite.setPosition(posX, posY);
			sprite_to_draw.push_back(&pen_and_ink_Sprite);
			break;
		case pestle_and_mortar:
			pestle_and_mortar_Sprite.setPosition(posX, posY);
			sprite_to_draw.push_back(&pestle_and_mortar_Sprite);
			break;
		default:
			break;
		}

	}
	for (int i = 0; i < blue_player.player_technology_signs.size(); i++) {
		int posX = 10 + (TECHNOLOGY_SIZE + 10) * (i % 2);
		int posY = 10 + (TECHNOLOGY_SIZE + 10) * (i / 2);
		switch (blue_player.player_technology_signs[i])
		{
		case Triangle:
			Triangle_Sprite.setPosition(posX, posY);
			sprite_to_draw.push_back(&Triangle_Sprite);
			break;
		case Wheel:
			Wheel_Sprite.setPosition(posX, posY);
			sprite_to_draw.push_back(&Wheel_Sprite);
			break;
		case pen_and_ink:
			pen_and_ink_Sprite.setPosition(posX, posY);
			sprite_to_draw.push_back(&pen_and_ink_Sprite);
			break;
		case pestle_and_mortar:
			pestle_and_mortar_Sprite.setPosition(posX, posY);
			sprite_to_draw.push_back(&pestle_and_mortar_Sprite);
			break;
		default:
			break;
		}
	}
}




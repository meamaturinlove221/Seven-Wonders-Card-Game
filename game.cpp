#include"game.h"

using namespace sf;
using namespace std;

Game::Game()
{
	Window_Width = WINDOW_WIDTH;
	Window_Height = WINDOW_HEIGHT;
	Uint32 my_style = Style::Close;//���ڷ�񣺽�ֹ�ı䴰�ڴ�С
	window.create(VideoMode(Window_Width, Window_Height), L"�ߴ��漣���Ծ�", my_style);
	window.setFramerateLimit(60);//���ô��ڶ���֡��
	window.setPosition(Vector2i(100, 100));//���ô���λ��
	Load_Data();//�����ز�
}

Game::~Game() {}

void Game::Load_Data()
{
	if ((!font.loadFromFile("data/fonts/SourceHanSansHWSC-Regular.otf")))//��������
	{
		cout << "����û���ҵ�" << endl;
	}

	//���ر�������ͼƬ
	if (!Background_Texture.loadFromFile("data/images/table.png"))
	{
		cout << "û���ҵ�" << endl;
	}
	//ss.str("");//����ַ���

	Background_Sprite.setTexture(Background_Texture);

	if (!Tarrow.loadFromFile("data/images/arrow.png"))
	{
		cout << "��ͷ " << " û���ҵ�" << endl;
	}
	Sarrow.setTexture(Tarrow);

	if (!Battle_Texture.loadFromFile("data/images/battle.jpg"))
	{
		cout << "��ͻָʾ�� " << " û���ҵ�" << endl;
	}
	Battle_Sprite.setTexture(Battle_Texture);
	Battle_Sprite.setOrigin(Battle_Sprite.getLocalBounds().width / 2.0, Battle_Sprite.getLocalBounds().height / 2.0);
	Battle_Sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - Battle_Sprite.getLocalBounds().height / 2.0);

	if (!War_Texture.loadFromFile("data/images/war.png"))
	{
		cout << "ս����� " << " û���ҵ�" << endl;
	}
	War_Sprite.setTexture(War_Texture);
	War_Sprite.setScale(1.0 / 6, 1.0 / 6);
	War_Sprite.setOrigin(War_Sprite.getLocalBounds().width / 2.0, War_Sprite.getLocalBounds().height / 2.0);
	War_Sprite.setPosition(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT - Battle_Sprite.getLocalBounds().height / 2.0);

	if (!Triangle_Texture.loadFromFile("data/images/technology/Triangle.png"))
	{
		cout << "���� " << " û���ҵ�" << endl;
	}
	if (!pen_and_ink_Texture.loadFromFile("data/images/technology/pen_and_ink.png"))
	{
		cout << "��ī " << " û���ҵ�" << endl;
	}
	if (!pestle_and_mortar_Texture.loadFromFile("data/images/technology/pestle_and_mortar.png"))
	{
		cout << "ҩ�� " << " û���ҵ�" << endl;
	}
	if (!Wheel_Texture.loadFromFile("data/images/technology/Wheel.png"))
	{
		cout << "���� " << " û���ҵ�" << endl;
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
		cout << "ճ�� " << " û���ҵ�" << endl;
	}
	if (!Glass_Texture.loadFromFile("data/images/Glass.png"))
	{
		cout << "���� " << " û���ҵ�" << endl;
	}
	if (!Paper_Texture.loadFromFile("data/images/Paper.png"))
	{
		cout << "ֽ " << " û���ҵ�" << endl;
	}
	if (!Wood_Texture.loadFromFile("data/images/Wood.png"))
	{
		cout << "ľͷ " << " û���ҵ�" << endl;
	}
	if (!Stone_Texture.loadFromFile("data/images/Stone.png"))
	{
		cout << "ʯͷ " << " û���ҵ�" << endl;
	}
	//�췽
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
	//����
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
	arrow_text.setString(L"��ǰ�������");

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
		cout << "Ӳ�Һ�����ͼ " << " û���ҵ�" << endl;
	}
	if (!Tcoin.loadFromFile("data/images/coin.png"))
	{
		cout << "Ӳ����ͼ " << " û���ҵ�" << endl;
	}
	Scoin_box_blue.setTexture(Tcoin_box);
	Scoin_box_blue.setPosition(COIN_POSX, COIN_POSY);
	Scoin_box_red.setTexture(Tcoin_box);
	Scoin_box_red.setPosition(1200, COIN_POSY);

	Scoin_blue.setTexture(Tcoin);
	Scoin_blue.setPosition(COIN_POSX + 75 - 15, COIN_POSY + 75 - 15);
	Scoin_red.setTexture(Tcoin);
	Scoin_red.setPosition(1200 + 75 - 15, COIN_POSY + 75 - 15);

	//��ʼ���漣����
	for (int i = 0; i < 8; i++) {
		stringstream ss;
		ss << "data/images/wonders/" << i << ".png";

		//���ر�������ͼƬ
		if (!wonder_cards[i].Twonder.loadFromFile(ss.str()))
		{
			cout << "�漣�� " << i << " û���ҵ�" << endl;
		}
		ss.str("");//����ַ���
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

		//���ر�������ͼƬ
		if (!time_cards[i].Ttime_card.loadFromFile(ss.str()))
		{
			cout << "ʱ���� " << i << " û���ҵ�" << endl;
		}
		if (!time_cards[i].Ttime_back.loadFromFile("data/images/time/back.png"))
		{
			cout << "ʱ�������� " << " û���ҵ�" << endl;
		}
		ss.str("");//����ַ���
		time_cards[i].card_id = i;
		time_cards[i].player_selected = 0;
		time_cards[i].Stime_card.setTexture(time_cards[i].Ttime_card);
		time_cards[i].Stime_back.setTexture(time_cards[i].Ttime_back);
		time_cards[i].Card_Need_Resoure = Time_card_list[i].need_resource;
		time_cards[i].Card_Provide_Resoure = Time_card_list[i].provide_pesoure;
	}
}

void Game::Game_Initail()  //һ����Ϸ�ĳ�ʼ��
{
	Is_Game_Begin = true;
	Game_Quit = false;
	Game_Over = false;
	//�ù���Ĺ���
	fight_state = 0;
	wonder_count = 0;
	stage_cards.clear();
	last_player = none;
	destroy_card_mode = false;

	is_selected_card = false;
	selected_card = nullptr;

	//ϴ�ƣ�����漣����
	suffle suffled_cards;
	for (int i = 0; i < 8; i++) {
		wonders_to_select[i] = i;
	}
	suffled_cards.shuffle_8(wonders_to_select);
	for (int i = 0; i < 8; i++) {
		wonders_to_select[i] = suffled_cards.result_cards8[i];
	}

	//����ѡ���漣�Ľ׶�һ
	selecting_wonders = 1;
	wonders_at_stage = 4;
	// �������ʼѡ������
	srand(time(NULL));
	int r = rand() % 2;
	if (r == 0) {
		choiser = blue;
		action_bar.setString(L"�ȴ�����ѡ��ʼ��ҡ���");
	}
	else {
		choiser = red;
		action_bar.setString(L"�ȴ��췽ѡ��ʼ��ҡ���");
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
		//ѡ��ʼ���
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
				action_bar.setString(L"�����������ѡ���ơ�");
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
				action_bar.setString(L"�췽�������ѡ���ơ�");
				choosing = false;
			}
			LisPressed = false;
		}

		//ѡ���漣�� ǰ4��
		if (!choosing && selecting_wonders == 1)
		{
			if (LisPressed) {
				for (int i = 0; i < 4; i++) {
					if (wonder_cards[wonders_to_select[i]].player_selected == 0) {
						if (wonder_cards[wonders_to_select[i]].clickedCheck(LpressX, LpressY)) {
							//��ҽ���������
							//���ƵĲ���
							wonder_cards[wonders_to_select[i]].player_selected = choiser;
							wonder_cards[wonders_to_select[i]].Swonder.setScale(WONDER_SCALE, WONDER_SCALE);
							wonders_at_stage -= 1;
							//���ƻ������
							switch (choiser)
							{
							case red: {
								red_player.wonder_cards.push_back(wonder_cards[wonders_to_select[i]]);
								action_bar.setString(L"�췽ѡ��ɹ�");
								red_player.can_pick_wonder_count -= 1;
								if (red_player.can_pick_wonder_count <= 0) {
									choiser = blue;
								}
								break;
							}
							case blue: {
								blue_player.wonder_cards.push_back(wonder_cards[wonders_to_select[i]]);
								action_bar.setString(L"����ѡ��ɹ�");
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
								action_bar.setString(L"�췽ѡ��ɹ�");
								red_player.can_pick_wonder_count -= 1;
								if (red_player.can_pick_wonder_count <= 0) {
									choiser = blue;
								}
								break;
							}
							case blue: {
								blue_player.wonder_cards.push_back(wonder_cards[wonders_to_select[i]]);
								action_bar.setString(L"����ѡ��ɹ�");
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
			//��鳡�������
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
						if (destroy_card_mode)//����ģʽ
						{
							if (!destory_mode(red_player))
							{
								is_selected_card = false;
							}
							else
							{
								fight_state = blue_player.Player_Resource.War_sign - red_player.Player_Resource.War_sign;
								//�л����
								choiser = blue;
								is_selected_card = false;
							}
						}
						if (LpressX >= RED_PUSH_IN_X_LEFT && LpressX <= RED_PUSH_IN_X_RIGHT && LpressY >= RED_PUSH_IN_Y_DOWN && LpressY <= RED_PUSH_IN_Y_UP)
						{
							if (select_card(red_player))
							{
								action_bar.setString(L"�췽ѡ��ɹ�");
								//�л����
								choiser = blue;
								is_selected_card = false;
							}


						}
						else if (LpressX >= RED_SELL_X_LEFT && LpressX <= RED_SELL_X_RIGHT && LpressY >= RED_SELL_Y_DOWN && LpressY <= RED_SELL_Y_UP)
						{
							sell_card(red_player);
							action_bar.setString(L"�췽���۳ɹ�");
							//�л����
							choiser = blue;
							is_selected_card = false;
						}
						else
						{
							//�����漣
							build_wonder_card(red_player);
						}
					}
					else
					{
						if (destroy_card_mode)//����ģʽ
						{
							if (!destory_mode(blue_player))
							{
								is_selected_card = false;
							}
							else
							{
								//�л����
								fight_state = blue_player.Player_Resource.War_sign - red_player.Player_Resource.War_sign;
								choiser = red;
								is_selected_card = false;
							}
						}
						if (LpressX >= BLUE_PUSH_IN_X_LEFT && LpressX <= BLUE_PUSH_IN_X_RIGHT && LpressY >= BLUE_PUSH_IN_Y_DOWN && LpressY <= BLUE_PUSH_IN_Y_UP)
						{
							if (select_card(blue_player))
							{
								action_bar.setString(L"����ѡ��ɹ�");
								//�л����
								choiser = red;
								is_selected_card = false;
							}

						}
						else if (LpressX >= BLUE_SELL_X_LEFT && LpressX <= BLUE_SELL_X_RIGHT && LpressY >= BLUE_SELL_Y_DOWN && LpressY <= BLUE_SELL_Y_UP)
						{
							sell_card(blue_player);
							action_bar.setString(L"�������۳ɹ�");
							//�л����
							choiser = red;
							is_selected_card = false;
						}
						else
						{
							//�����漣
							build_wonder_card(blue_player);
						}
					}
				}
			}
			LisPressed = false;
		}
		//�Ҽ�ȡ��ѡ����
		if (RisPressed && is_selected_card) {

			selected_card->Stime_card.setPosition(selected_card->posX, selected_card->posY);
			is_selected_card = false;
			RisPressed = false;
		}
		//����ս�����
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
		ss.str("");//����ַ���
		ss << red_player.money;
		money_num_red.setString(ss.str());
		ss.str("");//����ַ���

		//���ַ���ĸĶ�
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
	//�����ж��ķ����ѡ��ʼ�غϵ����
	if (TIME == 1) {
		//������ѡ��
		srand(time(NULL));
		int r = rand() % 2;
		if (r == 0) {
			choiser = blue;
			action_bar.setString(L"�ȴ�����ѡ��ʼ��ҡ���");
		}
		else {
			choiser = red;
			action_bar.setString(L"�ȴ��췽ѡ��ʼ��ҡ���");
		}
	}
	else if (TIME >= 2) {
		//��һ�оݣ�ս�����
		if (fight_state > 0) {
			choiser = red;
		}
		else if (fight_state < 0) {
			choiser = blue;
		}
		//�ڶ��оݣ�������ƣ������лغϵ���ң�
		if (fight_state == 0) {
			choiser = last_player;
		}
	}
	choosing = 1;
}
void Game::player_choosing_phase_logic() {
	do {
		//����� �޸�choiseֵ


	} while (choiser == blue || choiser == red);
	choosing = 0;
	//��ʼ��һغ�
	if (choiser == blue) {
		//player_blue.player_turn;
	}
	else if (choiser == red) {
		//player_red.player_turn;
	}
}
void Game::time1() {
	selecting_wonders = -1;
	time_now = 1;//����ʱ��һ
	//ϴ�ƣ����ʱ������
	suffle suffled_cards;
	for (int i = 0; i < 20; i++) {
		time_to_select[i] = i;
	}
	suffled_cards.shuffle_20(time_to_select);
	for (int i = 0; i < 20; i++) {
		time_to_select[i] = suffled_cards.result_cards[i];
	}

	//����,����λ��
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

	player_choosing_phase(1);//�غ�ѡ��
}
void Game::sell_card(player& a_player)//����ʱ����
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
bool Game::select_card(player& a_player)//��ҳ��Ի�ȡʱ����
{
	//������Դ������
	if (a_player.buy_card_with_resource(selected_card))
	{
		//���Ʒ����ɫ����ƶ�
		selected_card->player_selected = choiser;
		selected_card->can_pick = false;
		selected_card->is_picked = true;
		a_player.time_cards.push_back(*selected_card);
		//�������ӵ�е���Դ
		a_player.player_resource_update();
		a_player.player_score_update(selected_card);
		return true;
	}
	else
	{
		action_bar.setString(L"��Ǯ����");
		selected_card->Stime_card.setPosition(selected_card->posX, selected_card->posY);
		is_selected_card = false;
		RisPressed = false;
		return false;
	}
}
bool Game::build_wonder_card(player& a_player)//��ҳ��Խ����漣��
{
	int already_build_wonders = 0;//�Ѿ�������漣������
	//�����漣
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
				action_bar.setString(L"�ѽ����漣��������7 �޷�����");
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
						//��������ʱ�������ٴ�ѡ�Ƶ�Ч��
						if (&a_player == &blue_player)
						{
							action_bar.setString(L"���������漣�������ٴ�ѡ��");
						}
						else
						{
							action_bar.setString(L"�췽�����漣�������ٴ�ѡ��");
						}
						is_selected_card = false;
					}
					else if (a_player.wonder_cards[i].destory_card)
					{
						if (&a_player == &blue_player)
						{
							if (red_player.time_cards.size() == 0)
							{
								//��������û��ʱ����
								action_bar.setString(L"���������漣������û��ʱ���ƿ�������");
								destroy_card_mode = false;
								//�л����
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
								action_bar.setString(L"���������漣����������һ�Ŷ���ʱ����");
								destroy_card_mode = true;
							}
						}
						else
						{
							if (blue_player.time_cards.size() == 0)
							{
								//��������û��ʱ����
								action_bar.setString(L"�췽�����漣������û��ʱ���ƿ�������");
								destroy_card_mode = false;
								//�л����
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
								action_bar.setString(L"�췽�����漣����������һ�Ŷ���ʱ����");
								destroy_card_mode = true;
							}
						}
					}
					else
					{
						if (&a_player == &blue_player)
						{
							action_bar.setString(L"���������漣");
						}
						else
						{
							action_bar.setString(L"�췽�����漣");
						}
						//�л����
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
					action_bar.setString(L"�����漣��Դ����");
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
void Game::check_cards_condition()//��鳡�������
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
				//������
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
				//������
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
bool Game::is_win()//falseû��ʤ�� true����ʤ��
{
	//ս��ʤ��
	if (abs(fight_state) >= 4)
	{
		if (fight_state >= 4)
		{
			action_bar.setString(L"����ս��ʤ��");
			return true;
		}
		else
		{
			action_bar.setString(L"�췽ս��ʤ��");
			return true;
		}
	}

	//�Ƽ�ʤ��
	if (red_player.player_technology_signs.size() >= 3)
	{
		action_bar.setString(L"�췽�Ƽ�ʤ��");
		return true;
	}
	if (blue_player.player_technology_signs.size() >= 3)
	{
		action_bar.setString(L"�����Ƽ�ʤ��");
		return true;
	}

	//����ʤ��
	if (time_cards[time_to_select[0]].is_picked == true &&
		time_cards[time_to_select[1]].is_picked == true &&
		time_cards[time_to_select[2]].is_picked == true &&
		time_cards[time_to_select[3]].is_picked == true &&
		time_cards[time_to_select[4]].is_picked == true &&
		time_cards[time_to_select[5]].is_picked == true
		)//���һ���Ʊ�ѡ��
	{
		int red_score = red_player.score;
		int blue_score = blue_player.score;

		//�췽
		red_score += red_player.time_cards.size() * TIME_CARD_SCORE;
		for (int i = 0; i < red_player.wonder_cards.size(); i++)
		{
			if (red_player.wonder_cards[i].is_build)
			{
				red_score += WONDER_CARD_SCORE;
			}
		}
		//����
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
			action_bar.setString(L"�췽����ʤ��");
			return true;
		}
		else if (red_score < blue_score)
		{
			action_bar.setString(L"��������ʤ��");
			return true;
		}
		else
		{
			action_bar.setString(L"ƽ��");
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

	//�漣ѡ��׶Σ����Ƴ����漣��
	Draw_select_wonders();
	//ʱ���׶Σ����Ƴ���ʱ����
	if (time_now == 1) {
		Draw_times();
		//���������Դͼ��
		Draw_player_res();
	}

	//������е��漣��
	Draw_player_wonder_cards();

	//������е�ʱ����
	Draw_player_time_cards();

	//������еĿƼ�����
	Draw_player_tec_sign();

	//�������ƾ���
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
	Vector2i mouse_position = Mouse::getPosition(window);//��ȡ�������ڴ��ڵ�λ������

	if (choosing)
	{
		//�������ɫ�������
		if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= PLAYER_BLUE_LINE && mouse_position.x >= 0))
		{
			action_bar.setString(L"ѡ����ɫ��ҿ�ʼѡ�ơ�");
			RectangleShape rect(Vector2f(PLAYER_BLUE_LINE, Window_Height));//���ô�С
			rect.setPosition(Vector2f(0, 0));//����λ��
			rect.setFillColor(Color(0, 0, 255, 158));//������ɫ
			window.draw(rect);//����rect
		}
		else
		{ //����ں�ɫ�������
			if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= Window_Width && mouse_position.x >= Window_Width - PLAYER_RED_LINE))
			{
				action_bar.setString(L"ѡ���ɫ��ҿ�ʼѡ�ơ�");
				RectangleShape rect(Vector2f(PLAYER_RED_LINE, Window_Height));//���ô�С
				rect.setPosition(Vector2f(Window_Width - PLAYER_RED_LINE, 0));//����λ��
				rect.setFillColor(Color(255, 0, 0, 158));//������ɫ
				window.draw(rect);//����rect
			}
			else {
				if (choiser == 2) {
					action_bar.setString(L"�ȴ��췽ѡ��ʼ��ҡ���");
				}
				else if (choiser == 1) {
					action_bar.setString(L"�ȴ�����ѡ��ʼ��ҡ���");
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
					RectangleShape rect(Vector2f(CARD_WIDTH, CARD_HEIGHT));//���ô�С
					rect.setPosition(Vector2f(time_cards[time_to_select[i]].posX, time_cards[time_to_select[i]].posY));//����λ��
					rect.setFillColor(Color(255, 255, 255, 175));//������ɫ
					window.draw(rect);//����rect
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
void Game::Draw_select_wonders()//�漣ѡ��׶Σ����Ƴ����漣��
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
void Game::Draw_times()//ʱ���׶Σ����Ƴ���ʱ����
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
void Game::Draw_player_res()//���������Դͼ��
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
void Game::Draw_player_wonder_cards()//������������漣��
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
void Game::Draw_player_time_cards()//�����������ʱ����
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
void Game::Draw_player_tec_sign()//������еĿƼ�����
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




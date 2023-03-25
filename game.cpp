#include"game.h"

using namespace sf;
using namespace std;

Game::Game()
{
	Window_Width = WINDOW_WIDTH;
	Window_Height = WINDOW_HEIGHT;
	Uint32 my_style = Style::Close;//���ڷ�񣺽�ֹ�ı䴰�ڴ�С
	window.create(VideoMode(Window_Width, Window_Height), L"�ߴ��漣���Ծ�", my_style);
}

Game::~Game()
{
}

void Game::Game_Initail()
{
	window.setFramerateLimit(60);//���ô��ڶ���֡��
	window.setPosition(Vector2i(100, 100));//���ô���λ��
	Game_Quit = false;
	Game_Over = false;
	Stage_cards_coner = Vector2i(300, 200);
	Background_Image_Name = "bk.png";

	Load_Meida_Data();

	//��̨�����鼰���ʼ��
	for (int i = 0; i < 10; i++)
	{
		the_stage.stage_cards.push_back(Time_Card(Time_card_list[i]));
	}
	for (int i = 0; i < 10; i++)
	{
		the_stage.stage_cards[i].Set_Card_Condition(this);
	}
}

void Game::Input()
{
	Event event;

	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			Game_Quit = true;
		}
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
		{
			if (the_stage.is_selected_card == true)
			{
				//����п�Ƭ��ѡ�У���ô��ʱֻ�б��Ŵ�Ŀ����ܱ���Ӧ
				the_stage.selected_card->checkMouse(event, this);
			}
			else
			{
				for (int i = 0; i < the_stage.stage_cards.size(); i++)
				{
					the_stage.stage_cards[i].checkMouse(event, this);
				}
			}

		}
		if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
		{
			if (the_stage.is_selected_card == true)
			{
				the_stage.selected_card->checkMouse(event, this);
			}
			else
			{
				for (int i = 0; i < the_stage.stage_cards.size(); i++)
				{
					the_stage.stage_cards[i].checkMouse(event, this);
				}
			}
		}
	}
}

void Game::Load_Meida_Data()
{
	if ((!font.loadFromFile("./fonts/SourceHanSansHWSC-Regular.otf")))//��������
	{
		cout << "����û���ҵ�" << endl;
	}

	stringstream ss;
	ss << "./images/" << Background_Image_Name;

	//���ر�������ͼƬ
	if (!Background_Texture.loadFromFile(ss.str()))
	{
		cout << Background_Image_Name << "û���ҵ�" << endl;
	}
	ss.str("");//����ַ���

	Background_Sprite.setTexture(Background_Texture);
}

void Game::Run()
{
	do
	{
		Game_Initail();
		while (window.isOpen() && Game_Over == false)
		{
			Input();
			Draw();
		}
	} while (!Game_Quit);
}

void Game::Draw_of_MouseMoving()
{
	Vector2i mouse_position = Mouse::getPosition(window);//��ȡ�������ڴ��ڵ�λ������

	//�������ɫ�������
	if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= PLAYER_BLUE_LINE && mouse_position.x >= 0))
	{
		RectangleShape rect(Vector2f(PLAYER_BLUE_LINE, Window_Height));//���ô�С
		rect.setPosition(Vector2f(0, 0));//����λ��
		rect.setFillColor(Color(0, 0, 255, 158));//������ɫ
		window.draw(rect);//����rect
	}

	//����ں�ɫ�������
	if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= Window_Width && mouse_position.x >= Window_Width - PLAYER_RED_LINE))
	{
		RectangleShape rect(Vector2f(PLAYER_RED_LINE, Window_Height));//���ô�С
		rect.setPosition(Vector2f(Window_Width - PLAYER_RED_LINE, 0));//����λ��
		rect.setFillColor(Color(255, 0, 0, 158));//������ɫ
		window.draw(rect);//����rect
	}
}

void Game::Draw_stage_cards()
{
	//�Ȼ���û��ѡ�еĿ���
	if (the_stage.is_selected_card == true)
	{
		for (int i = 0; i < the_stage.stage_cards.size(); i++)
		{
			if (the_stage.stage_cards[i].is_show_info == false)
			{
				the_stage.stage_cards[i].Draw(Vector2i(Stage_cards_coner.x + (i % MAX_CARD_IN_LINE) * CARD_BEWTEEN_X, Stage_cards_coner.y + (i / MAX_CARD_IN_LINE) * CARD_BEWTEEN_Y), this);
			}
			else
			{
				the_stage.selected_card = &the_stage.stage_cards[i];
			}
		}
	}
	else
	{
		for (int i = 0; i < the_stage.stage_cards.size(); i++)
		{
			the_stage.stage_cards[i].Draw(Vector2i(Stage_cards_coner.x + (i % MAX_CARD_IN_LINE) * CARD_BEWTEEN_X, Stage_cards_coner.y + (i / MAX_CARD_IN_LINE) * CARD_BEWTEEN_Y), this);
		}
	}

	//�ٻ��Ʊ�ѡ�еĿ���
	if (the_stage.is_selected_card == true)
	{
		the_stage.selected_card->Draw_selected(this);
		the_stage.selected_card->show_info_outside(this);
	}
}

void Game::Draw()
{
	window.clear(Color(255, 255, 255, 0));
	window.draw(Background_Sprite);

	Draw_of_MouseMoving();
	Draw_stage_cards();

	window.display();
}
#include"game.h"

using namespace sf;
using namespace std;

extern Time_card_list_node* Time_card_list;

Game::Game()
{
	Window_Width = 1600;
	Window_Height = 900;
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
	//Load_Meida_Data();
	Game_Quit = false;
	Game_Over = false;
	Time_Card a_card(Time_card_list[0]);
	int wood = a_card.get_Resource(6, 2);
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
			cout << "Mouse Left Pressed" << endl;
		}
		if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
		{
			cout << "Mouse Left Released" << endl;
		}
	}
}

void Game::Load_Meida_Data()
{
	stringstream ss;
	ss << "./img/" << Background_Image_Name;

	//���ر�������ͼƬ
	if (!Background_Texture.loadFromFile(ss.str()))
	{
		cout << Background_Image_Name << "û���ҵ�" << endl;
	}

	ss.str("");//����ַ���
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

void Game::Draw()
{
	window.clear(Color(255, 255, 255, 0));

	Draw_of_MouseMoving();

	window.display();
}
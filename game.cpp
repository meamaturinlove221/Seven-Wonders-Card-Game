#include"game.h"

using namespace sf;
using namespace std;

extern Time_card_list_node* Time_card_list;

Game::Game()
{
	Window_Width = 1600;
	Window_Height = 900;
	Uint32 my_style = Style::Close;//窗口风格：禁止改变窗口大小
	window.create(VideoMode(Window_Width, Window_Height), L"七大奇迹：对决", my_style);
}

Game::~Game()
{
}

void Game::Game_Initail()
{
	window.setFramerateLimit(60);//设置窗口对象帧数
	window.setPosition(Vector2i(100, 100));//设置窗口位置
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

	//加载背景纹理图片
	if (!Background_Texture.loadFromFile(ss.str()))
	{
		cout << Background_Image_Name << "没有找到" << endl;
	}

	ss.str("");//清空字符串
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
	Vector2i mouse_position = Mouse::getPosition(window);//获取鼠标相对于窗口的位置坐标

	//鼠标在蓝色玩家区域
	if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= PLAYER_BLUE_LINE && mouse_position.x >= 0))
	{
		RectangleShape rect(Vector2f(PLAYER_BLUE_LINE, Window_Height));//设置大小
		rect.setPosition(Vector2f(0, 0));//设置位置
		rect.setFillColor(Color(0, 0, 255, 158));//设置颜色
		window.draw(rect);//绘制rect
	}

	//鼠标在红色玩家区域
	if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= Window_Width && mouse_position.x >= Window_Width - PLAYER_RED_LINE))
	{
		RectangleShape rect(Vector2f(PLAYER_RED_LINE, Window_Height));//设置大小
		rect.setPosition(Vector2f(Window_Width - PLAYER_RED_LINE, 0));//设置位置
		rect.setFillColor(Color(255, 0, 0, 158));//设置颜色
		window.draw(rect);//绘制rect
	}
}

void Game::Draw()
{
	window.clear(Color(255, 255, 255, 0));

	Draw_of_MouseMoving();

	window.display();
}
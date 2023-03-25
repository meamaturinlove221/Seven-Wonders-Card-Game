#pragma once

#include"card.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
#include <vector>

#define PLAYER_BLUE_LINE 400//��ɫ�������
#define PLAYER_RED_LINE 400//��ɫ�������

using namespace sf;
using namespace std;

class Game
{
public:
	RenderWindow window;//���ڶ���
	bool Game_Over;//��Ϸ�Ƿ����
	bool Game_Quit;//��Ϸ�Ƿ��˳�
	bool Is_Game_Begin;//��Ϸ�Ƿ�ʼ
	int Is_Game_Over_State;//��Ϸ������״̬
	int Window_Width;//���ڿ��
	int Window_Height;//���ڸ߶�
	int Stage_Width;//��̨���
	int Stage_Height;//��̨�߶�

	string Background_Image_Name;//����ͼƬ��
	Texture Background_Texture;//����ͼƬ�������
	Sprite Background_Sprite;//����ͼƬ�������

	Game();
	~Game();

	//��Ϸ������ʼ��
	void Game_Initail();

	//����ý����Դ
	void Load_Meida_Data();

	//��Ϸ����
	void Run();

	//��Ϸ����
	void Input();

	//�ܻ��ƺ���
	void Draw();

	//������������
	void Draw_of_MouseMoving();
};
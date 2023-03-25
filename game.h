#pragma once

#include"stage.h"

#define WINDOW_WIDTH	1600
#define WINDOW_HEIGHT	900
#define PLAYER_BLUE_LINE 400//��ɫ�������
#define PLAYER_RED_LINE 400//��ɫ�������
#define MAX_CARD_IN_LINE 5//һ�ſ������ż���
#define CARD_BEWTEEN_X 100//���ƺ���������
#define CARD_BEWTEEN_Y 200//��������������
#define CARD_INFO_X 1300//���ƾ�����ϢX
#define CARD_INFO_Y 700//���ƾ�����ϢY

using namespace sf;
using namespace std;

extern Time_card_list_node* Time_card_list;

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
	Vector2i Stage_cards_coner;//��̨���Ʒֲ��󶥵�

	stage the_stage;//��̨ʵ��

	string Background_Image_Name;//����ͼƬ��
	Texture Background_Texture;//����ͼƬ�������
	Sprite Background_Sprite;//����ͼƬ�������
	Font font;//�������

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

	//������������
	void Draw_of_MouseMoving();

	//������������̨�ϵĿ���
	void Draw_stage_cards();	

	//�ܻ��ƺ���
	void Draw();
};
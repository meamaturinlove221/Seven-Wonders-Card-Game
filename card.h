#pragma once

#include"base.h"

class Game;
using namespace sf;
using namespace std;

#define CARD_WIDTH 90//���ƿ��
#define CARD_HEIGHT 160//���Ƹ߶�
#define CHARACTER_SIZE 25//�����С
#define INFO_SCALE 3//���Ʊ������Ŵ�ϵ��

enum Card_Color_list//������ɫ
{
	Brown = 0,
	Grey,
	Green,
	Blue,
	Red,
	Yellow,
	Purple
};

struct Time_card_list_node//�ں�һ��ʱ���ƵĻ�����Ϣ
{
	wstring card_name;//��������
	int color;//��ɫ
	unsigned int need_resource;//������Դ��������״̬ѹ����
	unsigned int provide_pesoure;//�ṩ��Դ��������״̬ѹ����
	int card_score;//�����ṩ����
	int update_avilibale_from;//��������
};

class Time_Card//ʱ����
{
public:
	RectangleShape Base;//���Ƶ������
	Sprite Card_Cost_Sprite;//�������ı�־����
	vector<Sprite>	Card_Sign;//���Ʊ��

	//��Time_card_list_node�ĳ�Ա��Ӧ
	int Card_Bottom_Color;//���Ƶ�����ɫ
	Text Name;//��������
	unsigned int Card_Need_Resoure;//����������Դ��������״̬ѹ����
	unsigned int Card_Provide_Resoure;//�����ṩ��Դ��������״̬ѹ����
	int score;//�����ṩ����
	int update_from;//������������

	Text info;//������ϸ��Ϣ
	bool is_show_info = false;//�Ƿ�Ŵ�����ʾ��ϸ��Ϣ

public:
	Time_Card(Time_card_list_node a_time_card_basic_info);
	~Time_Card();

	//��ɫenumת��ΪRGBֵ
	Vector3i Transfrom_Color_enum(int a_color);

	//�趨���Ƽ������Ԫ�ص�����
	void Set_Card_Condition(Game* a_game);

	//���� �����Ӧ���Ŵ�int��ȡ����Ӧ��ֵ
	int get_Resource(int Resource_num, int from);

	//��ָ��λ�û���
	void Draw(Vector2i position, Game* a_game);

	//�ж�����ǲ����ڰ�ť��
	void checkMouse(Event event, Game* a_game);

	//��ʾ������ϸ��Ϣ
	void show_info_outside(Game* a_game);

	//����ѡ��״̬�Ŀ���
	void Draw_selected(Game* a_game);
};

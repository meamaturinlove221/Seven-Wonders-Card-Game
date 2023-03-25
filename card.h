#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
#include <vector>

using namespace sf;
using namespace std;

#define CARD_WIDTH 10//���ƿ��
#define CARD_HEIGHT 20//���Ƹ߶�

enum technology_sign//�Ƽ�����
{
	Triangle = 0b0,//����
	Wheel,//����
	pen_and_ink,//��ī
	pestle_and_mortar,//ҩ��
	wifi,
	planetarium //������
};

enum Resource//������Դ
{
	 Clay = 0b0,//ճ��
	 Wood ,//ľͷ
	 Stone,//ʯͷ
	 Glass,//����
	 Paper,//ֽ��
	 Money,//���
	 War_sign//ս�����
};

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
	string card_name;//��������
	int color;//��ɫ
	unsigned int need_resource;//������Դ��������״̬ѹ����
	unsigned int provide_pesoure;//�ṩ��Դ��������״̬ѹ����
	int card_score;//�����ṩ����
	int update_avilibale_from;//��������
};


class Time_Card//ʱ����
{
private:
	Sprite Card_Botton_Sprite;//���Ƶ��澫��
	Sprite Card_Cost_Sprite;//�������ı�־����
	vector<Sprite>	Card_Sign;//���Ʊ��

	//��Time_card_list_node�ĳ�Ա��Ӧ
	int Card_Botton_Color;//���Ƶ�����ɫ
	string Name;//��������
	unsigned int Card_Need_Resoure;//����������Դ��������״̬ѹ����
	unsigned int Card_Provide_Resoure;//�����ṩ��Դ��������״̬ѹ����
	int score;//�����ṩ����
	int update_from;//������������

	int Card_Width = CARD_WIDTH;//���ƿ��
	int Card_Height = CARD_HEIGHT;//���Ƹ߶�
	int Card_x;//����λ��x����
	int Card_y;//����λ��y����

public:
	Time_Card(Time_card_list_node a_time_card_basic_info);
	~Time_Card();

	//�趨����λ��
	void Set_Card_Position(int x, int y);

	//�����뾫�����
	void load_source(Texture* texture_put_in);

	//���� �����Ӧ���Ŵ�bitset<25>��ȡ����Ӧ��ֵ
	int get_Resource(int Resource_num, int from);
};

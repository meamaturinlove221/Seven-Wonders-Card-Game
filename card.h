#pragma once

#include"base.h"

class Game;
using namespace sf;
using namespace std;

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

struct Wonder_card_list_node//�ں�һ��ʱ���ƵĻ�����Ϣ
{
	wstring card_name;//��������
	unsigned int need_resource;//������Դ��������״̬ѹ����
	unsigned int provide_pesoure;//�ṩ��Դ��������״̬ѹ����
	int card_score;//�����ṩ����
	bool select_again;//�Ƿ����ṩ�ٴγ鿨
	bool destory_card;//�Ƿ���ʹ�������ʧЧ
};

class Time_Card//ʱ����
{
public:

	//��Time_card_list_node�ĳ�Ա��Ӧ
	int Card_Bottom_Color;//��������
	
	unsigned int Card_Need_Resoure;//����������Դ��������״̬ѹ����
	unsigned int Card_Provide_Resoure;//�����ṩ��Դ��������״̬ѹ����
	int score;//�����ṩ����
	//int update_from;//������������

	Text Name;//��������
	Text info;//������ϸ��Ϣ
	bool is_show_info = false;//�Ƿ�Ŵ�����ʾ��ϸ��Ϣ

	int posX;
	int posY;

	int card_id;
	int player_selected;
	Sprite Stime_back;
	Texture Ttime_back;
	Sprite Stime_card;
	Texture Ttime_card;
	

	bool is_truned_up=true;
	bool is_picked = false;
	bool can_pick=false;


	Time_Card();
	~Time_Card();

	//�����Ӧ���Ŵ�int��ȡ����Ӧ��ֵ
	int get_Resource(int Resource_num, int from);

	bool clickedCheck(int x, int y);
};


class wonder_card {
public:
	int width = CARD_WONDER_WIDTH;
	int height = CARD_WONDER_HEIGHT;
	int card_id;
	int player_selected;//���ѡ��
	int posX;
	int posY;
	bool is_build;//�Ƿ񽨳�
	Texture Twonder;//������ͼ
	Sprite Swonder; //����

	unsigned int Card_Need_Resoure;//����������Դ��������״̬ѹ����
	unsigned int Card_Provide_Resoure;//�����ṩ��Դ��������״̬ѹ����
	int score;//�����ṩ����
	bool select_again;//�Ƿ����ṩ�ٴγ鿨
	bool destory_card;//�Ƿ���ʹ�������ʧЧ

	wonder_card();
	~wonder_card();
	bool clickedCheck(int x, int y);
	//�����Ӧ���Ŵ�int��ȡ����Ӧ��ֵ
	int get_Resource(int Resource_num, int from);
};
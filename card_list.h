#pragma once

#include"card.h"
#include<string>

struct Time_card_list_node//�ں�һ��ʱ���ƵĻ�����Ϣ
{
	string card_name;//��������
	int color;//��ɫ
	Resource need_resource;//������Դ
	Resource provide_pesoure;//�ṩ��Դ
	int provide_points;//�ṩ����

};
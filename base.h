#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <time.h>
#include <stdlib.h>

enum technology_sign//�Ƽ�����
{
	None = 0,//û��
	Triangle,//����
	Wheel,//����
	pen_and_ink,//��ī
	pestle_and_mortar,//ҩ��
	wifi,
	planetarium //������
};

enum Resource//������Դ
{
	Clay = 0b0,//ճ��
	Wood,//ľͷ
	Stone,//ʯͷ
	Glass,//����
	Paper,//ֽ��
	Money,//���
	War_sign//ս�����
};



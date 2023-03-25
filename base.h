#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "xipai.h"

#define WINDOW_WIDTH	1600
#define WINDOW_HEIGHT	900
#define PLAYER_BLUE_LINE 400//��ɫ�������
#define PLAYER_RED_LINE 400//��ɫ�������
#define MAX_CARD_IN_LINE 5//һ�ſ������ż���
#define CARD_BEWTEEN_X 10//���ƺ���������
#define CARD_BEWTEEN_Y 0//��������������
#define CARD_INFO_X 1300//���ƾ�����ϢX
#define CARD_INFO_Y 700//���ƾ�����ϢY

#define CARD_WIDTH 90//���ƿ��4
#define CARD_HEIGHT 135//���Ƹ߶�6
#define CHARACTER_SIZE 25//�����С
#define INFO_SCALE 3//���Ʊ������Ŵ�ϵ��

#define CARD_WONDER_WIDTH  225 //�漣�ƿ�
#define CARD_WONDER_HEIGHT  135 //�漣�Ƹ�
#define CARD_WONDER_BETWEEN_X 70
#define CARD_WONDER_BETWEEN_Y 10
#define WONDER_SCALE 0.6

#define RED_PUSH_IN_X_LEFT 1200//�췽��ҿ��Ʒ�����Ӧ����
#define RED_PUSH_IN_X_RIGHT 1600
#define RED_PUSH_IN_Y_UP 440
#define RED_PUSH_IN_Y_DOWN 150

#define BLUE_PUSH_IN_X_LEFT 0//������ҿ��Ʒ�����Ӧ����
#define BLUE_PUSH_IN_X_RIGHT 400
#define BLUE_PUSH_IN_Y_UP 440
#define BLUE_PUSH_IN_Y_DOWN 150

#define RED_SELL_X_LEFT 1200//�췽��ҿ��Ƴ�����Ӧ����
#define RED_SELL_X_RIGHT 1350
#define RED_SELL_Y_UP 149
#define RED_SELL_Y_DOWN 0

#define BLUE_SELL_X_LEFT 250//������ҿ��Ƴ�����Ӧ����
#define BLUE_SELL_X_RIGHT 400
#define BLUE_SELL_Y_UP 149
#define BLUE_SELL_Y_DOWN 0

#define COIN_POSX 250
#define COIN_POSY 0
#define COIN_SIZE 150
#define START_MONEY 10 //˫������ӵ�еĽ�Ǯ��

#define MONEY_NUM_RED_X	1275
#define MONEY_NUM_RED_Y	70
#define MONEY_NUM_BLUE_X 325	
#define MONEY_NUM_BLUE_Y 70	

#define TECHNOLOGY_SIZE 42//�Ƽ����Ŵ�С

#define EVERY_RESOURCE_COST 2//����һ����Դ��Ҫ�Ľ����

#define TIME_CARD_SCORE 1//���һ��ʱ�����ӷ�
#define WONDER_CARD_SCORE 2//����һ���漣���ӷ�
#define MAX_WONDERS 7 //��������ܽ�����漣��

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



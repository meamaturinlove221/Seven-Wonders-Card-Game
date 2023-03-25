#pragma once

#include "card.h"

class stage {
public:
	enum players {
		none = 0,
		blue,
		red
	};
	int fight_state;//ս�����
	//����-���Ϸ�չ���
	int wonder_count; //����-�ѱ�������漣��Ŀ
	vector<Time_Card> stage_cards; //���ؿ��Ʊ�
	bool is_selected_card = false;//�Ƿ��п��Ʊ�ѡ��
	Time_Card* selected_card = nullptr;//��ѡ�еĿ���,Ĭ��Ϊ��

	players last_player;//�ϻغ����ʼ�غϵ����
	players choise = none;
	int choosing = 0;//�ȴ����ѡ����,0δѡ��

	//�����ж��ķ����ѡ��ʼ�غϵ����
	void player_choosing_phase(int TIME);

	void player_choosing_phase_display();
	
	void player_choosing_phase_logic();

	void time1();
	void time2();
	void time3();
};
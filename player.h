#include "card.h"

class player {
public:
	//����-��������ƿ�
	//����-������пƼ����ż�������
	//����-������з�չ���

	int can_pick_wonder_count; //��ҿ�ȡ���漣��

	vector<wonder_card> wonder_cards;//����漣����
	vector<Time_Card> time_cards;//���ʱ������
	vector<int> player_technology_signs;//������пƼ�����

	//����ͳ��
	struct resource
	{
		int Clay = 0;//ճ��
		int Wood = 0;//ľͷ
		int Stone = 0;//ʯͷ
		int Glass = 0;//����
		int Paper = 0;//ֽ��
		int War_sign = 0;//ս�����
	}Player_Resource = { 0,0,0,0,0 };//������Դ


	int money = 0;
	int score = 0;

	void player_resource_update();//�����������
	void player_score_update(Time_Card* a_time_card);//������ҷ���
	void player_score_update(wonder_card* a_wonder_card);//������ҷ���

	int check_resource(Time_Card* a_time_card);//�������Ƿ���ѡȡʱ���ƣ�������Ҫ�Ľ�Ǯ��
	int check_resource(wonder_card* a_wonder_card);//�������Ƿ��ܽ����漣�ƣ�������Ҫ�Ľ�Ǯ��
	bool buy_card_with_resource(Time_Card* a_time_card);//���Խ����漣��
	bool build_wonder(wonder_card* a_wonder_card);//���Խ����漣��
};

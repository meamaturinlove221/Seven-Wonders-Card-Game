#pragma once
#include"player.h"

using namespace sf;
using namespace std;


extern Time_card_list_node* Time_card_list;
extern Wonder_card_list_node* Wonder_card_list;

class Game
{
public:
	RenderWindow window;//���ڶ���
	int Window_Width;//���ڿ��
	int Window_Height;//���ڸ߶�

	bool Game_Over;//��Ϸ�Ƿ����
	bool Game_Quit;//��Ϸ�Ƿ��˳�
	bool Is_Game_Begin;//��Ϸ�Ƿ�ʼ
	int Is_Game_Over_State;//��Ϸ������״̬

	bool choosing = false;//��Ϸ�׶α��-�ȴ����ѡ��,0δѡ��
	int selecting_wonders; //��Ϸ�׶α��-ѡ���漣�׶� 1Ϊ��һ�֣�2Ϊ�ڶ���
	int time_phase; //��Ϸ�׶α��-��ǰʱ�� 1Ϊʱ��1 2Ϊʱ��2��3Ϊʱ��3
	bool destroy_card_mode;//����ģʽ

	int Stage_Width;//��̨���
	int Stage_Height;//��̨�߶�
	Vector2i Stage_cards_coner;//��̨���Ʒֲ��󶥵�

	Texture Background_Texture;//����ͼƬ�������
	Sprite Background_Sprite;//����ͼƬ�������
	Font font;//�������

	Texture Battle_Texture;//��ͻָʾ���������
	Sprite Battle_Sprite;//��ͻָʾ�ﾫ�����
	Texture War_Texture;//ս������������
	Sprite War_Sprite;//ս����Ǿ������

	Text action_bar; //�����Ϣ������
	Text arrow_text;//��ͷ����
	Texture Tarrow;//��ͷ����
	Sprite Sarrow; //��ͷ����

	//�Ƽ�����
	Texture Triangle_Texture;//����
	Texture	Wheel_Texture;//����
	Texture	pen_and_ink_Texture;//��ī
	Texture pestle_and_mortar_Texture;//ҩ��
	Sprite Triangle_Sprite;
	Sprite Wheel_Sprite;
	Sprite pen_and_ink_Sprite;
	Sprite pestle_and_mortar_Sprite;

	//��Դ����
	Texture Clay_Texture;//ճ��
	Texture Glass_Texture;//����
	Texture	Paper_Texture;//ֽ
	Texture	Stone_Texture;//ʯͷ
	Texture Wood_Texture;//ľͷ
	Sprite Clay_Sprite_red;
	Sprite Glass_Sprite_red;
	Sprite Paper_Sprite_red;
	Sprite Stone_Sprite_red;
	Sprite Wood_Sprite_red;
	Sprite Clay_Sprite_blue;
	Sprite Glass_Sprite_blue;
	Sprite Paper_Sprite_blue;
	Sprite Stone_Sprite_blue;
	Sprite Wood_Sprite_blue;

	Text phase_text; //����-��ǰ�׶�

	Text money_num_red;//��ɫ��Ǯ����
	Text money_num_blue;//��ɫ��Ǯ����

	Text resouce_text_red;//��Դ����
	Text resouce_text_blue;

	vector<Sprite*> sprite_to_draw; //draw�����У���Ҫ���Ƶľ���ָ���б�

	enum players {
		none = 0,
		blue,
		red
	};
	players last_player;//�ϻغ����ʼ�غϵ����
	players choiser = none; //���ڽ���ѡ������

	player red_player, blue_player;

	int time_now;
	int fight_state;//ս�����
	int wonder_count; //����-�ѱ�������漣��Ŀ
	vector<Time_Card> stage_cards; //���ؿ��Ʊ�
	vector<Time_Card> destoryed_cards; //�ƻ����Ʊ�

	int wonders_at_stage;
	int wonders_to_select[8]; //�漣����-id,��������
	wonder_card wonder_cards[8]; //������漣����

	int time_to_select[20]; //ʱ������-id,��������
	Time_Card time_cards[20]; //�����ʱ������

	bool is_selected_card = false;//�Ƿ��п��Ʊ�ѡ��
	Time_Card* selected_card = nullptr;//��ѡ�еĿ���,Ĭ��Ϊ��
	Sprite Scoin_box_blue;
	Sprite Scoin_box_red;
	Texture Tcoin_box;
	Texture Tcoin;
	Sprite Scoin_blue;
	Sprite Scoin_red;


	Game();
	~Game();

	//��Ϸ������ʼ��
	void Game_Initail();

	//���ػ�����Դ
	void Load_Data();

	//��Ϸ����
	void Run();

	//����������
	bool leftClicked, rightClicked;
	bool LisPressed = false;
	bool RisPressed = false;
	int LpressX = -1;
	int LpressY = -1;
	int RpressX = -1;
	int RpressY = -1;
	Vector2i mouse_position;//ʵʱ���λ��
	//��Ϸ����
	void Input();

	//������������
	void Draw_of_MouseMoving();

	//�ܻ��ƺ���
	void Draw();
	void Draw_select_wonders(); //�漣ѡ��׶Σ����Ƴ����漣��
	void Draw_times();	//ʱ���׶Σ����Ƴ���ʱ����
	void Draw_player_res();//���������Դͼ��
	void Draw_player_wonder_cards();//������������漣��
	void Draw_player_time_cards();//�����������ʱ����
	void Draw_player_tec_sign();//������еĿƼ�����


	//��Ϸ���߼�����
	void logic();
	void check_cards_condition();//��鳡�������
	bool select_card(player &a_player);//��ҳ��Ի�ȡʱ����
	void sell_card(player &a_player);//�������ʱ����
	bool build_wonder_card(player& a_player);//��ҳ��Խ����漣��
	bool destory_mode(player& a_player);//����ģʽ
	bool is_win();//ʤ���ж�
	//�����ж��ķ����ѡ��ʼ�غϵ����
	void player_choosing_phase(int TIME);
	void player_choosing_phase_logic();

	void time1();	//ʱ������
};
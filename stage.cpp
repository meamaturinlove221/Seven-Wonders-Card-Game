#include"stage.h"

void stage::player_choosing_phase(int TIME) {
	//�����ж��ķ����ѡ��ʼ�غϵ����
	if (TIME == 1) {
		//������ѡ��
		srand(time(NULL));
		int r = rand() % 2;
		if (r == 0) {
			choise = blue;
		}
		else {
			choise = red;
		}
	}
	else if (TIME >= 2) {
		//��һ�оݣ�ս�����
		if (fight_state > 0) {
			choise = red;
		}
		else if (fight_state < 0) {
			choise = blue;
		}
		//�ڶ��оݣ�������ƣ������лغϵ���ң�
		if (fight_state == 0) {
			choise = last_player;
		}
	}
	choosing = 1;
}
void stage::player_choosing_phase_display()
{
	//if (choosing == 1) {
	//	//չʾ��Ϣ���ɺ�/����ѡ��ʼ��Ϸ��һ��
	//    //չʾ��פ��Ϣ����/����ѡ���С���
	//	//�������ɫ�������
	//	if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= PLAYER_BLUE_LINE && mouse_position.x >= 0))
	//	{
	//		RectangleShape rect(Vector2f(PLAYER_BLUE_LINE, Window_Height));//���ô�С
	//		rect.setPosition(Vector2f(0, 0));//����λ��
	//		rect.setFillColor(Color(0, 0, 255, 158));//������ɫ
	//		window.draw(rect);//����rect
	//	}

	//	//����ں�ɫ�������
	//	if ((mouse_position.y >= 0 && mouse_position.y <= Window_Height) && (mouse_position.x <= Window_Width && mouse_position.x >= Window_Width - PLAYER_RED_LINE))
	//	{
	//		RectangleShape rect(Vector2f(PLAYER_RED_LINE, Window_Height));//���ô�С
	//		rect.setPosition(Vector2f(Window_Width - PLAYER_RED_LINE, 0));//����λ��
	//		rect.setFillColor(Color(255, 0, 0, 158));//������ɫ
	//		window.draw(rect);//����rect
	//	}
	//}

}
void stage::player_choosing_phase_logic() {
	do {
		//����� �޸�choiseֵ


	} while (choise == blue || choise == red);
	choosing = 0;
	//��ʼ��һغ�
	if (choise == blue) {
		//player_blue.player_turn;
	}
	else if (choise == red) {
		//player_red.player_turn;
	}
}
void stage::time1() {
	//����
	player_choosing_phase(1);//�غ�ѡ��
}
void stage::time2() {

	//����
	player_choosing_phase(2);//�غ�ѡ��

}
void stage::time3() {
	//����
	player_choosing_phase(3);//�غ�ѡ��

}
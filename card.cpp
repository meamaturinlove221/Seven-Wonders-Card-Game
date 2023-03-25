#include"card.h"
#include"game.h"

using namespace sf;
using namespace std;

class Game;

Time_Card::Time_Card()
{

}

Time_Card::~Time_Card()
{
}



//�����Ӧ���Ŵ�int��ȡ����Ӧ��ֵ
/*	��һ������Ϊ��Ӧ��Դ����
		�Ƽ�����		8
		ճ��			7
		ľͷ			6
		ʯͷ			5
		����			4
		ֽ��			3
		���			2
		ս�����		1
	�ڶ���Ϊ��ȡ��Դ��1 -> Card_Need_Resoure,2 -> Card_Provide_Resoure
	��ȡʧ���򷵻�-1
*/
int Time_Card::get_Resource(int Resource_num, int from)
{
	unsigned int result = 0;
	if (from == 1)
	{
		if (Resource_num >= 1 && Resource_num <= 8)
		{
			//λ������ȡ����
			result = (Card_Need_Resoure >> ((Resource_num - 1) * 4)) & 0b1111;
			return result;
		}
		else
		{
			cout << "get_Resource error: ��Դ���Ŵ���" << endl;
			return -1;
		}
	}
	else if (from == 2)
	{
		if (Resource_num >= 1 && Resource_num <= 8)
		{
			result = (Card_Provide_Resoure >> ((Resource_num - 1) * 4)) & 0b1111;
			return result;
		}
		else
		{
			cout << "get_Resource error: ��Դ���Ŵ���" << endl;
			return -1;
		}
	}
	else
	{
		cout << "get_Resource error: û���ҵ���Ӧ������Դ" << endl;
		return -1;
	}
}


bool Time_Card::clickedCheck(int x, int y) {
	if (x <= posX + CARD_WIDTH && x >= posX && y <= posY + CARD_HEIGHT && y >= posY) {
		return true;
	}
	else {
		return false;
	}
}



wonder_card::wonder_card() {
	is_build = false;
}

wonder_card::~wonder_card() {

}

bool wonder_card::clickedCheck(int x, int y) {
	if (x <= posX + CARD_WONDER_WIDTH && x >= posX && y <= posY + CARD_WONDER_HEIGHT && y >= posY) {
		return true;
	}
	else {
		return false;
	}
}

int wonder_card::get_Resource(int Resource_num, int from)
{
	unsigned int result = 0;
	if (from == 1)
	{
		if (Resource_num >= 1 && Resource_num <= 8)
		{
			//λ������ȡ����
			result = (Card_Need_Resoure >> ((Resource_num - 1) * 4)) & 0b1111;
			return result;
		}
		else
		{
			cout << "get_Resource error: ��Դ���Ŵ���" << endl;
			return -1;
		}
	}
	else if (from == 2)
	{
		if (Resource_num >= 1 && Resource_num <= 8)
		{
			result = (Card_Provide_Resoure >> ((Resource_num - 1) * 4)) & 0b1111;
			return result;
		}
		else
		{
			cout << "get_Resource error: ��Դ���Ŵ���" << endl;
			return -1;
		}
	}
	else
	{
		cout << "get_Resource error: û���ҵ���Ӧ������Դ" << endl;
		return -1;
	}
}

#include"card.h"

using namespace sf;
using namespace std;

extern Time_card_list_node* Time_card_list;

Time_Card::Time_Card(Time_card_list_node a_time_card_basic_info)
{
	Card_Botton_Color = a_time_card_basic_info.color;
	Name = a_time_card_basic_info.card_name;
	Card_Need_Resoure = a_time_card_basic_info.need_resource;
	Card_Provide_Resoure = a_time_card_basic_info.provide_pesoure;
	score = a_time_card_basic_info.card_score;
	update_from = a_time_card_basic_info.update_avilibale_from;
}

Time_Card::~Time_Card()
{
}

//�趨����λ��
void Time_Card::Set_Card_Position(int x, int y)
{
	Card_x = x;
	Card_y = y;
}

//�����뾫�����
void Time_Card::load_source(Texture* texture_put_in)
{
	Texture* texture_point_locally = texture_put_in;
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
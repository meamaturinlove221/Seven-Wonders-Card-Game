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



//输入对应代号从int中取出对应数值
/*	第一个参数为对应资源代号
		科技符号		8
		粘土			7
		木头			6
		石头			5
		玻璃			4
		纸张			3
		金币			2
		战争标记		1
	第二个为获取来源，1 -> Card_Need_Resoure,2 -> Card_Provide_Resoure
	获取失败则返回-1
*/
int Time_Card::get_Resource(int Resource_num, int from)
{
	unsigned int result = 0;
	if (from == 1)
	{
		if (Resource_num >= 1 && Resource_num <= 8)
		{
			//位运算提取数字
			result = (Card_Need_Resoure >> ((Resource_num - 1) * 4)) & 0b1111;
			return result;
		}
		else
		{
			cout << "get_Resource error: 资源代号错误" << endl;
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
			cout << "get_Resource error: 资源代号错误" << endl;
			return -1;
		}
	}
	else
	{
		cout << "get_Resource error: 没有找到对应二进制源" << endl;
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
			//位运算提取数字
			result = (Card_Need_Resoure >> ((Resource_num - 1) * 4)) & 0b1111;
			return result;
		}
		else
		{
			cout << "get_Resource error: 资源代号错误" << endl;
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
			cout << "get_Resource error: 资源代号错误" << endl;
			return -1;
		}
	}
	else
	{
		cout << "get_Resource error: 没有找到对应二进制源" << endl;
		return -1;
	}
}

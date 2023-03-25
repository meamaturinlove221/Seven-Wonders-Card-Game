#include"card.h"
#include"game.h"

using namespace sf;
using namespace std;

class Game;

Time_Card::Time_Card(Time_card_list_node a_time_card_basic_info)
{
	Card_Bottom_Color = a_time_card_basic_info.color;
	Name.setString(a_time_card_basic_info.card_name);
	Card_Need_Resoure = a_time_card_basic_info.need_resource;
	Card_Provide_Resoure = a_time_card_basic_info.provide_pesoure;
	score = a_time_card_basic_info.card_score;
	update_from = a_time_card_basic_info.update_avilibale_from;

	//���Ƶ���ȷ��
	Base.setSize(Vector2f(CARD_WIDTH, CARD_HEIGHT));//���ô�С

	Vector3i this_color = Transfrom_Color_enum(Card_Bottom_Color);
	Base.setFillColor(Color(this_color.x, this_color.y, this_color.z));//������ɫ
}

Time_Card::~Time_Card()
{
}

//��ɫenumת��ΪRGBֵ
Vector3i Time_Card::Transfrom_Color_enum(int a_color)
{
	switch (a_color)
	{
	case Brown:
		return Vector3i(150, 75, 0);
		break;
	case Grey:
		return Vector3i(220, 220, 220);
		break;
	case Green:
		return Vector3i(0, 139, 69);
		break;
	case Blue:
		return Vector3i(30, 144, 255);
		break;
	case Red:
		return Vector3i(255, 48, 48);
		break;
	case Yellow:
		return Vector3i(225, 215, 0);
		break;
	case Purple:
		return Vector3i(186, 85, 211);
		break;
	default:
		return Vector3i(0, 0, 0);
		cout << "color unfind error" << endl;
		break;
	}
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

void Time_Card::checkMouse(Event event, Game* a_game)
{
	if (!is_show_info)
	{
		if (Base.getPosition().x - Base.getGlobalBounds().width / 2 < event.mouseButton.x && Base.getPosition().x + Base.getGlobalBounds().width / 2 > event.mouseButton.x &&
			Base.getPosition().y - Base.getGlobalBounds().width / 2 < event.mouseButton.y && Base.getPosition().y + Base.getGlobalBounds().height / 2 > event.mouseButton.y)
		{
			if (event.type == Event::EventType::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				Base.setOutlineColor(Color(255, 255, 255, 255));
				Base.setOutlineThickness(2.0);
			}
			else if (event.type == Event::EventType::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				Base.setOutlineThickness(0);
				is_show_info = true;
				a_game->the_stage.is_selected_card = true;
			}
		}
		else
		{
			if (event.type == Event::EventType::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				Base.setOutlineThickness(0);
			}
		}
	}
	else
	{
		if (Base.getPosition().x - Base.getGlobalBounds().width / 2 < event.mouseButton.x && Base.getPosition().x + Base.getGlobalBounds().width / 2 > event.mouseButton.x &&
			Base.getPosition().y - Base.getGlobalBounds().width / 2 < event.mouseButton.y && Base.getPosition().y + Base.getGlobalBounds().height / 2 > event.mouseButton.y)
		{

			if (event.type == Event::EventType::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				Base.setOutlineColor(Color(255, 255, 255, 255));
				Base.setOutlineThickness(2.0);
			}
			else if (event.type == Event::EventType::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				Base.setOutlineThickness(0);
				is_show_info = false;
				a_game->the_stage.is_selected_card = false;
			}
		}
		else
		{
			if (event.type == Event::EventType::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				Base.setOutlineThickness(0);
			}
		}
	}
}

//�趨���Ƽ������Ԫ�ص�����
void Time_Card::Set_Card_Condition(Game* a_game)
{
	//���õ���
	Base.setOrigin(Base.getGlobalBounds().width / 2, Base.getGlobalBounds().height / 2);

	//��������
	Name.setFont(a_game->font);
	Name.setCharacterSize(CHARACTER_SIZE);
	Name.setStyle(Text::Regular);
	Name.setOrigin(0, 0);
	info.setFont(a_game->font);
	info.setCharacterSize(CHARACTER_SIZE);
	info.setStyle(Text::Regular);
	info.setOrigin(0, 0);
}

void Time_Card::show_info_outside(Game* a_game)
{
	//��ʾ������Ϣ
	Name.setFillColor(Color(0, 0, 0));
	Name.setPosition(CARD_INFO_X, CARD_INFO_Y);
	a_game->window.draw(Name);
}

void Time_Card::Draw_selected(Game* a_game)
{
	//���ƷŴ������ʾ
	Base.setScale(INFO_SCALE, INFO_SCALE);
	Base.setPosition(a_game->Window_Width / 2.0, a_game->Window_Height / 2.0);
	a_game->window.draw(Base);
}

void Time_Card::Draw(Vector2i position, Game* a_game)
{
	Base.setScale(1.0, 1.0);
	Base.setPosition(position.x, position.y);
	a_game->window.draw(Base);
}


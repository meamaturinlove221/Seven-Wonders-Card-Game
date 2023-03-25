#include"player.h"

void player::player_resource_update()
{
	Player_Resource = { 0,0,0,0,0 };
	for (int i = 0; i < time_cards.size(); i++)
	{
		Player_Resource.Clay += time_cards[i].get_Resource(7, 2);
		Player_Resource.Glass += time_cards[i].get_Resource(4, 2);
		Player_Resource.Paper += time_cards[i].get_Resource(3, 2);
		Player_Resource.Stone += time_cards[i].get_Resource(5, 2);
		Player_Resource.War_sign += time_cards[i].get_Resource(1, 2);
		Player_Resource.Wood += time_cards[i].get_Resource(6, 2);
	}
	for (int i = 0; i < wonder_cards.size(); i++)
	{
		if (wonder_cards[i].is_build)
		{
			Player_Resource.Clay += wonder_cards[i].get_Resource(7, 2);
			Player_Resource.Glass += wonder_cards[i].get_Resource(4, 2);
			Player_Resource.Paper += wonder_cards[i].get_Resource(3, 2);
			Player_Resource.Stone += wonder_cards[i].get_Resource(5, 2);
			Player_Resource.War_sign += wonder_cards[i].get_Resource(1, 2);
			Player_Resource.Wood += wonder_cards[i].get_Resource(6, 2);
		}
	}
}

void player::player_score_update(Time_Card* a_time_card)
{
	score += a_time_card->score;
}

void player::player_score_update(wonder_card* a_wonder_card)
{
	score += a_wonder_card->score;
}

int player::check_resource(Time_Card* a_time_card)
{
	int need_money = a_time_card->get_Resource(2, 1);
	if (Player_Resource.Clay < a_time_card->get_Resource(7, 1))
	{
		need_money += EVERY_RESOURCE_COST * (a_time_card->get_Resource(7, 1) - Player_Resource.Clay);
		Player_Resource.Clay = 0;
	}
	if (Player_Resource.Wood < a_time_card->get_Resource(6, 1))
	{
		need_money += EVERY_RESOURCE_COST * (a_time_card->get_Resource(6, 1) - Player_Resource.Wood);
		Player_Resource.Wood = 0;
	}
	if (Player_Resource.Stone < a_time_card->get_Resource(5, 1))
	{
		need_money += EVERY_RESOURCE_COST * (a_time_card->get_Resource(5, 1) - Player_Resource.Stone);
		Player_Resource.Stone = 0;
	}
	if (Player_Resource.Glass < a_time_card->get_Resource(4, 1))
	{
		need_money += EVERY_RESOURCE_COST * (a_time_card->get_Resource(4, 1) - Player_Resource.Glass);
		Player_Resource.Glass = 0;
	}
	if (Player_Resource.Paper < a_time_card->get_Resource(3, 1))
	{
		need_money += EVERY_RESOURCE_COST * (a_time_card->get_Resource(3, 1) - Player_Resource.Paper);
		Player_Resource.Paper = 0;
	}
	return need_money;
}

int player::check_resource(wonder_card* a_wonder_card)
{
	int need_money = a_wonder_card->get_Resource(2, 1);
	if (Player_Resource.Clay < a_wonder_card->get_Resource(7, 1))
	{
		need_money += EVERY_RESOURCE_COST * (a_wonder_card->get_Resource(7, 1) - Player_Resource.Clay);
		Player_Resource.Clay = 0;
	}
	if (Player_Resource.Wood < a_wonder_card->get_Resource(6, 1))
	{
		need_money += EVERY_RESOURCE_COST * (a_wonder_card->get_Resource(6, 1) - Player_Resource.Wood);
		Player_Resource.Wood = 0;
	}
	if (Player_Resource.Stone < a_wonder_card->get_Resource(5, 1))
	{
		need_money += EVERY_RESOURCE_COST * (a_wonder_card->get_Resource(5, 1) - Player_Resource.Stone);
		Player_Resource.Stone = 0;
	}
	if (Player_Resource.Glass < a_wonder_card->get_Resource(4, 1))
	{
		need_money += EVERY_RESOURCE_COST * (a_wonder_card->get_Resource(4, 1) - Player_Resource.Glass);
		Player_Resource.Glass = 0;
	}
	if (Player_Resource.Paper < a_wonder_card->get_Resource(3, 1))
	{
		need_money += EVERY_RESOURCE_COST * (a_wonder_card->get_Resource(3, 1) - Player_Resource.Paper);
		Player_Resource.Paper = 0;
	}
	return need_money;
}

bool player::buy_card_with_resource(Time_Card* a_time_card)//直接购买牌
{
	if (money - check_resource(a_time_card) < 0)
	{
		return false;//无法购买该卡牌
	}
	else
	{	
		if (check_resource(a_time_card) > a_time_card->get_Resource(2, 1))
		{
			money -= check_resource(a_time_card);
			money += a_time_card->get_Resource(2, 2);
			if (a_time_card->get_Resource(8, 2) != None)
			{
				//加入科技符号
				player_technology_signs.push_back(a_time_card->get_Resource(8, 2));
			}
			return true;//获得卡牌的时候使用了金钱购买资源
		}
		else
		{
			Player_Resource.Clay -= a_time_card->get_Resource(7, 1);
			Player_Resource.Wood -= a_time_card->get_Resource(6, 1);
			Player_Resource.Stone -= a_time_card->get_Resource(5, 1);
			Player_Resource.Glass -= a_time_card->get_Resource(4, 1);
			Player_Resource.Paper -= a_time_card->get_Resource(3, 1);
			money -= a_time_card->get_Resource(2, 1);
			money += a_time_card->get_Resource(2, 2);
			if (a_time_card->get_Resource(8, 2) != None)
			{
				//加入科技符号
				player_technology_signs.push_back(a_time_card->get_Resource(8, 2));
			}
			return true;//获得卡牌的时候没有使用金钱购买资源
		}
	}
}

bool player::build_wonder(wonder_card* a_wonder_card)
{
	if (check_resource(a_wonder_card) > a_wonder_card->get_Resource(2, 1))
	{
		if ((money - check_resource(a_wonder_card)) < 0)
		{
			return false;//无法购买该卡牌
		}
		else
		{
			money -= check_resource(a_wonder_card);
			money += a_wonder_card->get_Resource(2, 2);
			return true;//获得卡牌的时候使用了金钱购买资源
		}
	}
	else
	{
		Player_Resource.Clay -= a_wonder_card->get_Resource(7, 1);
		Player_Resource.Wood -= a_wonder_card->get_Resource(6, 1);
		Player_Resource.Stone -= a_wonder_card->get_Resource(5, 1);
		Player_Resource.Glass -= a_wonder_card->get_Resource(4, 1);
		Player_Resource.Paper -= a_wonder_card->get_Resource(3, 1);
		money -= a_wonder_card->get_Resource(2, 1);
		money += a_wonder_card->get_Resource(2, 2);
		return true;//获得卡牌的时候没有使用金钱购买资源
	}
}
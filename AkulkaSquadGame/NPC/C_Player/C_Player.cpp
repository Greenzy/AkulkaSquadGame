#include "C_Player.h"

C_Player::C_Player(int ID): C_NPC(ID)
{
}

C_Player::~C_Player()
{
}

int C_Player::GetDamage()
{
	return m_Damage;
}

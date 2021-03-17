#include "C_NPC.h"

C_NPC::C_NPC(int ID)
{
	m_ID = ID;
}

C_NPC::~C_NPC()
{
}

int C_NPC::GetDamage()
{
	return m_Damage;
}

int C_NPC::GetID()
{
	return m_ID;
}


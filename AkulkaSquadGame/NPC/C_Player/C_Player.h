#pragma once
#include "../C_NPC/C_NPC.h"

class C_Player : public C_NPC
{
public:
	C_Player(int ID);
	~C_Player();
	virtual int GetDamage();

private:
	int m_Damage = 1;
protected:
	
};

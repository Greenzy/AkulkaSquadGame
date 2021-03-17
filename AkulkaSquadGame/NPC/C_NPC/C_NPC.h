#pragma once

class C_NPC
{
public:
	C_NPC(int ID);
	~C_NPC();
	virtual int GetDamage();
	virtual int GetID();
private:
	int	m_ID;
	int m_Damage = 0;

protected:
	
};
#include "c_input_system.h"

c_input_system::c_input_system(HWND hwnd)
{
	m_hwnd = hwnd;
}

c_input_system::~c_input_system()
{
}

POINT c_input_system::Get_mouse_position()
{
	GetCursorPos(&m_point);
	return m_point;
}

POINT c_input_system::Get_hwnd_mouse_position()
{
	ScreenToClient(m_hwnd, &m_point);
	return m_point;
}

void c_input_system::mouse_visibility(bool true_false)
{
	ShowCursor(true_false); 
}


bool c_input_system::is_key_pressed(int key_code)
{
	if (GetKeyState(key_code) & 0x8000)
	{
		return true;
	}

	return false;
}

bool c_input_system::is_key_toggled(int key_code)
{
	/*caps lock, num lock ....*/
	return  (GetKeyState(key_code) & 1);
}



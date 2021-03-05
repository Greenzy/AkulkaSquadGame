#pragma once
#include <Windows.h>


class c_input_system
{
public:
	c_input_system(HWND hwnd);
	~c_input_system();
	POINT Get_mouse_position();//Get mouse position
	POINT Get_hwnd_mouse_position();//Get mouse position in hwnd
	void mouse_visibility(bool true_false);
	bool is_key_pressed(int key_code);
	bool is_key_toggled(int key_code);

private:
	POINT m_point;
	HWND m_hwnd;
};

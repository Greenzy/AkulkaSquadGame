#include "c_control_setting.h"

c_control_setting::c_control_setting(HWND hwnd)
{
	m_input = std::make_unique<c_input_system>(hwnd);
}

c_control_setting::~c_control_setting()
{
}

void c_control_setting::move_up(int speed)
{
}

void c_control_setting::move_down(int speed)
{
}

void c_control_setting::move_left(int speed)
{
}

void c_control_setting::move_right(int speed)
{
}



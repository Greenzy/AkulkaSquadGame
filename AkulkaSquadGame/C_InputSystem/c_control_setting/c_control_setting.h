#pragma once
#include "../c_input_system.h"
#include <iostream>

class c_control_setting
{
public:
	c_control_setting(HWND hwnd);
	~c_control_setting();

	void move_up(int speed);
	void move_down(int speed);
	void move_left(int speed);
	void move_right(int speed);
private:

	std::unique_ptr<c_input_system> m_input;
};

#pragma once
#include <windows.h>

class C_AppWindow {
public:
	C_AppWindow();
	~C_AppWindow();
private:
	HWND m_hWnd;
};
#pragma once
#include <windows.h>
#include "../C_Render/C_Render.h"

class C_AppWindow {
public:
	C_AppWindow();
	~C_AppWindow();
	bool IsRun();
	bool Broadcast();
private:

	std::unique_ptr<c_d3d_render> m_d3d_render;
	HWND m_HWND;
	bool m_IsRun;
};
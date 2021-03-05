#include "C_AppWindow.h"
#include <stdio.h>
#include <d3d9.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

C_AppWindow::C_AppWindow()
{

	// Register the window class.
	WNDCLASS wc = { };


	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"Game2D";

	RegisterClass(&wc);

	// Create the window.

	m_HWND = CreateWindowEx(NULL,
		L"Game2D",					// name of the window class
		L"Game2D",					// title of the window
		WS_EX_TOPMOST | WS_POPUP,   // window style                WS_EX_TOPMOST | WS_POPUP,    // fullscreen values
		100,						// x-position of the window    0, 0,    // the starting x and y positions should be 0
		100,						// y-position of the window
		1000,						// width of the window
		1000,						// height of the window
		NULL,						// we have no parent window, NULL
		NULL,						// we aren't using menus, NULL
		NULL,						// application handle
		NULL);						// used with multiple windows, NULL

	if (!m_HWND)
		printf("hwnd create error");

	ShowWindow(m_HWND, SW_SHOW);

	//m_d3d_render = std::make_unique<c_d3d_render>(m_hwnd);

	m_IsRun = true;
}

C_AppWindow::~C_AppWindow()
{
	m_IsRun = false;
}

bool C_AppWindow::IsRun()
{
	return m_IsRun;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	// sort through and find what code to run for the message given
	switch (message)
	{
		// this message is read when the window is closed
	case WM_CREATE:
	{
		C_AppWindow* Window = (C_AppWindow*)((LPCREATESTRUCT)lparam)->lpCreateParams;  //THIS WILL GET THE "THIS" POINTER PASSED IN CREATEWINDOWEX
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)Window);
		break;
	}
	case WM_DESTROY:
	{
		// close the application entirely
		C_AppWindow* Window = (C_AppWindow*)GetWindowLong(hwnd, GWLP_USERDATA);
		Window->~C_AppWindow();
		PostQuitMessage(0);
		break;
	}
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hwnd, message, wparam, lparam);
}
#include "C_AppWindow.h"
#include <d3d9.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

C_AppWindow::C_AppWindow() {

        // Register the window class.
        WNDCLASS wc = { };

        wc.lpfnWndProc = WindowProc;
        wc.hInstance = 0;
        wc.lpszClassName = L"chto-to";

        RegisterClass(&wc);

        // Create the window.

        HWND hwnd = CreateWindowEx(
            0,                              // Optional window styles.
            L"chto-to",                     // Window class
            L"something",    // Window text
            WS_OVERLAPPEDWINDOW,            // Window style

            0, 0, 1000, 1000,

            NULL,       // Parent window    
            NULL,       // Menu
            0,  // Instance handle
            NULL        // Additional application data
        );

        ShowWindow(hwnd, SW_SHOW);
    }
C_AppWindow::~C_AppWindow() {

}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    return DefWindowProc(hwnd, message, wparam, lparam);
}
#pragma once

#include "C_VertexBuffer/C_VertexBuffer.h"
#include "../C_InputSystem/c_input_system.h"
#include "C_GameSprite/C_GameSprite.h"

#include <d3d9.h>
#include <D3dx9tex.h>
#include <iostream>


class c_api_binding;
class c_d3d_render
{
public:
	c_d3d_render(HWND hwnd);
	c_d3d_render();
	~c_d3d_render();
	void RenderFrame();    // renders a single frame
	void CleandD3D();    // closes Direct3D and releases memory
	LPDIRECT3DDEVICE9 GetDevice();
	C_VertexBuffer* CreateVertexBuffer();
	static c_d3d_render* Get();

private:
	LPDIRECT3D9 m_d3d;    // the pointer to our Direct3D interface
	LPDIRECT3DDEVICE9 m_d3d_device;    // the pointer to the device class
	IDirect3DTexture9* m_pTexture; // texture file
	LPDIRECT3DCUBETEXTURE9 m_pCubeMap;
	C_VertexBuffer* m_vb;
	void m_some_render_foo(LPDIRECT3DDEVICE9 m_d3d_device); // test function for rendering
	std::unique_ptr<C_GameSprite> m_Sprite; // new m_Sprite file
	std::unique_ptr<c_input_system> m_input;

	friend class c_api_binding;
};


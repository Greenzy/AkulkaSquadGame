#include "C_Render.h"

c_d3d_render::c_d3d_render(HWND hwnd) 
{
	m_d3d = Direct3DCreate9(D3D_SDK_VERSION);    // create the Direct3D interface

	D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information

	ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
	d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	d3dpp.hDeviceWindow = hwnd;    // set the window to be used by Direct3D
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;


	// create a device class using this information and information from the d3dpp stuct
	m_d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&m_d3d_device);


	m_vb = CreateVertexBuffer();
	m_vb->CreateSquare(200, 100, 100, 100);


	//create sprite
	m_Sprite = std::make_unique<C_GameSprite>(0, 0);
	m_Sprite.get()->Initialize(m_d3d_device, L"test.png", 600, 115);
	m_input = std::make_unique<c_input_system>(hwnd);
}
c_d3d_render::c_d3d_render()
{
}
c_d3d_render::~c_d3d_render() {}

void c_d3d_render::m_some_render_foo(LPDIRECT3DDEVICE9 m_d3d_device)
{

	// select which vertex format we are using
	m_d3d_device->SetFVF(CUSTOMFVF);
	// select the vertex buffer to display
	m_d3d_device->SetStreamSource(0, m_vb->GetVertexBuffer(), 0, m_vb->GetVertexSize());

	m_Sprite.get()->SetPosition(m_input.get()->Get_mouse_position().x -100, m_input.get()->Get_mouse_position().y-100);
	m_vb->SetPosition(m_input.get()->Get_mouse_position().x + 100, m_input.get()->Get_mouse_position().y + 100);

	// copy the vertex buffer to the back buffer
	m_d3d_device->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	m_Sprite.get()->Draw();


}

void c_d3d_render::RenderFrame(void)
{
	m_d3d_device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	m_d3d_device->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	m_d3d_device->BeginScene();    // begins the 3D scene

	// do rendering on the back buffer here

	m_some_render_foo(m_d3d_device);



	m_d3d_device->EndScene();    // ends the 3D scene

	m_d3d_device->Present(NULL, NULL, NULL, NULL);    // displays the created frame
}

// this is the function that cleans up Direct3D and COM
void c_d3d_render::CleandD3D()
{
	m_vb->GetVertexBuffer()->Release();
	m_d3d_device->Release();    // close and release the 3D device
	m_d3d->Release();    // close and release Direct3D
}

LPDIRECT3DDEVICE9 c_d3d_render::GetDevice()
{
	return m_d3d_device;
}

C_VertexBuffer* c_d3d_render::CreateVertexBuffer()
{
	return new C_VertexBuffer(m_d3d_device);
}

c_d3d_render* c_d3d_render::Get()
{
	static c_d3d_render render;
	return &render;
}
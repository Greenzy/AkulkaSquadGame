#include "C_GameSprite.h"
#include <iostream>

C_GameSprite::C_GameSprite()
{
	//Default the sprite to m_Position (0, 0, 0)
	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.z = 0;

	//When color is set to white, what you see is exactly what the image looks like.
	m_Color = D3DCOLOR_ARGB(255, 255, 255, 255);

	//We are not Initialized yet
	m_Initialized = false;
}

C_GameSprite::C_GameSprite(float pos_x, float pos_y)
{
	//Set the m_Position to the programmer's requested X and Y coordinates.  
	//Default Z to 0
	m_Position.x = pos_x;
	m_Position.y = pos_y;
	m_Position.z = 0;

	//When color is set to white, what you see is exactly what the image looks like.
	m_Color = D3DCOLOR_ARGB(255, 255, 255, 255);

	//We are not Initialized yet
	m_Initialized = false;
}

bool C_GameSprite::Initialize(LPDIRECT3DDEVICE9 device, LPCWSTR file, int width, int height)
{
	//Same functionality as D3DXCreateTextureFromFile EXCEPT width and height are manually entered
	if (!SUCCEEDED(D3DXCreateTextureFromFileEx(device, file,
		width, height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT,
		D3DX_DEFAULT, 0, NULL, NULL, &m_pTexture)))
	{
		printf("can't open texture file: %s", file);
		return false;
	}

	//Attempt to create the sprite
	if (!SUCCEEDED(D3DXCreateSprite(device, &m_Sprite)))
	{
		printf("D3DXCreateSprite error");
		return false;
	}

	m_Initialized = true;

	return true;
}

bool C_GameSprite::IsInitialized()
{
	//Are we Initialized (have a texture and sprite)
	return m_Initialized;
}

void C_GameSprite::Update()
{
	//Update our sprite
}

void C_GameSprite::Draw()
{
	if (m_Sprite && m_pTexture)
	{
		m_Sprite->Begin(D3DXSPRITE_ALPHABLEND);

		m_Sprite->Draw(m_pTexture, NULL, NULL, &m_Position, m_Color);

		m_Sprite->End();
	}
}

C_GameSprite::~C_GameSprite()
{
	if (m_Sprite)
	{
		m_Sprite->Release();
		m_Sprite = 0;
	}

	if (m_pTexture)
	{
		m_pTexture->Release();
		m_pTexture = 0;
	}
}

void C_GameSprite::SetPosition(float pos_x, float pos_y)
{
	m_Position.x = pos_x;
	m_Position.y = pos_y;
}


D3DXVECTOR3 C_GameSprite::GetPosition()
{
	return D3DXVECTOR3(m_Position.x, m_Position.y, NULL);
}
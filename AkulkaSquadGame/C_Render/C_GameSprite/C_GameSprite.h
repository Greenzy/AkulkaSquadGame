#pragma once

//Texture and Sprites and other functions.
#include <d3dx9.h>

class C_GameSprite
{
public:
	//Constructors and Destructor
	C_GameSprite();
	C_GameSprite(float x, float y);
	~C_GameSprite();

	//Sprite Functions
	bool Initialize(LPDIRECT3DDEVICE9 device, LPCWSTR file, int width, int height);
	bool IsInitialized();
	virtual void Update();
	virtual void Draw();
	void SetPosition(float pos_x, float pos_y);
	D3DXVECTOR3 GetPosition();

private:
	//Pointers
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPD3DXSPRITE m_Sprite;

	//Attributes
	D3DXVECTOR3 m_Position;
	D3DCOLOR m_Color;
	bool m_Initialized;
};


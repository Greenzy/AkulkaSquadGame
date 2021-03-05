#pragma once
#include <d3d9.h>
#include "vertex_t.h"
#include <D3dx9tex.h>


#define CUSTOMFVF (D3DFVF_XYZRHW |D3DFVF_TEX1)


class C_VertexBuffer
{
public:
	C_VertexBuffer(LPDIRECT3DDEVICE9 d3d_device);
	~C_VertexBuffer();
	UINT GetVertexSize();
	void SetPosition(int pos_x, int pos_y);
	void CreateSquare(long height, long width, long pos_x, long pos_y);
	LPDIRECT3DVERTEXBUFFER9 GetVertexBuffer();

private:
	LPDIRECT3DVERTEXBUFFER9 m_VertexBuffer;
	vertex_t m_vertex[4];
	long m_width;
	long m_height;
	void* m_p_void;
	LPDIRECT3DDEVICE9 m_d3d_device;
};


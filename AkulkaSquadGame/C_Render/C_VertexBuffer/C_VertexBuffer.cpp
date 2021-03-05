#include "C_VertexBuffer.h"

C_VertexBuffer::C_VertexBuffer(LPDIRECT3DDEVICE9 d3d_device)
{
	m_d3d_device = d3d_device;

}

C_VertexBuffer::~C_VertexBuffer()
{
}


void C_VertexBuffer::CreateSquare(long height, long width, long pos_x, long pos_y)
{
	m_width = width;
	m_height = height;

	m_vertex[0].x = pos_x;
	m_vertex[0].y = pos_y;
			   
	m_vertex[1].x = pos_x + m_width;
	m_vertex[1].y = pos_y;
			   
	m_vertex[2].x = pos_x;
	m_vertex[2].y = pos_y + m_height;
			   
	m_vertex[3].x = pos_x + m_width;
	m_vertex[3].y = pos_y + m_height;

	// create the vertex and store the pointer into v_buffer, which is created globally
	m_d3d_device->CreateVertexBuffer(4 * sizeof(vertex_t),
		D3DUSAGE_WRITEONLY,
		CUSTOMFVF,
		D3DPOOL_MANAGED,
		&m_VertexBuffer,
		NULL);





	m_VertexBuffer->Lock(0, 0, (void**)&m_p_void, 0);   // lock the vertex buffer
	memcpy(m_p_void, m_vertex, sizeof(m_vertex));   // copy the vertices to the locked buffer
	m_VertexBuffer->Unlock();    // unlock the vertex buffer

}

LPDIRECT3DVERTEXBUFFER9 C_VertexBuffer::GetVertexBuffer()
{
	return m_VertexBuffer;
}


UINT C_VertexBuffer::GetVertexSize()
{
	return  sizeof(vertex_t);
}

void C_VertexBuffer::SetPosition(int pos_x, int pos_y)
{
	m_vertex[0].x = pos_x;
	m_vertex[0].y = pos_y;

	m_vertex[1].x = pos_x + m_width;
	m_vertex[1].y = pos_y;

	m_vertex[2].x = pos_x;
	m_vertex[2].y = pos_y + m_height;

	m_vertex[3].x = pos_x + m_width;
	m_vertex[3].y = pos_y + m_height;

	m_VertexBuffer->Lock(0, 0, (void**)&m_p_void, 0);   // lock the vertex buffer
	memcpy(m_p_void, m_vertex, sizeof(m_vertex));   // copy the vertices to the locked buffer
	m_VertexBuffer->Unlock();    // unlock the vertex buffer
}



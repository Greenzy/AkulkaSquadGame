#pragma once
#include <Windows.h>

struct vertex_t
{
	float x, y;// from the D3DFVF_XYZRHW flag
	float z = 0.0f;
	float u, v = 10.0f;   // from the D3DFVF_DIFFUSE flag
};




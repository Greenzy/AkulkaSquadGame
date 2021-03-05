#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "C_AppWindow/C_AppWindow.h"
#include "C_Engine/C_Engine.h"

int main(int argc, char* argv[])
{
	auto engine_ptr = std::make_unique<core::C_Engine>();

	while (!engine_ptr->ExitWasPressed())
	{

	}
	return 0;
}
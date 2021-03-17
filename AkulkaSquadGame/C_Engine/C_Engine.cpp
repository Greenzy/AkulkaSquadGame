#include "C_Engine.h"
#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

using namespace core;

C_Engine::C_Engine()
{
	m_EngineStatus = ENGINE_STATUS_INITING;
	printf("Engine init was started...\n");
	const auto start_time = std::chrono::high_resolution_clock::now();

	//
	// Call all init functions, constructors here
	//

	m_Window = std::make_unique<C_AppWindow>();

	m_Threads[THREAD_LOGIC] = std::thread(logic_thread, this);

	Player = std::make_unique<C_Player>(1);
	NPC = std::make_unique<C_NPC>(0);
	
	
	const auto end_time = std::chrono::duration_cast<std::chrono::nanoseconds,
		long long>(std::chrono::high_resolution_clock::now() - start_time).count();

	// in seconds
	const auto init_time_seconds = static_cast<float>(end_time) / 1000000000.f;

	printf("Engine init was ended! Init time = %.2fs\n", init_time_seconds);
	m_EngineStatus = ENGINE_STATUS_READY;
}

C_Engine::~C_Engine()
{
	m_EngineStatus = ENGINE_STATUS_DESTROYING;
	printf("Engine destroy was started...\n");
	const auto start_time = std::chrono::high_resolution_clock::now();

	//
	// Call any destroy functions, destroy any objects, if they are not smart pointers also here
	//
	m_Window.get()->~C_AppWindow();

	for (auto& thread_ : m_Threads)
	{
		thread_.join();
	}

	const auto end_time = std::chrono::duration_cast<std::chrono::nanoseconds,
		long long>(std::chrono::high_resolution_clock::now() - start_time).count();

	// in seconds
	const auto init_time_seconds = static_cast<float>(end_time) / 1000000000.f;

	printf("Engine destroy was ended! Init time = %.2fs\n", init_time_seconds);
	m_EngineStatus = ENGINE_STATUS_INVALID;
}

void C_Engine::logic_thread(C_Engine* this_engine)
{
	//
	// Wait for engine init finish
	//
	while (this_engine->GetStatus() == ENGINE_STATUS_INITING)
		std::this_thread::sleep_for(1s);

	//
	// Update loop
	//


	while (this_engine->GetStatus() == ENGINE_STATUS_READY)
	{
		// OnUpdate callback for example should be here
		this_engine->m_Window.get()->Broadcast();
		printf("\nNpc id is %i with damage %i", this_engine->NPC.get()->GetID(), this_engine->NPC.get()->GetDamage());
		printf("\nPlayer id is %i with damage %i", this_engine->Player.get()->GetID(), this_engine->Player.get()->GetDamage());
	}
}
#pragma once
#include <thread>
#include <array>
#include "../C_AppWindow/C_AppWindow.h"
#include "../NPC/C_Player/C_Player.h"

namespace core
{
	enum e_EngineStatus : std::uint8_t
	{
		ENGINE_STATUS_INITING = 0u,
		ENGINE_STATUS_DESTROYING = 1u,
		ENGINE_STATUS_READY = 2u,
		ENGINE_STATUS_INVALID = 0xff
	};

	class C_Engine
	{
	public:
		C_Engine();
		~C_Engine();

		e_EngineStatus GetStatus() { return m_EngineStatus; }
		bool ExitWasPressed() { return m_ExitWasPressed; }
	private:
		e_EngineStatus m_EngineStatus = ENGINE_STATUS_INVALID;
		bool m_ExitWasPressed = false;

		enum e_ThreadType : std::uint8_t
		{
			THREAD_LOGIC = 0u,
			THREADS_COUNT,
		};

		std::array<std::thread, THREADS_COUNT> m_Threads;

		static void logic_thread(C_Engine* this_engine);
	private:
		std::unique_ptr<C_AppWindow> m_Window;
		std::unique_ptr<C_Player> Player;
		std::unique_ptr<C_NPC> NPC;
	};
}


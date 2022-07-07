#pragma once
#include "RodEnginePCH.h" 

struct SDL_Window;

namespace dae
{
	class RodEngine
	{
	public:
		void Initialize();
		void Cleanup();
		void Run();
	private:
		static const int MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		SDL_Window* m_Window{};
	};
}
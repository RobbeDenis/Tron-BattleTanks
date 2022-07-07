#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include <RodEngine.h>

int main(int, char* []) 
{
	dae::RodEngine engine;
	engine.Run();
	return 0;
}

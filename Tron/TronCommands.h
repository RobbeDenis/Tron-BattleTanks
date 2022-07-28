#pragma once
#include <Command.h>	

class Move final : public Command
{
public:
	Move(float x, float y) : x(x), y(y) {};

	void Execute() override
	{
		std::cout << "Move x: " << x << ", y: " << y << std::endl;
	}

private:
	float x;
	float y;
};

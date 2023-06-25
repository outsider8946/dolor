#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
namespace sf
{
	class Abstarct
	{
	protected:
		virtual void update(const std::string path, float x,float y, float width,float height, int endFrame, float time, float frame) = 0;

	};

}

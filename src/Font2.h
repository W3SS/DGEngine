#pragma once

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include "PhysFSStream.h"

class Font2 : public sf::Font
{
private:
	std::shared_ptr<sf::PhysFSStream> file;

public:
	Font2(const std::shared_ptr<sf::PhysFSStream>& file_) : file(file_) {}

	bool load()
	{
		if (file == nullptr || file->hasError() == true)
		{
			return false;
		}
		return loadFromStream(*file);
	}
};

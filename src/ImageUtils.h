#pragma once

#include "ImageContainers/ImageContainer.h"
#include <memory>
#include "Palette.h"

namespace ImageUtils
{
	void applyMask(sf::Image& image,
		const sf::Color& transparencyMask = sf::Color::Transparent);

	sf::Image loadImage(const std::string& fileName,
		const sf::Color& transparencyMask = sf::Color::Transparent);

	sf::Image loadImage(const ImageContainer& imgContainer,
		const std::shared_ptr<Palette>& pal);

	sf::Image loadImageFrame(const ImageContainer& imgContainer,
		const Palette& pal, size_t frameIdx);

	sf::Image loadBitmapFontImage(const ImageContainer& imgContainer,
		const char* fileNameBin, const std::shared_ptr<Palette>& pal);

	sf::Image splitImageHorizontal(const sf::Image& img, unsigned pieces = 1);
	sf::Image splitImageVertical(const sf::Image& img, unsigned pieces = 1);
}

//
// Created by Praveen P on 13-11-2025.
//

#ifndef FLIPBOOK_MISC_H
#define FLIPBOOK_MISC_H

#include <SFML/Graphics.hpp>

sf::Image scaleImage(const sf::Image &src, unsigned int scale);
sf::Image* scaleImageptr(const sf::Image* &src, unsigned int scale);
sf::Image* scaleImageHeap(const sf::Image& src, unsigned int scale);

#endif //FLIPBOOK_MISC_H
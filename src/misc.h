//
// Created by Praveen P on 13-11-2025.
//

#ifndef PIKZEL_MISC_H
#define PIKZEL_MISC_H

#include <SFML/Graphics.hpp>

sf::Image scaleImage(const sf::Image &src, unsigned int scale);
sf::Image* scaleImageptr(const sf::Image* &src, unsigned int scale);
sf::Image* scaleImageHeap(const sf::Image& src, unsigned int scale);

#endif //PIKZEL_MISC_H
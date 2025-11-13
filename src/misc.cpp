//
// Created by Praveen P on 13-11-2025.
//

#include "misc.h"


sf::Image scaleImage(const sf::Image& src, unsigned int scale)
{
    sf::Vector2u srcSize = src.getSize();
    sf::Image result({srcSize.x * scale, srcSize.y * scale}, sf::Color::Transparent);;
    //result.create(srcSize.x * scale, srcSize.y * scale);

    for (unsigned int y = 0; y < srcSize.y; ++y)
    {
        for (unsigned int x = 0; x < srcSize.x; ++x)
        {
            sf::Color color = src.getPixel({x, y});

            for (unsigned int dy = 0; dy < scale; ++dy)
            {
                for (unsigned int dx = 0; dx < scale; ++dx)
                {
                    result.setPixel({x * scale + dx, y * scale + dy}, color);
                }
            }
        }
    }

    return result;
}


sf::Image* scaleImageptr(const sf::Image* &src, unsigned int scale)
{
    if (!src || scale == 0)
        return nullptr;

    sf::Vector2u srcSize = src->getSize();
    unsigned int newWidth = srcSize.x * scale;
    unsigned int newHeight = srcSize.y * scale;

    sf::Image* scaled = new sf::Image({newWidth, newHeight}, sf::Color::Transparent);


    for (unsigned int y = 0; y < srcSize.y; ++y)
    {
        for (unsigned int x = 0; x < srcSize.x; ++x)
        {
            sf::Color color = src->getPixel({x, y});


            for (unsigned int dy = 0; dy < scale; ++dy)
            {
                for (unsigned int dx = 0; dx < scale; ++dx)
                {
                    scaled->setPixel({x * scale + dx, y * scale + dy}, color);
                }
            }
        }
    }

    return scaled;
}


sf::Image* scaleImageHeap(const sf::Image& src, unsigned int scale)
{
    sf::Vector2u srcSize = src.getSize();
    sf::Image* result = new sf::Image({srcSize.x * scale, srcSize.y * scale}, sf::Color::Transparent);
    // result->create(srcSize.x * scale, srcSize.y * scale, sf::Color::Transparent);

    for (unsigned int y = 0; y < srcSize.y; ++y)
    {
        for (unsigned int x = 0; x < srcSize.x; ++x)
        {
            sf::Color color = src.getPixel({x, y});

            for (unsigned int dy = 0; dy < scale; ++dy)
            {
                for (unsigned int dx = 0; dx < scale; ++dx)
                {
                    result->setPixel({x * scale + dx, y * scale + dy}, color);
                }
            }
        }
    }

    return result;
}

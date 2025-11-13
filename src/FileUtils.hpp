#pragma once

#include <iostream>
#include <vector>
#include "Canvas.hpp"
#include "pxrt.hpp"



class FileUtils
{
public:
	
	//FileUtils();

	// std::vector<Canvas>& frames;
	// FileUtils(std::vector<Canvas>& frames);
	std::list<Canvas>& frames;
	FileUtils(std::list<Canvas>& frames);


	void convertToGif(uint32_t scale = 1);
	void convertToPng(uint32_t scale = 1);
	std::string open();
	void save();



};


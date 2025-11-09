#pragma once

#include <iostream>
#include <vector>
#include "Canvas.hpp"
#include "pxrt.hpp"



class FileUtils
{
public:
	
	//FileUtils();

	std::vector<Canvas>& frames;
	FileUtils(std::vector<Canvas>& frames);


	void convertToGif();
	std::string open();
	void save();



};


#pragma once
#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>

#include "FileUtils.hpp"
#include "pxrt.hpp"
#include "Events.hpp"
#include "include/nfd.hpp"


class Gui
{
	
	sf::RenderWindow& window;
	inline static bool showColorPicker = false;
	inline static bool showStartupWindow = false;


public:

	Gui(sf::RenderWindow& window);
	~Gui();

	void init();
	void startUp();

	void processEvents(sf::Event &event);

	bool wantMouse();

	void update(sf::Time dt);

	void render();

	void menuBar();
	void drawLeftPanel();
	void drawColorSelector();
	void drawAnimationPanel();
	void drawToolBar();
	void drawColorShadesPanel();


};


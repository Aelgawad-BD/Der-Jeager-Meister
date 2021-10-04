#pragma once
#include <string>

/*
	This file has all the constants and configurables, no magic numbers in code, no sir!
*/

const char TITLE[] = "Der Jeager Meister";

const int SCREEN_WIDTH = 1400; // 840;
const int SCREEN_HEIGHT = 800; // 480;

// TIMING SETTINGS
const int FPS = 60;
const int DELAY_TIME = 0;// 1000.0f / FPS;

const int MARGIN = 10;

const int SPLASH_SCREEN_TIME_DELAY = 1000;

const int BUTTON_FRAMES = 3;


enum ExitCode
{
	FAILED,
	SUCCESS
};

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};



// [ToDo]: Run the game as a state machine
enum GAME_STATE
{
	IntroScreen,
	Menu,
	Options,
	Paused,
	Running,
	Over,
	Undetermined
};

enum BACKGROUND_SCROLL
{
	INFINITE_SCROLL,
	WIDTH_SCROLL
};

// // These are anow Macros in InputHandler.h file
//const int LEFT_ANALOGE_STICK = 1;
//const int RIGHT_ANALOGE_STICK = 2;

#define ON 1
#define OFF 0

/*
	The working directory is where your application thinks it is operating. Typically, your working directory is the directory where
	your executable is at but some programs like Visual Studio change the working directory to where the vcxproj file is located.
	So if your application can't find the image, make sure it is in the right place
*/

/*
	The following is a listing of all the resource files used and referenced in the code
*/

/*
	RULE:
			If a variable name has an underscore file extension at the end, then it is string representing the directory where the resource resides
*/

// ---------------------------  Bitmaps  ------------------------------
const std::string img_background_png = "Resources/PNG/backscene.png";
const std::string img_level_png = "Resources/PNG/level1.png";
const std::string img_title_png = "Resources/PNG/DerJeagerMeister_title.png";
const std::string img_studio_png = "Resources/PNG/studio.png";

// Jeager Meister -- unsre leiblings held
// ... maybe they should be member variables, for every object
const std::string spriteSheet_jeagermeister_png = "Resources/JeagerMeister/JeagerMeister.png";
const std::string texture_introcard_title_png = "Resources/PNG/DerJeagerMeister_title2.png";

// MENU state objects
const std::string texture_menubutton_start_png = "Resources/PNG/start_menubutton.png";
const std::string texture_menubutton_exit_png = "Resources/PNG/exit_menubutton.png";
const std::string texture_menubackground_png = "Resources/PNG/menubackground_blur.png";

const std::string texture_menubackground_base_png = "Resources/PNG/background_base.png";
const std::string texture_menubackground_mountains_png = "Resources/PNG/background_mountains.png";
const std::string texture_menubackground_night_png = "Resources/PNG/background_night.png";
const std::string texture_menubackground_trees_3_png = "Resources/PNG/background_trees_3.png";
const std::string texture_menubackground_trees_2_png = "Resources/PNG/background_trees_2.png";
const std::string texture_menubackground_trees_1_png = "Resources/PNG/background_trees_1.png";
const std::string texture_menubackground_trees_0_png = "Resources/PNG/background_trees_0.png";

const std::string texture_levelbackground_png = "Resources/PNG/menubackground_pale.png";


// PAUSE state objects
const std::string texture_menubutton_resume_png = "Resources/PNG/resume_menubutton.png";
const std::string texture_menubutton_menu_png = "Resources/PNG/menu_menubutton.png";
// ------------------------------------------------------------------
// 
// 
// SPRITE SHEET Standards
//	Ideally, all character sprite sheets should follow the same layout
//	the first row is the Walk animation
//	second is the Running animation

const int NO_OF_FRAMES_PER_ROW = 8;

const int FRAME_1 = 0;
const int FRAME_2 = 1;
const int FRAME_3 = 2;
const int FRAME_4 = 3;
const int FRAME_5 = 4;
const int FRAME_6 = 5;
const int FRAME_7 = 6;
const int FRAME_8 = 7;

enum ANIMATION_ROW
{
	IDLE = 0,
	RUNNING = 1,
	ATTACK = 2
};

const int MENU_BACKGROUND_BASE_SCROLL_SPEED = 1;
#ifndef __j1INPUT_H__
#define __j1INPUT_H__

#include "j1Module.h"
#include "SDL/include/SDL_gamecontroller.h"
#include "SDL/include/SDL_haptic.h"
#include <map>

//#define NUM_KEYS 352
#define NUM_MOUSE_BUTTONS 5
//#define LAST_KEYS_PRESSED_BUFFER 50
#define DEAD_ZONE 10000

#define MAX_CONTROLLER_AXIS 32768

struct SDL_Rect;

enum j1EventWindow
{
	WE_QUIT = 0,
	WE_HIDE = 1,
	WE_SHOW = 2,
	WE_COUNT
};

enum j1KeyState
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

enum j1JoyDir
{
	JOYSTICK_DIR_LEFT, // neg
	JOYSTICK_DIR_RIGHT, // pos
	JOYSTICK_DIR_UP, // neg
	JOYSTICK_DIR_DOWN, // pos
	JOYSTICK_DIR_MAX
};

enum j1JoyStickSide
{
	JOY_STICK_LEFT,
	JOY_STICK_RIGHT,
	JOY_MAX
};





class j1Input : public j1Module
{

public:

	j1Input();

	// Destructor
	virtual ~j1Input();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool PreUpdate();

	// Called before quitting
	bool CleanUp();

	// Gather relevant win events
	bool GetWindowEvent(j1EventWindow ev);

	// Check key states (includes mouse and joy buttons)
	j1KeyState GetKey(int id) const
	{
		return keyboard[id];
	}

	j1KeyState GetMouseButtonDown(int id) const
	{
		return mouse_buttons[id - 1];
	}

	Sint16 GetControllerAxis(SDL_GameControllerAxis axis);

	j1KeyState GetControllerButton(int id) const {
		return controller[id];
	}


	j1KeyState GetControllerAxisPulsation(int id) const
	{
		return controller_axis[id];
	}


	// Get mouse / axis position
	void GetMousePosition(int &x, int &y);
	void GetMouseMotion(int& x, int& y);

	bool		windowEvents[WE_COUNT];
	j1KeyState*	keyboard = nullptr;
	j1KeyState*	mouse_buttons = nullptr;
	j1KeyState* controller = nullptr;
	j1KeyState* controller_axis = nullptr;
	j1KeyState* joystick = nullptr;
	int			mouse_motion_x;
	int			mouse_motion_y;
	int			mouse_x;
	int			mouse_y;

	SDL_GameController* gamePad1 = nullptr;
private:
	

};

#endif // __j1INPUT_H__
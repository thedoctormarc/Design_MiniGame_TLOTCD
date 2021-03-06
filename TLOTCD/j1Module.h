// ----------------------------------------------------
// j1Module.h
// Interface for all engine modules
// ----------------------------------------------------

#ifndef __j1MODULE_H__
#define __j1MODULE_H__

#include <string>
#include <assert.h>
#include "p2Log.h"
#include "PugiXml\src\pugixml.hpp"
#include "Brofiler\Brofiler.h"

struct Collider;

class j1App;

class j1Module
{
public:
	float dt = 0.0F;
	j1Module() : active(false)
	{}

	virtual ~j1Module()
	{}

	void Init()
	{
		active = true;
	}

	// Called before render is available
	virtual bool Awake(pugi::xml_node&)
	{
		return true;
	}

	// Called before the first frame
	virtual bool Start()
	{
		return true;
	}

	// Called each loop iteration
	virtual bool PreUpdate()
	{
		return true;
	}

	// Called each loop iteration
	virtual bool Update(float dt)
	{
		return true;
	}

	// Called each loop iteration
	virtual bool PostUpdate()
	{
		return true;
	}


	// Called before quitting
	virtual bool CleanUp()
	{
		return true;
	}

	virtual bool Load(pugi::xml_node&)
	{
		return true;
	}

	virtual bool Save(pugi::xml_node&) const
	{
		return true;
	}

	// Module activation ---
	bool IsEnabled() const { return active; }

	void Enable()
	{
		if (active == false)
		{
			active = true;
			Start();
		}
	}

	void Disable()
	{
		if (active == true)
		{
			active = false;
			CleanUp();
		}
	}

public:

	std::string	name;
	bool		active = false;
	bool        startInitialized = true; 

};

#endif // __j1MODULE_H__
#pragma once

#include <iostream>
#include "compile_errors.h"

class Spell
{
public:
	std::string virtual use_spell() { throw std::runtime_error("Spell -> use_spell()"); }

};

class ColdSnap : public Spell
{
public :
	std::string use_spell() override
	{
		return "Cold Snap";
	}
};

class GhostWalk : public Spell
{
public:
	std::string use_spell() override
	{
		return "Ghost Walk";
	}
};

class IceWall : public Spell
{
public:
	std::string use_spell() override
	{
		return "Ice Wall";
	}
};

class Tornado : public Spell
{
public:
	std::string use_spell() override
	{
		return "Tornado";
	}
};

class EMP : public Spell
{
public:
	std::string use_spell() override
	{
		return "EMP";
	}
};

class Alacrity : public Spell
{
public:
	std::string use_spell() override
	{
		return "Alacrity";
	}
};

class SunStrike : public Spell
{
public:
	std::string use_spell() override
	{
		return "Sun Strike";
	}
};

class ForgeSpirit : public Spell
{
public:
	std::string use_spell() override
	{
		return "Forge Spirit";
	}
};

class DeafeningBlast : public Spell
{
public:
	std::string use_spell() override
	{
		return "Deafening Blast";
	}
};

class ChaosMeteor : public Spell
{
public:
	std::string use_spell() override
	{
		return "Chaos Meteor";
	}
};

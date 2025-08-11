#pragma once

#include <iostream>
#include "compile_errors.h"

class Spell
{
public:
	Spell()
	{

	}
	virtual ~Spell()
	{

	}
	std::string virtual use_spell() const noexcept { return spell_name_; }
protected:
	std::string spell_name_;
};

class ColdSnap : public Spell
{
public :
	ColdSnap()  { spell_name_ = "Cold snap"; }
};

class GhostWalk : public Spell
{
public:
	GhostWalk() { spell_name_ = "Ghost walk"; }
};

class IceWall : public Spell
{
public:
	IceWall() { spell_name_ = "Ice Wall"; }
};

class Tornado : public Spell
{
public:
	Tornado() { spell_name_ = "Tornado"; }
};

class EMP : public Spell
{
public:
	EMP() { spell_name_ = "EMP"; }
};

class Alacrity : public Spell
{
public:
	Alacrity() { spell_name_ = "Alacrity"; }
};

class SunStrike : public Spell
{
public:
	SunStrike() { spell_name_ = "Sun Strike"; }
};

class ForgeSpirit : public Spell
{
public:
	ForgeSpirit() { spell_name_ = "Forge Spirit"; }
};

class DeafeningBlast : public Spell
{
public:
	DeafeningBlast() { spell_name_ = "Deafening Blast"; }
};

class ChaosMeteor : public Spell
{
public:
	ChaosMeteor() { spell_name_ = "Chaos Meteor"; }
};

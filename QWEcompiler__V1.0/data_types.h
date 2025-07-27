#pragma once

#include "Spells.h"

struct InputKeys
{
	InputKeys(char quas_button = 'q', char wex_button = 'w', 
		char exort_button = 'e', char invole_button = 'r')
		:quas_button(quas_button), wex_button(wex_button),
		exort_button(exort_button), invole_button(invole_button)
	{

	}
	char quas_button;
	char wex_button;
	char exort_button;
	char invole_button;
};




enum token_type : int
{
	quas	= 0,
	wex		= 1,
	exort	= 2,
	invoke  = 3
};

struct Token
{
	Token(token_type t) : type(t) {}

	token_type type;
};



struct Instuction
{
	Instuction(Spell& s) : spell(s) {}
	Spell spell;
};

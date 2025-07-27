#pragma once


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




enum token_type
{
	quas	= 0,
	wex		= 1,
	exort	= 2,
	invoke  = 3
};

struct Token
{
	token_type type;
};



enum Spells
{
	// 9 спелов
};
struct Instuction
{
	Spells spell;
};

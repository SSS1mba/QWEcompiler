#pragma once

#include "Spells.h"


//////////////////////////////////////////////////////General
struct InputKeys
{
	InputKeys(char quas_button = 'q', char wex_button = 'w', 
		char exort_button = 'e', char invole_button = 'r')
		:quas_button(quas_button), wex_button(wex_button),
		exort_button(exort_button), invole_button(invole_button)
	{

	}
	
	const char quas_button;
	const char wex_button;
	const char exort_button;
	const char invole_button;
};


//////////////////////////////////////////////////////Lexer
enum token_type : int
{
	quas	= 0,
	wex		= 1,
	exort	= 2,
	invoke  = 3,
	empty_token = 4
};
class Token
{
public:
	Token(token_type t = empty_token) : type(t) {}

	inline token_type GET_token_type() const noexcept{ return type; }

private:

	token_type type;

};


/////////////////////////////////////////////////////Parser
constexpr size_t empty_slot = static_cast<size_t>(-1);

struct Sphere
{
	Sphere(size_t weight = empty_slot) : weight_(weight) {}

	inline size_t GET_weight() const noexcept { return weight_; }
private:
	size_t weight_;
};

/////////////////////////////////////////////////////InstuctionController
class Instuction
{
public:
	Instuction(const Spell& s = Spell()) : spell(s) {}

	inline Spell GET_spell()  const noexcept { return spell; }

private:
	Spell spell;
};

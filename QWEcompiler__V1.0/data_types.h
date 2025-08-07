#pragma once

#include "Spells.h"
#include "compile_errors.h"


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
	invoke  = 3
};
class Token
{
public:
	Token()
	{

	}
	Token(token_type t ) : type(t) {}

	inline token_type GET_token_type() const noexcept{ return type; }

private:

	token_type type;

};


/////////////////////////////////////////////////////Parser
constexpr size_t DEFAULT_CAPACITY_OF_BOOK = 3;

constexpr int WEIGHT_OF_QUAS = 1;
constexpr int WEIGHT_OF_WEX = 3;
constexpr int WEIGHT_OF_EXORT = 27;


struct Sphere
{
	Sphere() {}
	Sphere(size_t weight) : weight_(weight) {}

	inline size_t GET_weight() const noexcept { return weight_; }
private:
	size_t weight_;
};

class Book
{
public:
	Book(size_t capacity_of_book_ = DEFAULT_CAPACITY_OF_BOOK) : capacity_of_book_(capacity_of_book_), size_of_book(0),
		spheres(new Sphere[capacity_of_book_])
	{

	}

	void add_sphere(const Sphere& sphere) const
	{

	}
	void invoke() const
	{
		if (size_of_book != capacity_of_book_) throw compile_error("There are less than 3 spheres in the book!");
		//static unordered_map<size_t,spell>
	}


private:
	const size_t capacity_of_book_;
	size_t size_of_book;
	Sphere* spheres;

};


//InstuctionController
class Instuction
{
public:
	Instuction()
	{

	}
	Instuction(Spell& s) : spell(s) {}

	inline Spell GET_spell()  const noexcept { return spell; }

private:
	Spell spell;
};

#pragma once

#include <queue>
#include "compile_errors.h"
#include "data_types.h"
#include "KeyWords.h"


constexpr size_t DEFAULT_CAPACITY_OF_BOOK = 3;

constexpr int WEIGHT_OF_QUAS	= 1;
constexpr int WEIGHT_OF_WEX		= 3;
constexpr int WEIGHT_OF_EXORT	= 27;


class Parser
{
public:
	std::queue<Instuction,std::vector<Instuction>> parse(std::queue<Token, std::vector<Token>>& tokens)
	{
		std::queue<Instuction, std::vector<Instuction>> instuction_queue;

		while (!tokens.empty())
		{
			tokens.front() ;
		}

		return instuction_queue;
	}

	Parser(Book book = Book()) : book_(book) {}

private:
	Book book_;
};



struct Sphere
{
	Sphere(int weight = WEIGHT_OF_QUAS) : weiht_(weight) {}
	const int weiht_;
};


class Book
{
public:
	Book(size_t capacity_of_book_ = DEFAULT_CAPACITY_OF_BOOK) : capacity_of_book_(capacity_of_book_)
	{
		spheres = new Sphere[capacity_of_book_];
		size_of_book = 0;
	}
	
	void add_sphere() const
	{

	}
	void invoke()	const
	{

	}


	private :
		const size_t capacity_of_book_;
		size_t size_of_book;
		Sphere* spheres;
	
};


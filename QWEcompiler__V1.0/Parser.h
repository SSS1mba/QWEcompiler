#pragma once

#include <vector>
#include "compile_errors.h"
#include "data_types.h"
#include "KeyWords.h"


constexpr size_t DEFAULT_CAPACITY_OF_BOOK = 3;

constexpr int WEIGHT_OF_QUAS	= 1;
constexpr int WEIGHT_OF_WEX		= 3;
constexpr int WEIGHT_OF_EXORT	= 27;


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


private:
	const size_t capacity_of_book_;
	size_t size_of_book;
	Sphere* spheres;

};
struct Sphere
{
	Sphere(int weight = WEIGHT_OF_QUAS) : weiht_(weight) {}
	const int weiht_;
};


std::allocator< std::vector<Instuction>> instruction_alloc;
using instuction_traits = std::allocator_traits< std::allocator< std::vector<Instuction>>>;


class Parser
{
public:
	std::vector<Instuction>* parse(std::vector<Token>* tokens)
	{
		auto instuctions = instuction_traits::allocate(instruction_alloc,1);
		instuction_traits::construct(instruction_alloc, instuctions, tokens->size() / 4); // тк одна инструкция - это 4 токена (3 сферы + invoke)

		for (const auto& token : *tokens)
		{

		}

		return instuctions;
	}

	Parser(const Book& book) : book_(book) {}

private:
	Book book_;
};






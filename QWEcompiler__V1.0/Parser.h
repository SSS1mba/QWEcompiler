#pragma once

#include <vector>
#include "KeyWords.h"
#include "DEFAUT_VALUES.h"
#include "Book.h"


class Parser
{
public:
	std::vector<Instuction>* parse(std::vector<Token>* tokens);

	Parser(const Book& book) : book_(book) {}

private:
	Book book_;
};







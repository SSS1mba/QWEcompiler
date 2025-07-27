#pragma once

#include <queue>
#include "compile_errors.h"
#include "data_types.h"
#include "KeyWords.h"

class Parser
{
public:
	std::queue<Instuction,std::vector<Instuction>> parse(const std::queue<Token, std::vector<Token>>& tokens)
	{
		std::queue<Instuction, std::vector<Instuction>> instuction_queue;
		return instuction_queue;
	}
};

//надо реализовать идею с весом сферы
enum Sphere
{
	
};
class Book
{

};


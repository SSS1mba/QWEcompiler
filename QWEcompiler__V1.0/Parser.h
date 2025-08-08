#pragma once

#include <vector>
#include "KeyWords.h"
#include "DEFAUT_VALUES.h"
#include "Book.h"


class Parser
{
public:
	std::vector<Instuction>* parse(std::vector<Token>* tokens)
	{
		auto instuctions = instuction_traits::allocate(instruction_alloc,1);
		instuction_traits::construct(instruction_alloc, instuctions); 
		instuctions->reserve(tokens->size() / 4);	// тк одна инструкция - это 4 токена (3 сферы + invoke)

		for (const auto& token : *tokens)
		{
			switch (token.GET_token_type())
			{
			case token_type::quas:				 { book_.emplace_sphere(DEFAULT_WEIGHT_OF_QUAS);  break; }
			case token_type::wex:				 { book_.emplace_sphere(DEFAULT_WEIGHT_OF_WEX);   break; }
			case token_type::exort:				 { book_.emplace_sphere(DEFAULT_WEIGHT_OF_EXORT); break; }
			case token_type::invoke:			 { instuctions->emplace_back(book_.invoke()); break;}

				case token_type::empty_token:	 throw compile_error("empty_token in token_vector");
				default:						 throw compile_error("unknown token");
			}
		}

		return instuctions;
	}

	Parser(const Book& book) : book_(book) {}

private:
	Book book_;
};







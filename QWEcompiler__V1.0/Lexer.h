#pragma once

#include <vector>
#include "compile_errors.h"
#include "data_types.h"
#include "KeyWords.h"


inline size_t skip_white_space(const std::string& str, const size_t start_pos = 0) noexcept
{
	size_t result = start_pos;

	for(;;++result)
	{

		if (result > str.length()) throw compile_error("skip_white_space -> result > str.length()");

		if (str[result] == ' ')		continue;
		if (str[result] == '\t')	continue;
		if (str[result] == '\n')	continue;

		break;
	}
	return result;
}


static std::allocator< std::vector<Token>> token_alloc;
using token_traits = std::allocator_traits< std::allocator< std::vector<Token>>>;


class Lexer
{
public:
	std::vector<Token>* analyse(const std::string& source_code,size_t start, size_t end,const InputKeys& keys) const
	{
		auto tokens = token_traits::allocate(token_alloc,1);
		token_traits::construct(token_alloc, tokens);
		tokens->reserve(source_code.length());

		for (size_t current = start; current < end; ++current)
		{
			current = skip_white_space(source_code, current);

			if (source_code[current] == keys.quas_button)	{ tokens->emplace_back(token_type::quas);	continue; }
			if (source_code[current] == keys.wex_button)	{ tokens->emplace_back(token_type::wex);	continue; }
			if (source_code[current] == keys.exort_button)	{ tokens->emplace_back(token_type::exort);	continue; }
			if (source_code[current] == keys.invole_button) { tokens->emplace_back(token_type::invoke);	continue; }

			else throw compile_error("Unknown_token");
		}

		return tokens;
	}
};




#pragma once

#include <vector>
#include "compile_errors.h"
#include "data_types.h"
#include "KeyWords.h"


inline size_t skip_white_space(const std::string& str, const size_t start_pos = 0) noexcept
{
	return str.find_last_not_of(" \t\n\r\f\v", start_pos);
}


std::allocator< std::vector<Token>> token_alloc;
using token_traits = std::allocator_traits< std::allocator< std::vector<Token>>>;


class Lexer
{
public:
	std::vector<Token>* analyse(const std::string& source_code,size_t start, size_t end,const InputKeys& keys) const
	{
		auto tokens = token_traits::allocate(token_alloc,1);
		token_traits::construct(token_alloc, tokens, source_code.length());

		for (size_t current = start; start <= end; ++current)
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




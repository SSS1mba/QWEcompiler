#pragma once

#include <queue>
#include "compile_errors.h"
#include "data_types.h"
#include "KeyWords.h"


inline size_t skip_white_space(const std::string& str, const size_t start_pos = 0) noexcept
{
	return str.find_last_not_of(" \t\n\r\f\v", start_pos);
}



class Lexer
{
public:
	std::queue<Token, std::vector<Token>> analyse(const std::string& source_code,size_t start, size_t end, InputKeys keys)
	{
		std::queue<Token,std::vector<Token>> token_queue;

		for (size_t current = start; start <= end; ++current)
		{
			current = skip_white_space(source_code, current);

			if (source_code[current] == keys.quas_button)	token_queue.emplace(token_type::quas);
			if (source_code[current] == keys.wex_button)	token_queue.emplace(token_type::wex);
			if (source_code[current] == keys.exort_button)	token_queue.emplace(token_type::exort);
			if (source_code[current] == keys.invole_button) token_queue.emplace(token_type::invoke);

			else throw compile_error("Unknown_token");
		}

		return token_queue;
	}
};




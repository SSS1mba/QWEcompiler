#pragma once

#include <vector>
#include "compile_errors.h"
#include "data_types.h"
#include "KeyWords.h"


class Lexer
{
public:
	std::vector<Token> analyse(const std::string& source_code,size_t start, size_t end, InputKeys keys)
	{

	}
};


inline size_t skip_white_space(const std::string str,size_t start_pos = 0) noexcept
{
	return str.find_last_not_of(" \t\n\r\f\v", start_pos);
}

#pragma once

#include <vector>
#include "DEFAUT_VALUES.h"
#include "KeyWords.h"





class Lexer
{
public:
	static inline size_t skip_white_space(const std::string& str, const size_t start_pos = 0);

	std::vector<Token>* analyse(const std::string& source_code, size_t start, size_t end, const InputKeys& keys) const;
};




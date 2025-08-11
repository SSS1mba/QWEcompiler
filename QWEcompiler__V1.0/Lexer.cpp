#include "Lexer.h"


inline size_t Lexer::skip_white_space(const std::string& str, size_t start_pos)
{
	size_t result = start_pos;
	const size_t len = str.length();
	char c;

	while (result < len) {
		c = str[result];
		if (c == ' ' || c == '\t' || c == '\n') {
			++result;
			continue;
		}
		break;
	}

	return result;
}

std::vector<Token>* Lexer::analyse(const std::string& source_code, size_t start, size_t end, const InputKeys& keys) const
{
	auto tokens = token_traits::allocate(token_alloc, 1);
	token_traits::construct(token_alloc, tokens);
	tokens->reserve(source_code.length());

	for (size_t current = start; ; ++current)
	{
		current = skip_white_space(source_code, current);
		if (current >= end) break;

		if (source_code[current] == keys.quas_button) { tokens->emplace_back(token_type::quas);	continue; }
		if (source_code[current] == keys.wex_button) { tokens->emplace_back(token_type::wex);	continue; }
		if (source_code[current] == keys.exort_button) { tokens->emplace_back(token_type::exort);	continue; }
		if (source_code[current] == keys.invole_button) { tokens->emplace_back(token_type::invoke);	continue; }

		else throw compile_error("Unknown_token");
	}

	return tokens;
}

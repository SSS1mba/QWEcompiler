#pragma once

#include "Lexer.h"
#include "Parser.h"
#include "InstuctionController.h"


class Compiler
{
public :
	Compiler(const Lexer& lexer = Lexer(), const Parser& parser = Parser(DEFAULT_BOOK),
		const InstuctionController& IC = InstuctionController());

	void compile(const std::string& source_code, const std::string& file_path, const std::string& file_name);
private:
	Lexer lexer_;
	Parser parser_;
	InstuctionController instruction_controller_;

	size_t find_start(const std::string& source_code) const;
	InputKeys find_keys(const std::string& source_code) const;
	size_t find_end(const std::string& source_code) const;
	inline char find_key_after_input_word(const std::string& source_code, size_t& input_pos) const
	{
		input_pos = Lexer::skip_white_space(source_code, input_pos);
		if (input_pos == std::string::npos) throw compile_error("Incorrect input: use	 :(");
		return source_code[input_pos++];
	}

};


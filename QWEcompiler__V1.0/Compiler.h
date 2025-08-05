#pragma once

#include "Lexer.h"
#include "Parser.h"
#include "InstuctionController.h"

const Book DEFAULT_BOOK;

class Compiler
{
public :
	Compiler(const Lexer& lexer = Lexer(), const Parser& parser = Parser(DEFAULT_BOOK),
		const InstuctionController& IC = InstuctionController())
		: lexer_(lexer), parser_(parser),instruction_controller_(IC) {}

	void interpritate(const std::string& source_code , const std::string& file_name)
	{
		size_t start   = find_start(source_code);
		InputKeys keys = find_keys (source_code);
		size_t end     = find_end  (source_code);

		auto tokens = lexer_.analyse(source_code, start, end, keys);
		auto instructions = parser_.parse(tokens);
		instruction_controller_.compute(instructions);
	}
private:
	size_t find_start(const std::string& source_code) const
	{
		size_t start_pos = source_code.find(KEYWORD_BASE);

		if (start_pos == std::string::npos) 
			throw compile_error("Cant find keyword base		:(" );

		return start_pos + WORD_BASE_LENGHT;
		
	}
	InputKeys find_keys(const std::string& source_code) const
	{
		size_t input_pos = source_code.find(KEYWORD_INPUT);
		if (input_pos == std::string::npos) return InputKeys();		//вернули значение по-умолчанию ,тк не нашли input:

		if(input_pos + WORD_INPUT_LENGHT >= source_code.length())	
			throw compile_error("Incorrect input: use	 :(");		//вышли за пределы строки
		 

		input_pos += WORD_INPUT_LENGHT;
		char quas_key, wex_key, exort_key,invoke_key;

		input_pos = skip_white_space(source_code, input_pos);
		if (input_pos == std::string::npos) throw compile_error("Incorrect input: use	 :(");		
		quas_key = source_code[input_pos];
		
		input_pos = skip_white_space(source_code, input_pos);
		if (input_pos == std::string::npos) throw compile_error("Incorrect input: use	 :(");
		wex_key = source_code[input_pos];

		input_pos = skip_white_space(source_code, input_pos);
		if (input_pos == std::string::npos) throw compile_error("Incorrect input: use	 :(");
		exort_key = source_code[input_pos];

		input_pos = skip_white_space(source_code, input_pos);
		if (input_pos == std::string::npos) throw compile_error("Incorrect input: use	 :(");
		invoke_key = source_code[input_pos];


		return InputKeys(quas_key, wex_key, exort_key, invoke_key);
	}
	size_t find_end(const std::string& source_code) const
	{
		size_t end_pos = source_code.find(KEYWORD_AMIEN);

		if (end_pos == std::string::npos)
			throw compile_error("Cant find keyword amien		:(");

		return end_pos;
	}

	Lexer lexer_;
	Parser parser_;
	InstuctionController instruction_controller_;
};


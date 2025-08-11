#include "Compiler.h"

Compiler::Compiler(const Lexer& lexer, const Parser& parser, const InstuctionController& IC)
	: lexer_(lexer), parser_(parser), instruction_controller_(IC) { }



void Compiler::compile(const std::string& source_code, const std::string& file_name)
{
	size_t start = find_start(source_code);
	InputKeys keys = find_keys(source_code);
	size_t end = find_end(source_code);

	auto tokens = lexer_.analyse(source_code, start, end, keys);

	auto instructions = parser_.parse(tokens);
	token_traits::destroy(token_alloc, tokens);
	token_traits::deallocate(token_alloc, tokens, 1);

	instruction_controller_.compute(instructions, file_name);
	instuction_traits::destroy(instruction_alloc, instructions);
	instuction_traits::deallocate(instruction_alloc, instructions, 1);
}



size_t Compiler::find_start(const std::string& source_code) const
{
	size_t start_pos = source_code.find(KEYWORD_BASE);

	if (start_pos == std::string::npos)
		throw compile_error("Cant find keyword base		:(");

	return start_pos + WORD_BASE_LENGHT;

}

InputKeys Compiler::find_keys(const std::string& source_code) const
{
	size_t input_pos = source_code.find(KEYWORD_INPUT);
	if (input_pos == std::string::npos) return InputKeys();		//вернули значение по-умолчанию ,тк не нашли input:

	if (input_pos + WORD_INPUT_LENGHT >= source_code.length())
		throw compile_error("Incorrect input: use	 :(");		//исключаем случай , когда input в конце строки


	input_pos += WORD_INPUT_LENGHT;

	char quas_key, wex_key, exort_key, invoke_key;
	quas_key = find_key_after_input_word(source_code, input_pos);
	wex_key = find_key_after_input_word(source_code, input_pos);
	exort_key = find_key_after_input_word(source_code, input_pos);
	invoke_key = find_key_after_input_word(source_code, input_pos);

	return InputKeys(quas_key, wex_key, exort_key, invoke_key);
}

size_t Compiler::find_end(const std::string& source_code) const
{
	size_t end_pos = source_code.find(KEYWORD_AMIEN);

	if (end_pos == std::string::npos)
		throw compile_error("Cant find keyword amien		:(");

	return end_pos;
}

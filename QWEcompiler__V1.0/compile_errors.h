#pragma once
#include <iostream>

class compile_error : public std::runtime_error
{
public:
	compile_error(const char* const  msg) : std::runtime_error(msg) {}
};


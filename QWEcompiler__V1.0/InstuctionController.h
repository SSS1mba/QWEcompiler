#pragma once

#include <fstream>
#include <vector>
#include "DEFAUT_VALUES.h"

class InstuctionController
{
public:
	void compute(std::vector<Instuction>* instuctions, const std::string& file_name)
	{
		std::ofstream file(file_name + ".qwe");

		if( !file.is_open() ) throw compile_error("can`t create .qwe file" );

		for (const auto& instruction : *instuctions)
		{
			file << instruction.GET_spell().use_spell() << "\n";
		}

		file.close();
	}
};


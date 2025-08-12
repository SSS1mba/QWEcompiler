#include "InstuctionController.h"

void InstuctionController::compute(std::vector<Instuction>* instuctions, const std::string& file_name) const
{
	std::ofstream file(file_name);

	if (!file.is_open()) throw compile_error("can`t create a file");

	for (const auto& instruction : *instuctions)
	{
		file << instruction.GET_spell().use_spell() << "\n";
	}

	file.close();
}
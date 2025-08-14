#include "InstuctionController.h"

void InstuctionController::compute(std::vector<Instuction>* instuctions, const std::string& file_path, const std::string& file_name) const
{
	std::string output_path;
	if (file_path.empty())
	{
		output_path = file_name + COMPILED_FILE_TYPE;
	}
	else
	{
		try
		{
			std::filesystem::create_directory(file_path);
			output_path = file_path + '/' + file_name + COMPILED_FILE_TYPE;
		}
		catch(const std::filesystem::filesystem_error& fserr)
		{
			std::cerr << fserr.what() << '\n';
		}
	}


	std::ofstream file(output_path);

	if (!file.is_open()) throw compile_error("can`t create a file");

	for (const auto& instruction : *instuctions)
	{
		file << instruction.GET_spell().use_spell() << "\n";
	}

	file.close();
	std::cout << "File successfully created at: " << std::filesystem::absolute(output_path) << std::endl;
}
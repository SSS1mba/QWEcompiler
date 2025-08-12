#include "UserFileInput.h"

bool check_file_type(const std::string& file_name, const std::string& file_type)
{
	size_t size_of_file_type = file_type.length();

	return file_type == file_name.substr(file_name.size() - size_of_file_type, size_of_file_type);
}

std::string user_dialog()
{
	std::string input;
	std::string path;

	while (true)
	{
		try
		{
			std::cout << "Enter " << SOURCE_CODE_FILE_TYPE<< " file location (or 'q' for exit): ";
			std::cin >> path;

			if (path.empty())
			{
				std::cerr << "its a empty string\n";
				continue;
			}

			if (path == "q") throw Exit();

			if (path.front() == '"' && path.back() == '"') {
				path = path.substr(1, path.size() - 2);
			}

			if (!check_file_type(path, SOURCE_CODE_FILE_TYPE))
			{
				std::cerr << "it is not a " << SOURCE_CODE_FILE_TYPE << "file\n";
				continue;
			}

			return path;
		}
		catch (std::exception& ex)
		{
			std::cerr << "Reading error";
		}
	}

}

std::string qwExe_file_name_reader()
{
	std::string input;

	while (true)
	{
		std::cout << "Enter output file name(and path if need)\n";
		std::cin >> input;

		if (input.empty())
		{
			std::cerr << "its a empty string\n";
			continue;
		}

		if (input.length() > 6 && !check_file_type(input, COMPILE_FILE_TYPE)) // .qwExe - 6 символов
		{
			input += COMPILE_FILE_TYPE;
		}

		return input;
	}
}

std::string read_from_file(const std::string& file_path)
{
    std::ifstream file(file_path, std::ios::binary | std::ios::ate);
    if (!file) throw std::runtime_error("Could not open file " + file_path);

    const auto size = file.tellg();
    file.seekg(0);

    std::string content;
    content.resize(size);
    file.read(&content[0], size);

    return content;
}



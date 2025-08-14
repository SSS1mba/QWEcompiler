#include "UserFileInput.h"

bool check_file_type(const std::string& file_name, const std::string& file_type)
{
	size_t size_of_file_type = file_type.length();

	if (file_name.length() < size_of_file_type) return false;

	return file_type == file_name.substr(file_name.size() - size_of_file_type, size_of_file_type);
}

std::string user_dialog_to_findout_directory( const std::string& file_type) 
{
	std::string path;

	while (true)
	{
		try
		{
			std::cout << "Enter " << file_type << " file location (or 'q' for exit): ";
			std::cin >> path;

			if (path.empty())
			{
				std::cerr << "its a empty string\n";
				continue;
			}

			if (path == "q") throw Exit();

			if (path.front() == '"' && path.back() == '"') //если путь указан с ковычками  (пример: "C:\Users")
			{
				path = path.substr(1, path.size() - 2);
			}

			if (!check_file_type(path, file_type))
			{
				std::cerr << "it is not a " << file_type << " file\n";
				continue;
			}
			

			return path;
		}
		catch (const std::exception& ex)
		{
			std::cerr << "Reading error";
		}
	}

}

std::string qwExe_file_path_reader(const std::string& file_type)
{
	std::string path;
	while (true)
	{
		try
		{
			std::cout << "Enter " << file_type << " file location (or 'q' for exit): ";
			std::cin >> path;

			if (path.empty())
			{
				std::cerr << "its a empty string\n";
				continue;
			}

			if (path == "q") throw Exit();

			if (path.front() == '"' && path.back() == '"') //если путь указан с ковычками  (пример: "C:\Users")
			{
				path = path.substr(1, path.size() - 2);
			}

			return path;
		}
		catch (const std::exception& ex)
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
		std::cout << "Enter output file name :";
		std::cin >> input;

		if (input.empty())
		{
			std::cerr << "its a empty string\n";
			continue;
		}

		if (!check_file_type(input, COMPILED_FILE_TYPE))
		{
			input += COMPILED_FILE_TYPE;
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



#pragma once

#include <iostream>
#include <fstream>
#include "KeyWords.h"

class Exit {};

bool check_file_type(const std::string& file_name, const std::string& file_type); //проверяет тип файла(.txt ,например) файла

std::string user_dialog_to_findout_directory (const std::string& file_type = SOURCE_CODE_FILE_TYPE);
std::string read_from_file(const std::string& file_path);

std::string qwExe_file_path_reader(const std::string& file_type = COMPILED_FILE_TYPE);
std::string qwExe_file_name_reader();

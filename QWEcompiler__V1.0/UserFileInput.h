#pragma once

#include <iostream>
#include <fstream>
#include "KeyWords.h"

class Exit {};

bool check_file_type(const std::string& file_name, const std::string& file_type); //проверяет тип файла(.txt ,например) файла

std::string user_dialog();

std::string read_from_file(const std::string& file_path);

std::string qwExe_file_name_reader();

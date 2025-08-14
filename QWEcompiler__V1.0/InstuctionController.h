#pragma once

#include <fstream>
#include <filesystem>
#include <vector>
#include "DEFAUT_VALUES.h"
#include "KeyWords.h"

class InstuctionController
{
public:
	void compute(std::vector<Instuction>* instuctions, const std::string& file_path, const std::string& file_name) const;
};


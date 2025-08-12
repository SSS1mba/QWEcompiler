#pragma once

#include <fstream>
#include <vector>
#include "DEFAUT_VALUES.h"

class InstuctionController
{
public:
	void compute(std::vector<Instuction>* instuctions, const std::string& file_name) const;
};


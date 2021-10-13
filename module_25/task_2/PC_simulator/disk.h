#pragma once
#include <string>
#include <vector>


const std::string FILE_NAME = "../src/data.txt";

void save(const std::vector<int> &);
std::vector<int> load();

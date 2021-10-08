#pragma once
#include <vector>
#include <string>


const std::string FILE_NAME = "../src/data.txt";

void save(const std::vector<int> &);
std::vector<int> load();

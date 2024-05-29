#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

void checkFile(std::ofstream&);
void writeFishToFile(std::ofstream&, const std::set<std::string>&);

#endif

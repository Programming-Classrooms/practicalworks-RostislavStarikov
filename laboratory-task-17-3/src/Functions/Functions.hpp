#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <cctype> 
#include <unordered_map>
#include <set>

void checkInputFile(std::ifstream&);
void readFile(std::istream&, std::string&, std::unordered_map<std::string, size_t>&, std::set<std::string>&);

#endif

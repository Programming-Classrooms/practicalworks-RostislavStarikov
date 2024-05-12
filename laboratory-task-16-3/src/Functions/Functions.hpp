#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void checkFile(std::ifstream&);
void getText(std::vector<std::string>&, std::ifstream&);
void print(std::vector<std::string>);
void Sort(std::vector<std::string>&);
void quickSort(std::vector<std::string>&, size_t, size_t);
void Search(std::vector<std::string>, char);
void Delete(std::vector<std::string>&, char);
#endif 

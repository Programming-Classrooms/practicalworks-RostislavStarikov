#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

bool checkString(std::string);
void input(std::vector<int>&);
void print(const std::vector<int>&);
int sumOfVector(const std::vector<int>&);
size_t amountOfNumbers(const std::vector<int>&);
size_t operator< (int, const std::vector<int>&);
size_t operator> (int, const std::vector<int>&);
size_t operator== (int, const std::vector<int>&);
size_t operator!= (int, const std::vector<int>&);
size_t operator<= (int, const std::vector<int>&);
size_t operator>= (int, const std::vector<int>&);
void averageArithmeticalWithoutZero(std::vector<int>&);
void addToEachInInterval(std::vector<int>&, int, int);
void replaceEven(std::vector<int>&);
void removeDuplicatesExceptFirstAbs(std::vector<int>&);

#endif

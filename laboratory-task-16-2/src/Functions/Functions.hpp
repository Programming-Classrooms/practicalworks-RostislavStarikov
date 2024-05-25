#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

bool checkString(std::string);

void inputVector(std::vector<int>&);
void printVector(const std::vector<int>&);

int sumVector(const std::vector<int>&);
size_t amountNumbers(const std::vector<int>&);

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

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "src/Student/Student.hpp"
#include "src/Student/StudentAfterFirstSession.hpp"
#include "src/Student/StudentAfterSecondSession.hpp"

double averageGroupAfterFirstSession(Student** arr, size_t size, uint16_t group);
double averageGroupAfterSecondSession(Student** arr, size_t size, uint16_t group);

void randomArrFirst(int*);

void randomArrSecond(int*);


#endif

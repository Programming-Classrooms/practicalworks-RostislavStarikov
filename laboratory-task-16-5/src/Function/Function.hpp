#ifndef FUNCTION_HPP
#define FUNCTION_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdint.h>


struct Student {
    std::string name;
    uint16_t course;
    uint16_t group;
};

void checkFile(std::ifstream&);
std::vector<Student> readStudentsFromFile(const std::string& filename);
void writeStudentsToFile(const std::string& filename, const std::vector<Student>& students);
void sortName(std::vector<Student>& students);
void sortCourseAndGroup(std::vector<Student>& students);

#endif // FUNCTION_H


#include "Functions.hpp"
#include "src/Student/StudentAfterFirstSession.hpp"
#include "src/Student/StudentAfterSecondSession.hpp"

double averageGroupAfterFirstSession(Student** arr, size_t size, uint16_t group)
{
    double result = 0;
    size_t count = 0; // Счетчик студентов в группе

    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i]->getGroup() == group)
        {
            StudentAfterFirstSession* studentAfterFirst = dynamic_cast<StudentAfterFirstSession*>(arr[i]);
            if (studentAfterFirst)
            {
                result += studentAfterFirst->calculateAverageGrade();
                ++count;
            }
        }
    }
    if (count != 0)
    {
        result /= count; 
    }

    return result;
}

double averageGroupAfterSecondSession(Student** arr, size_t size, uint16_t group)
{
    double result = 0;
    size_t count = 0; // Счетчик студентов в группе

    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i]->getGroup() == group)
        {
            StudentAfterSecondSession* studentAfterSecond = dynamic_cast<StudentAfterSecondSession*>(arr[i]);
            if (studentAfterSecond)
            {
                result += studentAfterSecond->calculateAverageGrade();
                ++count;
            }
        }
    }
    if (count != 0)
    {
        result /= count; 
    }

    return result;
}

void randomArrFirst(int* arr)
{
    for (size_t i = 0; i < 4; ++i)
    {
        arr[i] = (rand() % 10) + 1;
    }
}


void randomArrSecond(int* arr) {
    for (size_t i = 0; i < 5; ++i)
    {
        arr[i] = (rand() % 10) + 1;
    }

}

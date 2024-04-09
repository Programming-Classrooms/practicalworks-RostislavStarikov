#include "src/Functions/Functions.hpp"
#include "src/Student/Student.hpp"
#include "src/Student/StudentAfterFirstSession.hpp"
#include "src/Student/StudentAfterSecondSession.hpp"


int main() {
    srand(time(0));

    const size_t numStudents = 6;

    // Создание массива указателей на объекты Student
    Student** students = new Student * [numStudents];

    // Создание объектов StudentAfterFirstSession и StudentAfterSecondSession
    int firstSemesterScores1[4];
    randomArrFirst(firstSemesterScores1);
    students[0] = new StudentAfterFirstSession(std::string("Ivan"), 1, 101, 120, firstSemesterScores1);
    int firstSemesterScores2[4];
    randomArrFirst(firstSemesterScores2);
    students[1] = new StudentAfterFirstSession(std::string("Vasya"), 1, 102, 121, firstSemesterScores2);

    int firstSemesterScores3[4];
    randomArrFirst(firstSemesterScores3);
    students[2] = new StudentAfterFirstSession(std::string("Petya"), 1, 101, 123, firstSemesterScores3);

    int secondSemesterScores1[5];
    randomArrFirst(secondSemesterScores1);
    randomArrSecond(secondSemesterScores1);
    students[3] = new StudentAfterSecondSession(std::string("Slava"), 1, 101, 124, firstSemesterScores1, secondSemesterScores1);

    int secondSemesterScores2[5];
    randomArrFirst(secondSemesterScores2);
    randomArrSecond(secondSemesterScores2);
    students[4] = new StudentAfterSecondSession(std::string("Timur"), 1, 102, 125, firstSemesterScores2, secondSemesterScores2);

    int secondSemesterScores3[5];
    randomArrFirst(secondSemesterScores3);
    randomArrSecond(secondSemesterScores3);
    students[5] = new StudentAfterSecondSession(std::string("Kirill"), 1, 101, 126, firstSemesterScores3, secondSemesterScores3);

    std::cout << "Fisrt session student: ";
    for (size_t i = 0; i < 3; ++i)
    {
        std::cout << *students[i];
    }    
    std::cout << "\nSecond session student: ";
    for (size_t i = 3; i < 6; ++i)
    {
        std::cout << *students[i];
    }

    // Вызов функций для расчета среднего балла для группы после первого и второго семестров
    double averageScoreFirstSemester = averageGroupAfterFirstSession(students, numStudents, 101);
    std::cout << "\nAverage score for the group after the first semester: " << averageScoreFirstSemester << std::endl;

    double averageScoreSecondSemester = averageGroupAfterSecondSession(students, numStudents, 101);
    std::cout << "\nAverage score of the group after the second semester: " << averageScoreSecondSemester << std::endl;

    // Освобождение памяти
    for (size_t i = 0; i < numStudents; ++i) {
        delete students[i];
    }
    delete[] students;

    return 0;
}

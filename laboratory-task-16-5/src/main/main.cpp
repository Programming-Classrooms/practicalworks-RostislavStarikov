#include "src/Function/Function.hpp"

int main() {
    try
    {
        std::vector<Student> students = readStudentsFromFile("src/Function/Students.txt");

        // Сортируем студентов по ФИО
        sortName(students);
        writeStudentsToFile("src/Function/Fio.txt", students);

        // Сортируем студентов по курсу и группе
        sortCourseAndGroup(students);
        writeStudentsToFile("src/Function/Groups.txt", students);

        std::cout << "Files Fio.txt and Groups.txt created!" << std::endl;

        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
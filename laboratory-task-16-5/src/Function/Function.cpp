#include "Function.hpp"

//Проверка файла
void checkFile(std::ifstream& fin)
{
	if (!fin.good())
	{
        throw std::runtime_error("File isn't exist"); //файл не найден
	}
	if (!fin)
	{
        throw std::runtime_error("Input file error"); //Ошибка открытия файла
	}
    if (fin.peek() == EOF)
    {
        throw std::runtime_error("File is empty"); //файл пустой
    }
}

std::vector<Student> readStudentsFromFile(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream fin(filename);
    checkFile(fin);

    std::string surname, name, fullName;
    uint16_t course, group;
    while (fin >> surname >> name >> course >> group) {
        fullName = (surname + ' ' + name);
        students.push_back({ fullName, course, group });
    }

    fin.close();
    return students;
}

void writeStudentsToFile(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file");
    }

    for (const auto& student : students) {
        file << student.name << " " << student.course << " " << student.group << std::endl;
    }

    file.close();
}

// Компаратор для сравнения и сортировки по ФИО
bool compareName(const Student& a, const Student& b) {
    return a.name < b.name;
}

// Компаратор для сравнения и сортировки по курсу и группе
bool compareCourseAndGroup(const Student& a, const Student& b) {
    if (a.course == b.course) {
        if (a.group == b.group) {
            return a.name < b.name;
        }
        return a.group < b.group;
    }
    return a.course < b.course;
}

void sortName(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), compareName);
}

void sortCourseAndGroup(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), compareCourseAndGroup);
}

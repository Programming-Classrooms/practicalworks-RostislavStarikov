#include "src/Student/Student.hpp"
#include "src/Person/Person.hpp"
#include "src/Professor/Professor.hpp"

void menu() {
    const int maxObjects = 100;
    Person* objects[maxObjects]{}; // Массив указателей на объекты типа Person

    int choice;
    int numObjects = 0;

    do {
        // Отобразить меню
        std::cout << "\nMenu:\n1. Enter student\n2. Enter the professor\n3. Display a list of students\n4. Display a list of professor\n5. Finish work\nChoice:";
        std::cin >> choice;
        std::cin.ignore();

        if (std::cin.fail()) 
        {
            std::cout << "Wrong choice!!!\n";
            choice = 5;
        }
        switch (choice) {
        case 1:
            // Создание и ввод информации о студенте
            objects[numObjects] = new Student(); 
            std::cin >> static_cast<Student&>(*objects[numObjects]); // Перегруженный оператор ввода для Student
            numObjects++;
            break;
        case 2:
            // Создание и ввод информации о преподавателе
            objects[numObjects] = new Professor(); 
            std::cin >> static_cast<Professor&>(*objects[numObjects]); // Перегруженный оператор ввода для Professor
            numObjects++;
            break;
        case 3:
            // Вывод списка студентов
            std::cout << "Student:\n";
            for (int i = 0; i < numObjects; i++) {
                if (dynamic_cast<Student*>(objects[i]))
                {
                    std::cout << "Student:\n";
                    objects[i]->print(std::cout);
                }
            }
            break;
        case 4:
            // Вывод списка преподавателей
            std::cout << "Professor:\n";
            for (int i = 0; i < numObjects; i++) {
                if (dynamic_cast<Professor*>(objects[i]))
                {
                    std::cout << "Professor:\n";
                    objects[i]->print(std::cout);
                }
            }
            break;
        case 5:
            // Очистка памяти и выход из программы
            std::cout << "Exit from menu...\n";
            for (int i = 0; i < numObjects; i++) {
                delete objects[i];
            }
            numObjects = 0;
            break;
        case 6:
            std::cout << "Wrong choice. Please try again.\n";
            break;
        default:
            std::cout << "Wrong choice. Please try again.\n";
        }
    } while (choice != 5);
}

int main()
{
    try
    {
        menu();
        return 0;
    }
    catch (std::exception& er)
    {
        std::cout << er.what() << '\n';
    }
}

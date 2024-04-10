#include "src/TreeContainer/TreeContainer.hpp"

int main() {
    try {
        TreeContainer container;

        // Получение данных деревьев из файла
        container.loadTreesFromFile();

        // Вывод информации о деревьях
        container.displayTreeInfo(std::cout);

        // Подсчет и вывод количества лесных деревьев
        int forestTreeCount = container.countTreesOfKind("forest");
        std::cout << "\nNumber of forest trees:" << forestTreeCount << '\n';

        // Подсчет и вывод количества фруктовых деревьев
        int fruitTreeCount = container.countTreesOfKind("fruit");
        std::cout << "\nNumber of fruit trees:" << fruitTreeCount << '\n';

        // Вывод информации о деревьях после сортировки
        container.displayTreeInfo(std::cout);

        // Сортировка деревьев по имени и возрасту
        container.sortTreesByNameAndAge(std::cout);
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
}

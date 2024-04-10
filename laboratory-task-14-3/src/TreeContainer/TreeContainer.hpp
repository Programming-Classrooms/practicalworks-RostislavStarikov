#ifndef TREE_CONTAINER_H
#define TREE_CONTAINER_H

#include "src/Tree/Tree.hpp"
#include <vector>
#include <algorithm>
#include <fstream>

class TreeContainer {
private:
    std::vector<Tree*> trees;

public:
    TreeContainer() = default;
    ~TreeContainer();

    // Добавление дерева в контейнер
    void addTree(Tree* tree);

    // Вывод всех деревьев
    void displayTreeInfo(std::ostream&);

    // Подсчет древьве определенного типа в контейнере 
    int countTreesOfType(TypeTree type);

    // Подсчет каждого вида деревьев
    int countTreesOfKind(const std::string& kind);

    // Сортировка деревьев по имени и возрасту
    void sortTreesByNameAndAge(std::ostream&);

    // Заполнение контейнера  из файла
    void loadTreesFromFile();
};

#endif
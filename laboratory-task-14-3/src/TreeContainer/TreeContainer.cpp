#include "TreeContainer.hpp"
#include "src/Tree/ForestTree.hpp"
#include "src/Tree/FruitTree.hpp"
#include <exception>
// Деструктор
TreeContainer::~TreeContainer() {
    for (int i = 0; i < trees.size(); i++) {
        Tree* tree = trees[i];
        delete tree;
    }
}

// Добавление дерева в контейнер
void TreeContainer::addTree(Tree* tree) {
    trees.push_back(tree);
}

// Вывод всех деревьев
void TreeContainer::displayTreeInfo(std::ostream& out) {
    for (int i = 0; i < trees.size(); i++) {
        Tree* tree = trees[i];
        tree->print(out);
    }
}

// Подсчет древьве определенного типа в контейнере 
int TreeContainer::countTreesOfType(TypeTree type) {
    int count = 0;
    for (int i = 0; i < trees.size(); i++) {
        Tree* tree = trees[i];
        if (tree->getType() == type) {
            count++;
        }
    }
    return count;
}

// Подсчет каждого вида деревьев
int TreeContainer::countTreesOfKind(const std::string& kind) {
    int count = 0;
    for (int i = 0; i < trees.size(); i++)
    {
        Tree* tree = trees[i];
        if (dynamic_cast<ForestTree*>(tree) && kind == "forest") {
            count++;
        }
        else if (dynamic_cast<FruitTree*>(tree) && kind == "fruit") {
            count++;
        }
    }
    return count;
}

// Сортировка деревьев по имени и возрасту
void TreeContainer::sortTreesByNameAndAge(std::ostream& out) {
    int n = trees.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (trees[j]->getName() > trees[j + 1]->getName() ||
                (trees[j]->getName() == trees[j + 1]->getName() && trees[j]->getAge() < trees[j + 1]->getAge())) {
                Tree* temp = trees[j];
                trees[j] = trees[j + 1];
                trees[j + 1] = temp;
            }
        }
    }

    // Вывод информации о деревьях
    for (int i = 0; i < trees.size(); i++) {
        Tree* tree = trees[i];
        tree->print(out);
    }
}

// Заполнение контейнера  из файла
void TreeContainer::loadTreesFromFile() 
{
    std::ifstream file("src/file/trees.txt");
    if (!file.good())
    {
        throw std::runtime_error("File does not exist.\n");
    }
    if (!file)
    {
        throw std::runtime_error("File is not opened.\n");
    }
    if (file.peek() == EOF)
    {
        throw std::runtime_error("File is empty.\n");
    }

    std::string name;
    uint16_t age;
    int type;
    uint32_t quantityOrWeight;
    uint32_t quantityOfWood;
    uint32_t storageDuration;

    while (file >> name >> age >> type) {
        if (type == 0) { // ForestTree
            file >> quantityOfWood;
            addTree(new ForestTree(name, age, TypeTree::deciduous, quantityOfWood));
        }
        else if (type == 1) { // FruitTree
            file >> quantityOrWeight >> storageDuration;
            addTree(new FruitTree(name, age, TypeTree::coniferous, quantityOrWeight, storageDuration));
        }
    }

    file.close();
}
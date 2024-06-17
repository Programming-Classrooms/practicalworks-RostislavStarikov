#include "ForestTree.hpp"

/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/

ForestTree::ForestTree() :Tree(), quantityOfWood(0)
{}

ForestTree::ForestTree(std::string initName, uint16_t initAge, TypeTree initType, uint32_t initQuantityOfWood) : Tree(initName, initAge, initType), quantityOfWood(initQuantityOfWood)
{}

ForestTree::~ForestTree()
{}

/*================================================================================*/
/*==================================== Геттеры ===================================*/
/*================================================================================*/


uint32_t ForestTree::getQuantityOfWood() const
{
    return this->quantityOfWood;
}

/*================================================================================*/
/*================================= Вывод в поток ================================*/
/*================================================================================*/

std::ostream& ForestTree::print(std::ostream& out)
{
    Tree::print(out);
    out << "\nQuantity of wood:\t\t" << quantityOfWood;
    out << "\n==========================================\n";
    return out;
}

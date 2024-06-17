#ifndef FOREST_TREE
#define FOREST_TREE

#include "Tree.hpp"

class ForestTree : public Tree
{
private:
	uint32_t quantityOfWood;
public:
	// Конструкторы
	ForestTree();
	ForestTree(std::string, uint16_t, TypeTree, uint32_t);
	~ForestTree();

	// Геттеры
	uint32_t getQuantityOfWood() const;

	// Вывод в поток 
	virtual std::ostream& print(std::ostream&) override;
};
#endif

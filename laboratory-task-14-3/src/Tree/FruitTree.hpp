#ifndef FRUIT_TREE
#define FRUIT_TREE

#include "Tree.hpp"

class FruitTree : public Tree
{
private:
	uint32_t harvestWeight;
	uint32_t averageStorageDuration;
public:
	// Конструкторы
	FruitTree();
	FruitTree(std::string, uint16_t, TypeTree, uint32_t, uint32_t);
	~FruitTree();

	// Геттеры
	uint32_t getHarvestWeight() const;
	uint32_t getAverageStorageDuration() const;

	// Вывод в поток 
	virtual std::ostream& print(std::ostream&) override;
};
#endif

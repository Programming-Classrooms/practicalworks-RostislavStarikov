#include "FruitTree.hpp"

/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/

FruitTree::FruitTree() : Tree(), harvestWeight(0), averageStorageDuration(0)
{}
FruitTree::FruitTree(std::string initName, uint16_t initAge, TypeTree initType, uint32_t initHarvestWeight, uint32_t initAverageStorageDuration) : Tree(initName, initAge, initType), harvestWeight(initHarvestWeight), averageStorageDuration(initAverageStorageDuration)
{}
FruitTree::~FruitTree()
{}


/*================================================================================*/
/*==================================== Геттер ====================================*/
/*================================================================================*/

uint32_t FruitTree::getHarvestWeight() const
{
	return this->harvestWeight;
}

uint32_t FruitTree::getAverageStorageDuration() const
{
	return this->averageStorageDuration;
}

/*================================================================================*/
/*================================= Вывод в поток ================================*/
/*================================================================================*/

std::ostream& FruitTree::print(std::ostream& out)
{
	Tree::print(out);
	out << "\nHarvest weight:\t\t\t" << harvestWeight;
	out << "\nAverage storage duration:\t" << averageStorageDuration;
	out << "\n==========================================\n";
	return out;
}

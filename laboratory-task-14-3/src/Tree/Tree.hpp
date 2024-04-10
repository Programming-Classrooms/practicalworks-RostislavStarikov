#ifndef TREE
#define TREE
#include <iostream>

enum class TypeTree
{
	deciduous,
	coniferous,
};
class Tree
{
private:
	std::string name;
	uint16_t age;
	TypeTree type;
public:
	// Конструкторы
	Tree(std::string = "",uint16_t = 0, TypeTree = TypeTree::deciduous);
	virtual ~Tree();

	// Геттеры
	std::string getName() const;
	uint16_t getAge() const;
	TypeTree getType() const;

	// Вывод в поток
	virtual std::ostream& print(std::ostream&);
}; 
#endif

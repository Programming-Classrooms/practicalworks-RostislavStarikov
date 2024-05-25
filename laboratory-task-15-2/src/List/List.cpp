#include "List.hpp"

/*================================================================================*/
/*============================ Конструктор копирования ===========================*/
/*================================================================================*/

List::List(const List& rhs)
{
    Clone(rhs);
}

List::~List() {
    Clear();
}

/*================================================================================*/
/*============================== Проверка на пустоту =============================*/
/*================================================================================*/


bool List::isEmpty()
{
    return (first == nullptr);
}

/*================================================================================*/
/*================================= Клонирование =================================*/
/*================================================================================*/

void List::Clone(const List& obj)
{
    Node* currentNodeObj = obj.first;
    Node* lastNode = nullptr;
    while (currentNodeObj != nullptr)
    {
        Node* currentNode = new Node;
        currentNode->val = new Product(*(currentNodeObj->val)); // Создаем новый объект Product
        currentNode->next = nullptr;
        if (lastNode == nullptr)
        {
            first = currentNode;
        }
        else
        {
            lastNode->next = currentNode;
        }
        lastNode = currentNode;
        currentNodeObj = currentNodeObj->next;
    }
}

/*================================================================================*/
/*======================= Перегрузка оператора присваивания ======================*/
/*================================================================================*/


const List& List::operator=(const List& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    Clear();
    Clone(rhs);
    return *this;
}

/*================================================================================*/
/*============================ Перегрузка оператора [] ===========================*/
/*================================================================================*/
Product& List::operator[](size_t ind)
{
    if (isEmpty())
    {
        throw std::invalid_argument("List is empty!!!");
    }

    size_t tempInd = 0;
    Node* current = first;
    while(tempInd != ind)
    {
        if (current->next == nullptr)
        {
            throw std::out_of_range("iIndex value is out of size!!!");
        }

        current = current->next;
        ++tempInd;
    }

    return *current->val;

}

/*================================================================================*/
/*================= Вставка нового элемента в указанную позицию ==================*/
/*================================================================================*/

void List::InsertByIndex(const Product& value, size_t ind) 
{
    Node* newNode = new Node;
    newNode->val = new Product(value); // Создание нового объекта Product
    newNode->next = nullptr;

    if (ind == 0)
    {
        newNode->next = first;
        first = newNode;
        return;
    }

    // вставка в конец

    size_t tempInd = 1;
    Node* slow = first;
    Node* fast = first->next;

    while(tempInd != ind)
    {
        if (slow-> next == nullptr)
        {
            throw std::out_of_range("Index out of range!!!");
        }

        slow = slow->next;
        fast = fast->next;
        ++tempInd;
    }

    slow->next = newNode;
    newNode->next = fast;
}

/*================================================================================*/
/*===================== Удаление первого элемента по индексу =====================*/
/*================================================================================*/

void List::DeleteByIndex(size_t ind)
{
    if (isEmpty())
    {
        throw std::invalid_argument("List is empty!!!");
    }

    Node* slow = first;
    if (ind == 0)
    {
        delete first;
        first = slow;

    }
    size_t tempInd = 1;
    Node* fast = first->next;

    while(tempInd != ind)
    {

        if (slow-> next == nullptr)
        {
            throw std::out_of_range("Index out of range!!!");
        }

        slow = slow->next;
        fast = fast->next;
        ++tempInd;
    }
    slow->next = fast->next;
    delete fast;
}

/*================================================================================*/
/*========================= Удаление элемента по значению ========================*/
/*================================================================================*/


void List::DeleteByValue(const Product& initValue)
{
    if (isEmpty())
    {
        throw std::invalid_argument("List is empty!!!");
    }

    Node* current = first;
    Node* previous = nullptr;

    // Проверка первого элемента списка на соответствие initValue
    while (current != nullptr && *current->val == initValue) {
        first = current->next;
        delete current->val; // Удаляем объект Product
        delete current;
        current = first;
    }

    // Проходим по оставшимся элементам списка
    while (current != nullptr) {
        if (*current->val == initValue) {
            if (previous != nullptr) {
                previous->next = current->next;
            }
            delete current->val; // Удаляем объект Product
            delete current;
            current = previous != nullptr ? previous->next : first; // Переходим к следующему элементу
        }
        else {
            previous = current; // Переходим к следующему элементу
            current = current->next;
        }
    }
}

/*================================================================================*/
/*================== Просмотр списка с изменением всех значений ==================*/
/*================================================================================*/

void List::modifyAllValuse(Product newValue) const
{
    Node* current = first;
    while (current != nullptr) {
        *current->val = newValue;
        current = current->next;
    }
}

/*====================================================================================================*/
/*====== метод, выводящий содержимое списка от первого до последнего элемента в указанный поток ======*/
/*====================================================================================================*/
std::ostream& List::OutputStream(std::ostream& out)
{
    Node* current = first;
    out << "List: ";
    while (current != nullptr) {
        out << *(current->val) << " ";
        current = current->next;
    }
    out << std::endl;
}

/*================================================================================*/
/*================= сортировкa списка по возрастанию или убыванию ================*/
/*================================================================================*/
void List::Sort()
{
    if (isEmpty())
    {
        throw std::runtime_error("List is empty!!!");
    }

    // Создаем новый список для отсортированных элементов
    Node* sorted = nullptr;

    while (first != nullptr)
    {
        // Найдем узел с минимальным значением
        Node** minMax = &first;
        Node** current = &first->next;

        while (*current != nullptr)
        {
            if ((*current)->val->getCost() < (*minMax)->val->getCost())
            {
                minMax = current;
            }
            current = &(*current)->next;
        }

        // Перемещаем мин элемент в начало
        Node* temp = *minMax;
        *minMax = (*minMax)->next; // Убираем элемент из списка
        temp->next = sorted;
        sorted = temp;
    }

    // Обновляем указатель на первый элемент
    first = sorted;
}



/*================================================================================*/
/*================================ Удаление листа ================================*/
/*================================================================================*/


void List::Clear()
{
    Node* p = first;
    while (p != nullptr)
    {
        Node* q = p->next;
        delete p;
        p = q;
    }
    first = nullptr;
}


/*================================================================================*/
/*======================== Отображение содержимого списка ========================*/
/*================================================================================*/

std::ostream& operator<<(std::ostream& out, List& obj)
{
    List::Node* current = obj.first;
    out << "List: ";
    while (current != nullptr) {
        out << *(current->val) << " ";
        current = current->next;
    }
    out << std::endl;
    return out;
}
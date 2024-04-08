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
/*==================== Вставка нового элемента в начало списка ===================*/
/*================================================================================*/

void List::InsertFirst(const Product& initValue)
{
    Node* newNode = new Node;
    newNode->val = new Product(initValue); // Создание нового объекта Product
    newNode->next = first;
    first = newNode;
}

/*================================================================================*/
/*==================== Вставка нового элемента в конец списка ====================*/
/*================================================================================*/

void List::InsertLast(const Product& value) {
    Node* newNode = new Node;
    newNode->val = new Product(value); // Создание нового объекта Product
    newNode->next = nullptr;

    if (isEmpty()) {
        first = newNode;
    }
    else {
        Node* current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

/*================================================================================*/
/*======================= Удаление первого элемента списка =======================*/
/*================================================================================*/

void List::DeleteFirst()
{
    if (isEmpty())
    {
        throw std::invalid_argument("List is empty!!!");
    }

    Node* temp = first;
    first = first->next;
    delete temp->val; // Удаляем объект Product
    delete temp;
}

/*================================================================================*/
/*====================== Удаление последнего элемента списка =====================*/
/*================================================================================*/

void List::DeleteLast()
{
    if (isEmpty())
    {
        throw std::invalid_argument("List is empty!!!");
    }

    // Если в списке один элемент
    if (first->next == nullptr) {
        delete first->val; // Удаляем объект Product
        delete first;
        first = nullptr;
        return;
    }

    Node* current = first;
    Node* previous = nullptr;

    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }

    // Удаляем последний элемент
    delete current->val; // Удаляем объект Product
    delete current;
    // Устанавливаем указатель предыдущего элемента на nullptr
    previous->next = nullptr;
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

/*====================================================================================================*/
/*======= Поиск элемента по значению с подсчетом числа сравнений, выполненных в процессе поиска ======*/
/*====================================================================================================*/

List::Node* List::Search(const Product& initValue, size_t& counter)
{
    counter = 0; // Инициализация счетчика сравнений

    Node* current = first;

    // Проходим по всем элементам списка
    while (current != nullptr) {
        counter++;

        if (*current->val == initValue) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
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

/*================================================================================*/
/*================== Просмотр списка с вызовом callback-функции ==================*/
/*================================================================================*/

void List::viewWitchCallback(void(*callback)(Product)) const
{
    Node* current = first;
    while (current != nullptr) {
        callback(*(current->val));
        current = current->next;
    }
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
        delete p->val; // Удаляем объект Product
        delete p;
        p = q;
    }
    first = nullptr;
}


/*================================================================================*/
/*======================== Отображение содержимого списка ========================*/
/*================================================================================*/

void List::display() const
{
    Node* current = first;
    std::cout << "List: ";
    while (current != nullptr) {
        std::cout << *(current->val) << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

/*================================================================================*/
/*========================== Callback для функции вывода =========================*/
/*================================================================================*/


void List::prProductValue(Product value) const
{
    std::cout << value << ' ';
}

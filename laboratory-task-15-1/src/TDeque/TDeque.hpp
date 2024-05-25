#ifndef TDEQUE_HPP
#define TDEQUE_HPP

#include <iostream>

template <typename TInfo>
class TDeque /* дек – двустороння очередь */
{
protected:
    struct TDequeItem // элемент дека
    {
        TInfo Info; // данные
        TDequeItem* next; // указатель на следующий элемент
        TDequeItem* prev; // указатель на предыдущий элемент
        TDequeItem(TInfo, TDequeItem*, TDequeItem*) TDeque<TInfo>::TDequeItem::TDequeItem(TInfo inInfo, TDequeItem* inNext, TDequeItem* inPrev) :
            Info(inInfo),
            next(inNext),
            prev(inPrev)
    {}
    };
    /* указатели на первый и последний элементы в списке */
    TDequeItem* front, * rear;
    int size; // количество элементов в деке
    void Erase(); // удаление всех элементов
    void Clone(const TDeque&);
    void DeleteItem(TDequeItem*); // удаление элемента по указателю
    void* PtrByIndex(unsigned)const; // указатель на элемент с заданным индексом
public:
    TDeque(); // конструктор
    TDeque(const TDeque&); // конструктор копирования
    virtual ~TDeque(); // деструктор
    void InsFront(TInfo); // включить элемент в голову дека
    void InsRear(TInfo); // включить элемент в хвост дека
    bool DelFront(TInfo&); // исключить элемент из головы дека
    bool DelRear(TInfo&); // исключить элемент из хвоста дека
    const TDeque& operator = (const TDeque&);// оператор присваивания
    const TInfo& GetByIndex(unsigned)const; // получить элемент по индексу
    void SetByIndex(TInfo, unsigned); // изменить элемент по индексу
    void Browse(void(*)(TInfo&)); // просмотр с изменением элементов
    void Browse(void(*)(TInfo)) const; // просмотр без изменения элементов
};

/*================================================================================*/
/*============================ удаление всех элементов ===========================*/
/*================================================================================*/
template <typename TInfo>
void TDeque<TInfo>::Erase()
{
    while (size > 0) {
        TInfo temp;
        DelFront(temp);
    }
}

/*================================================================================*/
/*================================= Клонирование =================================*/
/*================================================================================*/
template<typename TInfo>
void TDeque<TInfo>::Clone(const TDeque& rhs)
{
    if (this != &rhs)
    {
        TDequeItem* current = rhs.front;
        while (current != nullptr) {
            InsRear(current->Info);
            current = current->next;
        }
    }
}

/*================================================================================*/
/*======================== удаление элемента по указателю ========================*/
/*================================================================================*/
template<typename TInfo>
void TDeque<TInfo>::DeleteItem(TDequeItem* ptr)
{
    if (ptr->prev != nullptr)
    {
        ptr->prev->next = ptr->next;
    }
    else {
        front = ptr->next;
    }

    if (ptr->next != nullptr) {
        ptr->next->prev = ptr->prev;
    }
    else {
        rear = ptr->prev;
    }

    delete ptr;
    --size;
}

/*================================================================================*/
/*=================== указатель на элемент с заданным индексом ===================*/
/*================================================================================*/
template<typename TInfo>
void* TDeque<TInfo>::PtrByIndex(unsigned index) const
{
    if (index >= size) {
        throw std::out_of_range("Index out of range!!!");
    }

    TDequeItem* current = front;
    for (unsigned i = 0; i < index; ++i) {
        current = current->next;
    }
    return current;
}

/*================================================================================*/
/*=========================== Конструктор по умолчанию ===========================*/
/*================================================================================*/
template<typename TInfo>
TDeque<TInfo>::TDeque() : front(nullptr), rear(nullptr), size(0) {}

/*================================================================================*/
/*============================ Конструктор копирования ===========================*/
/*================================================================================*/
template<typename TInfo>
TDeque<TInfo>::TDeque(const TDeque& rhs) : front(nullptr), rear(nullptr), size(0) {
    Clone(rhs);
}

/*================================================================================*/
/*================================== деструктор ==================================*/
/*================================================================================*/
template<typename TInfo>
TDeque<TInfo>::~TDeque()
{
    Erase();
}

/*================================================================================*/
/*======================== включить элемент в голову дека ========================*/
/*================================================================================*/
template<typename TInfo>
void TDeque<TInfo>::InsFront(TInfo info)
{
    TDequeItem* newItem = new TDequeItem(info, front, nullptr);
    if (front != nullptr)
    {
        front->prev = newItem;
    }
    else
    {
        rear = newItem;
    }
    front = newItem;
    ++size;
}

/*================================================================================*/
/*========================= включить элемент в хвост дека ========================*/
/*================================================================================*/
template<typename TInfo>
void TDeque<TInfo>::InsRear(TInfo info)
{
    TDequeItem* newItem = new TDequeItem(info, nullptr, rear);
    if (rear != nullptr)
    {
        rear->next = newItem;
    }
    else
    {
        front = newItem;
    }
    rear = newItem;
    ++size;
}

/*================================================================================*/
/*======================= исключить элемент из головы дека =======================*/
/*================================================================================*/
template<typename TInfo>
bool TDeque<TInfo>::DelFront(TInfo& info)
{
    if (size == 0) return false;

    TDequeItem* item = front;

    info = item->Info;

    front = front->next;

    if (front != nullptr) { front->prev = nullptr; } // если не дек пустой - устанавливаем указатель на предыдущий как nullptr
    else { rear = nullptr; } // Если пустой - указатель на следующий nullptr

    delete item;
    --size;
    return true;
}

/*================================================================================*/
/*======================= исключить элемент из хвоста дека =======================*/
/*================================================================================*/
template<typename TInfo>
bool TDeque<TInfo>::DelRear(TInfo& info)
{
    if (size == 0) return false;

    TDequeItem* item = rear;

    info = item->Info;

    rear = rear->prev;

    if (rear != nullptr) { rear->next = nullptr; } // если не дек пустой - устанавливаем указатель на предыдущий как nullptr
    else { front = nullptr; } // Если пустой - указатель на следующий nullptr

    delete item;
    --size;
    return true;
}

/*================================================================================*/
/*============================= оператор присваивания ============================*/
/*================================================================================*/
template<typename TInfo>
const TDeque<TInfo>& TDeque<TInfo>::operator=(const TDeque& rhs)
{
    if (this != &rhs)
    {
        this->Erase();
        this->Clone(rhs);
    }
    return *this;
}

/*================================================================================*/
/*========================== получить элемент по индексу =========================*/
/*================================================================================*/
template<typename TInfo>
const TInfo& TDeque<TInfo>::GetByIndex(unsigned ind) const
{
    if (ind >= size) {
        throw std::out_of_range("Entered an incorrect index");
    }

    TDequeItem* iter = front;
    size_t temp = 0;
    while (iter != nullptr)
    {
        if (temp == ind)
        {
            return iter->Info;
        }
        ++temp;
        iter = iter->next;
    }
    throw std::out_of_range("Entered an incorrect index");
}

/*================================================================================*/
/*========================== изменить элемент по индексу =========================*/
/*================================================================================*/

template<typename TInfo>
void TDeque<TInfo>::SetByIndex(TInfo data, unsigned ind)
{
    if (ind >= size) {
        throw std::out_of_range("Entered an incorrect index");
    }

    TDequeItem* iter = front;
    size_t temp = 0;
    while (iter != nullptr)
    {
        if (temp == ind)
        {
            iter->Info = data;
            return;
        }
        ++temp;
        iter = iter->next;
    }
    throw std::out_of_range("Entered an incorrect index");
}

/*================================================================================*/
/*======================== просмотр с изменением элементов =======================*/
/*================================================================================*/

template<typename TInfo>
void TDeque<TInfo>::Browse(void(*func)(TInfo&))
{
    TDequeItem* iter = front;
    while (iter != nullptr)
    {
        func(iter->Info);
        iter = iter->next;
    }
    std::cout << '\n';
}

/*================================================================================*/
/*======================= просмотр без изменения элементов =======================*/
/*================================================================================*/

template<typename TInfo>
void TDeque<TInfo>::Browse(void(*func)(TInfo)) const
{
    TDequeItem* iter = front;
    while (iter != nullptr)
    {
        func(iter->Info);
        iter = iter->next;
    }
    std::cout << '\n';
}

#endif // !TDEQUE_HPP

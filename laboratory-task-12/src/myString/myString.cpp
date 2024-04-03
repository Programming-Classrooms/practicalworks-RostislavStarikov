#define _CRT_SECURE_NO_WARNINGS
#include "src/myString/myString.hpp"

/*====================================================================================*/
/*============================ Конструкторы ==========================================*/
/*====================================================================================*/
myString::myString()
{
	str = new char[1];
	str[0] = '\0';
	len = 0;
}

myString::myString(const char* ptr)
{
	len = strlen(ptr);
	str = new char[len + 1];
	strcpy(str, ptr);
}

myString::myString(const myString& rhs)
{
	len = strlen(rhs.str);
	str = new char[len + 1];
	strcpy(str, rhs.str);
}

myString& myString::operator = (myString& rhs)
{
	if (this == &rhs) return *this;
	len = rhs.len;
	delete[] str;
	str = new char[len + 1];
	strcpy(str, rhs.str);
	return (*this);
}

myString::~myString()
{
	len = 0;
	if (str == nullptr) delete[] str;
}

/*====================================================================================*/
/*================================ Конкатенация ======================================*/
/*====================================================================================*/


myString& myString::operator += (const myString& rhs)
{
	*this = (*this + rhs);
	return *this;
}

myString& myString::operator + (const myString& rhs)
{
	size_t newLen = len + rhs.len;
	char* newStr = new char[newLen + 1];
	strcpy(newStr, str);
	strcat(newStr, rhs.str);
	delete[] str;
	str = newStr;
	len = newLen;
	return *this;
}

/*====================================================================================*/
/*============================ Операторы сравнения ===================================*/
/*====================================================================================*/


bool myString::operator == (const myString& rhs)
{
	if (strlen(str) == strlen(rhs.str))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool myString::operator < (const myString& rhs)
{
	{
		if (strlen(rhs.str) < strlen(str))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool myString::operator > (const myString& rhs)
{
	if (strlen(rhs.str) > strlen(str))
	{
		return true;
	}
	else
	{
		return false;
	}
}bool myString::operator <= (const myString& rhs)
{
	{
		if (strlen(rhs.str) <= strlen(str))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool myString::operator >= (const myString& rhs)
{
	if (strlen(rhs.str) >= strlen(str))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool myString::operator != (const myString& rhs)
{
	return !(operator == (rhs));
}

/*====================================================================================*/
/*================================== Геттеры =========================================*/
/*====================================================================================*/


const char* myString::getStr() const
{
	char* getterStr = new char[len + 1];
	strcpy(getterStr, str);
	return getterStr;
}

size_t myString::getLength() const
{
	return len;
}


/*====================================================================================*/
/*================================ Сеттер ============================================*/
/*====================================================================================*/

void myString::setStr(const char* set)
{
	delete[]str;
	str = new char[strlen(set) + 1];
	strcpy(str, set);
}

/*================================================================================*/
/*=========================== Методы и функции myString ==========================*/
/*================================================================================*/


// Проверка на пустоту строки
bool myString::is_empty()
{
	return str == nullptr || str[0] == '\0';
}

// Поиск первого вхождения символа а в строку s 
int32_t search_first_of(const char a, const myString& s)
{
	size_t size = strlen(s.str);
	for (size_t i = 0; i < size; ++i)
	{
		if (s.str[i] == a)
		{
			return i;
		}
	}
	return -1;
}

// Добавление символа в конец строки
void myString::push_back(const char c)
{
	size_t resultLen = len + 2;
	char* result = new char[resultLen];
	std::strcpy(result, str);
	result[len] = c;
	result[resultLen - 1] = '\0';
	delete[]str;
	str = result;
	++len;
}

/*================================================================================*/
/*=================== Перегрузка оператора вывода и ввода строки =================*/
/*================================================================================*/


std::ostream& operator << (std::ostream& out, const myString& s)
{
	out << s.str;
	return out;
}

std::istream& operator>>(std::istream& in, myString& obj)
{
	char temp[1000];
	in >> temp;
	obj.setStr(temp);
	return in;

}
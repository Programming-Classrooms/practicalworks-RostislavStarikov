#define _CRT_SECURE_NO_WARNINGS
#include "myString.hpp"

String::String() : str(nullptr), len(0)
{}

String::String(const char* ptr)
{
	len = strlen(ptr);
	str = new char[len + 1];
	strcpy(str, ptr);
}

String::String(const String& arr) 
{
	len = arr.size();
	str = new char[len + 1];
	strcpy(str, arr.str);
}

String& String::operator = (String& arr)
{
	if (this != &arr)
	{
		len = arr.len;
		delete[] str;
		str = new char[len + 1];
		strcpy(str, arr.str);
	}
	return (*this);
}

String& String::operator += (const String& arr)
{
	size_t newLen = len + arr.len;
	char* newStr = new char[newLen + 1];
	strcpy(newStr, str);
	strcat(newStr, arr.str);
	delete[] str;
	str = newStr;
	len = newLen;
	return *this;
}

String String::operator+(const String& arr) 
{
    size_t newLen = len + arr.len;
    char* newStr = new char[newLen + 1];
    strcpy(newStr, str);
    strcat(newStr, arr.str);

    String result(newStr);
	
    return result;
}

bool String::operator == (const String& arr) 
{
	return (size() == arr.size());
}

bool String::operator < (const String& arr)
{
	return (size() < arr.size());

}

bool String::operator > (const String& arr)
{
	return !(*this < arr);

}bool String::operator <= (const String& arr)
{
	return (*this < arr && *this == arr);
}

bool String::operator >= (const String& arr)
{
	return (*this > arr && *this == arr);
}

bool String::operator != (const String& arr) 
{
	return !(*this == arr);
}

bool String::is_empty()
{
	return str == 0 || str[0] == '\0';
}

const char* String::getStr()  
{
	return str;
}

size_t String::size() const
{
	return len;
}

int32_t search_first_of(const char a, const String& s)
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

int32_t search_first_of(const String& find, const String& s)
{
	size_t size = strlen(s.str);
	size_t sizeFind = strlen(find.str);
	for (size_t i = 0; i < sizeFind; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			if (s.str[j] == find.str[i])
			{
				return j;
			}
		}
	}
	return -1;
}

std::ostream& operator << (std::ostream& out, const String& s)
{
	out << s.str;
	return out;
}

String::~String()
{
	len = 0;
	delete[] str;
	str = nullptr;
	std::cout << "\nDestruct";
}

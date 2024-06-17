#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#include <iostream>
#include <cstring>

class String
{
private:
	size_t len;
	char* str;
public:

	String();
	String(const char*);
	String(const String&);

	String& operator = (String&);

	String& operator += (const String&);

	String operator + (const String&);

	bool operator == (const String&) ;
	bool operator > (const String&) ;
	bool operator >= (const String&) ;
	bool operator < (const String&) ;
	bool operator <= (const String&) ;
	bool operator != (const String&) ;

	bool is_empty();

	const char* getStr() ;

	size_t size() const;

	friend int32_t search_first_of(const char, const String&);
	friend int32_t search_first_of(const String&, const String&);
	
	friend std::ostream& operator << (std::ostream&, const String&);

	~String();
};
#endif

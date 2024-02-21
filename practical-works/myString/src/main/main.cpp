#include "../fraction/Fraction.hpp"

int main()
{
	//String str1 = String("erty");
	//String str = String("qw");
	String str_check = "Abc";
	String delim = "Abx";
	/*if (str == str1) {
		std::cout << str1 << " and " << str << " are equal.\n";
	}
	if (str > str1) {
		std::cout << str1 << " > " << str << "\n";
	}
	if (str < str1) {
		std::cout << str1 << " < " << str << "\n";
	}
	//str += str1;

	String str2 = str;

	String str3 = str + str1;
	
	std::cout << str3 << '\n';*/
	std::cout << search_first_of('A', str_check) << '\n';
	std::cout << search_first_of("dsdb", str_check) << '\n';
	return 0;
}

#include "../Library/Library.hpp"

int main()
{
	try
	{
    Library library;

    Author author1("Starikov", "Rostislav", "Romanovich");
    Author author2("Soloviev", "Ivan", "Anatolevich");

    AuthorList authorList1;
    authorList1.addAuthor(author1);
    authorList1.addAuthor(author2);

    Book book1(123, authorList1, "What to do after expulsion from university", 2025);
    library.addBook(book1);

    std::cout << library << "\n";

    std::cout << "Search by title 'What to do after expulsion from university':\n";
    library.searchTitle("What to do after expulsion from university");\

	std::cout << "Search by title 'The benefits of << go to >>':\n";
    library.searchTitle("The benefits of << go to >>");

    std::cout << "Search by author 'Starikov':" << std::endl;
    library.searchAuthor(author1);

    library.deleteBook(book1);

    std::cout << "\nLibrary after delete book" << library << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

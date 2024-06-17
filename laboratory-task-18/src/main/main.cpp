#include "../Library/Library.hpp"
#include "../Book/Book.hpp"

int main() {
	try
	{
		Library library;

		Book book1("Book A", {"Author 1", "Author 2"}, 12.34, 5);
		Book book2("Book B", {"Author 3"}, 43.21, 3);
		Book book3("Book C", {"Author 4"}, 11.11, 2);

		library.addBook(book1);
		library.addBook(book2);
		library.addBook(book3);

		std::cout << library;

		std::string findISNB;
		std::cout << "\nВведите ISNB для поиска книги:\t";
		std::cin >> findISNB;
		std::cout << "\nПоиск книги по заданному ISBN: " << findISNB << ":\n";
		std::cout << *library.findBook(book1.ISBN);
		
		std::string author;
		std::cout << "\nВведите ISNB для добавления автора\t";
		std::cin >> findISNB;
		std::cout << "Введите автора для добавления:\t";
		std::getline(std::cin,author);
		std::cout << "\nДобавление автора " << author << "в книгу с ISBN: " << findISNB << ":\n";
		library.addAuthor(findISNB, author);
		std::cout << library;

		std::cout << "\nВведите ISNB для удаления автора\t";
		std::cin >> findISNB;
		std::cout << "Введите автора для удаления:\t";
		std::getline(std::cin,author);
		std::cout << "\nУдаление автора " << author << "из книги с ISBN: " << findISNB << ":\n";
		library.removeAuthor(findISNB, author);
		std::cout << library;

		std::cout << "\nСортировка книг по ISBN:\n";
		library.sortBooksByISBN();

		std::cout << "\nВведите ISNB для удаления книги\t";
		std::cin >> findISNB;
		std::cout << "\nУдаление книги по ISBN: " << findISNB << ":\n";
		library.removeBook(findISNB);
		std::cout << library;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}

#ifndef BOOK_H
#define BOOK_H "BOOK_H"

#include <string>
#include <vector>

class book {
public:

	int id_of_all();

	int id_of_author_book(int const &id_of_book);

	std::string title_finder(int const &id_of_book);

	int show_shelf_ids(int const &requested_id);

	std::vector<int>sort_by_title(std::vector<int>id_of_books);

	std::string book_genre_finder(int const &specific_id);

	void read_from_file(std::string books_address);

	void show_details(int id_of_author);

private:



	std::vector<int> id;
	std::vector<int> author_id;
	std::vector <std::string> title;
	std::vector <std::string> genre;
};




#endif
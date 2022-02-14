#ifndef GOODREADS_H
#define GOODREADS_H "GOODREADS_H"


#include"book.hpp"
#include"user.hpp"
#include"review.hpp"
#include"author.hpp"

class goodreads {
public:

	void recommended_book(int id);

	void show_best_reviewer();

	void show_best_book();

	void show_credit_of_user(int id_of_user);

	std::string author_name_finder(int const &id_of_author);

	void show_sorted_shelf(int const &id,std::string const &shelf_type,std::string const &genre);

	void show_info_of_author(int requested_id);
	
	goodreads(std::string authors_address,std::string books_address,std::string reviews_address,std::string users_address);

private:
	void read_from_users_file(std::string users_address);
	book books;
	std::vector<author>authors;
	std::vector<user>users;
	review reviews;
};

#endif
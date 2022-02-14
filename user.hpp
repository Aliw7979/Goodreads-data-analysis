#ifndef USER_H
#define USER_H "USER_H"


#include<string>
#include<vector>


class user {
public:
	user(int const &id_received, std::string const &name_received, std::string const &place_of_birth_received,
		std::string const &member_since_received, std::vector<int>const &favorite_author_received, std::vector<std::string> const &favorite_genres_received,
		std::vector<int> const &want_to_read_received, std::vector<int>const &currently_read_received, std::vector<int>const &read_received);
	int get_id();

	std::string get_name();

	std::string get_place_of_birth();

	std::string get_member_since();

	std::vector<std::string> get_favorite_genre();

	std::vector<int> get_favorite_authors();

	int number_of_books_in_read();

	int number_of_books_in_want_to_read();

	int number_of_books_in_currently_reading();

	std::vector<int>user_shelf_fetcher(std::string const &shelf_type);

private:
	int id;
	std::string name;
	std::string place_of_birth;
	std::string member_since;
	std::vector<int> favorite_authors;
	std::vector<std::string>favorite_genre;
	std::vector<int>want_to_read;
	std::vector<int>currently_reading;
	std::vector<int>read;

};
#endif
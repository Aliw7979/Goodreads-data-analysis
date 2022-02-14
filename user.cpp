#include"user.hpp"

using namespace std;


user::user(int const &id_received, string const &name_received, string const &place_of_birth_received,
		string const &member_since_received, vector<int>const &favorite_author_received, vector<string> const &favorite_genres_received,
		vector<int> const &want_to_read_received, vector<int>const &currently_read_received, vector<int>const &read_received)
	{

		id = id_received;
		name = name_received;
		place_of_birth = place_of_birth_received;
		member_since = member_since_received;
		favorite_authors = favorite_author_received;
		favorite_genre = favorite_genres_received;
		want_to_read = want_to_read_received;
		currently_reading = currently_read_received;
		read = read_received;
	}
	int user::get_id()
	{
		return id;
	}
	string user::get_name()
	{
		return name;
	}
	string user::get_place_of_birth()
	{
		return place_of_birth;
	}
	string user::get_member_since()
	{
		return member_since;
	}
	vector<string> user::get_favorite_genre()
	{
		return favorite_genre;
	}
	vector<int> user::get_favorite_authors()
	{
		return favorite_authors;
	}
	int user::number_of_books_in_read()
	{
		return read.size();
	}

	int user::number_of_books_in_want_to_read()
	{
		return want_to_read.size();
	}

	int user::number_of_books_in_currently_reading()
	{
		return currently_reading.size();
	}
	vector<int>user::user_shelf_fetcher(string const &shelf_type)
	{
		if (shelf_type == "read")
			return read;
		else if (shelf_type == "want_to_read")
			return want_to_read;
		else if (shelf_type == "currently_reading")
			return currently_reading;

	}
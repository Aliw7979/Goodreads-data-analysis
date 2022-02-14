#include"goodreads.hpp"
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;





	void goodreads::recommended_book(int id) 
    {
		vector<string>favorite_genres_of_user;
		int favorite_genre=0, id_of_best;
		double score = 0, best_score=0;
		for (int i = 0; i < users.size(); i++) {
			if (users[i].get_id() == id) {
				favorite_genres_of_user = users[i].get_favorite_genre();
				break;
			}
		}
		
		for (int id_of_all_books = books.id_of_all()-1; id_of_all_books >= 0; id_of_all_books--) {
			string genre_of_book = books.book_genre_finder(id_of_all_books);

			for (int i = 0; i < favorite_genres_of_user.size(); i++) {
				if (favorite_genres_of_user[i] == genre_of_book)
					favorite_genre = 5;
			}

			double rating = reviews.rating_calculator(id_of_all_books);
			score = rating + favorite_genre;

			if (best_score < score) {
				best_score = score;
				id_of_best = id_of_all_books;
			}
			favorite_genre = 0;

		}
		cout << "id: "<<id_of_best<<endl<<
		"Title: "<<books.title_finder(id_of_best)<<endl<<
		"Genre: "<<books.book_genre_finder(id_of_best)<<endl<<
		"Author: "<<author_name_finder(books.id_of_author_book(id_of_best))<<endl;
		reviews.show_all_reviews_of_book(id_of_best);
 }



	void goodreads::show_best_reviewer()
	{
		int id_of_best, number_of_likes;

		id_of_best = reviews.best_reviewer(number_of_likes);
		

		for (int i = 0; i < users.size(); i++) {
			if (id_of_best == users[i].get_id()) {
				cout << "id: " << id_of_best << endl;
				cout << "Name: " << users[id_of_best].get_name() << endl <<
					"Place of Birth: " << users[i].get_place_of_birth() << endl <<
					"Member Since: " << users[i].get_member_since() << endl;
				vector<string>favorite_genres = users[i].get_favorite_genre();
				cout << "Favorite Genres: ";
				for (int j = 0; j < favorite_genres.size(); j++) {
					cout << favorite_genres[j];
					if (j + 1 != favorite_genres.size()) {
						cout << ", ";
					}
					
				}
				cout << endl;
				vector<int>favorite_authors = users[i].get_favorite_authors();
				cout << "Favorite Authors: ";

				for (int j = favorite_authors.size()-1; j >= 0; j--) {
					cout << author_name_finder(favorite_authors[j]);
					if (j -1 != -1) {
						cout << ", ";
					}
				}
				cout << endl << "Number of Books in Read Shelf: " << users[i].number_of_books_in_read() << endl <<
					"Number of Books in Want to Read Shelf: " << users[i].number_of_books_in_want_to_read() << endl <<
					"Number of Books in Currently Reading Shelf: " << users[i].number_of_books_in_currently_reading() << endl <<
					"Number of Likes: " << number_of_likes << endl;
				break;
			}
		}
	}






	void goodreads::show_best_book()
	{
		float rating_of_best;
		int id_of_best;
		id_of_best = reviews.best_book_average_rating_id(rating_of_best);
		string name_of_author = author_name_finder(books.id_of_author_book(id_of_best));
		cout << "id: " << id_of_best << endl
			<< "Title: " << books.title_finder(id_of_best) << endl
			<< "Genre: " << books.book_genre_finder(id_of_best) << endl
			<< "Author: " << name_of_author << endl
			<< "Average Rating: " << setprecision(3) << rating_of_best << endl;
	}

	void goodreads::show_credit_of_user(int id_of_user)
	{
		float user_credit=reviews.credit_viewer(id_of_user);
		cout << setprecision(4) << user_credit<<endl;
	}

	string goodreads::author_name_finder(int const &id_of_author)
	{

		for (int i = 0; i < authors.size(); i++) {
			if (id_of_author == authors[i].get_id())
				return authors[i].get_name();
		}
	}


	void goodreads::show_sorted_shelf(int const &id, string const &shelf_type, string const &genre)
	{
		vector<int>match_genre_ids;
		vector<int>unmatch_genre_ids;
		vector<int>specific_shelf;
		for (int i = 0; i < users.size(); i++) {
			if (id == users[i].get_id()) {
				specific_shelf = users[i].user_shelf_fetcher(shelf_type);
				break;
			}
		}
		for (int i = 0; i < specific_shelf.size(); i++) {
			if (genre == books.book_genre_finder(specific_shelf[i])) {
				match_genre_ids.push_back(specific_shelf[i]);
			}
			else {
				unmatch_genre_ids.push_back(specific_shelf[i]);
			}
		}
		match_genre_ids = books.sort_by_title(match_genre_ids);
		unmatch_genre_ids = books.sort_by_title(unmatch_genre_ids);

		for (int i = 0; i < match_genre_ids.size(); i++) {
			int author_id = books.show_shelf_ids(match_genre_ids[i]);
			cout << "Author: " << author_name_finder(author_id) << endl << "***" << endl;
		}

		for (int i = 0; i < unmatch_genre_ids.size(); i++) {
			int author_id = books.show_shelf_ids(unmatch_genre_ids[i]);
			cout << "Author: " << author_name_finder(author_id) << endl << "***" << endl;
		}

	}

	void goodreads::show_info_of_author(int requested_id)
	{
		for (int i = 0; i < authors.size(); i++) {
			int id_of_author = authors[i].get_id();
			if (id_of_author == requested_id) {
				authors[i].show_author_info();
				books.show_details(i);
				break;
			}
		}
	}
	goodreads::goodreads(string authors_address,string books_address,string reviews_address,string users_address)
	{
		int id, year;

		int num_of_row = 0;
		string oneline, temp, name, gender, member_since, place_of_birth, genres;
		ifstream authors_file(authors_address);
		authors_file.ignore(1000, '\n');
		while (getline(authors_file, oneline)) {

			stringstream line(oneline);
			getline(line, temp, ',');
			id = stoi(temp);
			temp.clear();

			getline(line, temp, ',');
			name = temp;
			temp.clear();

			getline(line, temp, ',');
			gender = temp;
			temp.clear();

			getline(line, temp, ',');
			member_since = temp;
			temp.clear();

			getline(line, temp, ',');
			year = stoi(temp);
			temp.clear();

			getline(line, temp, ',');
			place_of_birth = temp;
			temp.clear();


			getline(line, temp, '\n');
			genres = temp;
			num_of_row += 1;
			authors.push_back(author(id, name, gender, member_since, year, place_of_birth, genres));

		}
		books.read_from_file(books_address);
		read_from_users_file(users_address);
		reviews.read_from_file(reviews_address);
	}

	void goodreads::read_from_users_file(string users_address)
	{
		int id;
		vector<int>favorite_author, want_to_read, currently_read, read;
		vector<string>favorite_genres;

		string oneline, temp, name, place_of_birth, member_since;
		ifstream authors_file(users_address);
		authors_file.ignore(1000, '\n');
		while (getline(authors_file, oneline)) {

			stringstream line(oneline);
			getline(line, temp, ',');
			id = stoi(temp);
			temp.clear();


			getline(line, temp, ',');
			name = temp;
			temp.clear();

			getline(line, temp, ',');
			place_of_birth = temp;
			temp.clear();

			getline(line, temp, ',');
			member_since = temp;
			temp.clear();

			getline(line, temp, ',');
			stringstream all_of_favorites_with_delimiter(temp);
			temp.clear();
			while (getline(all_of_favorites_with_delimiter, temp, '$')) {
				favorite_author.push_back(stoi(temp));
				temp.clear();
			}

			getline(line, temp, ',');
			stringstream all_of_favorite_genres_with_delimiter(temp);
			temp.clear();
			while (getline(all_of_favorite_genres_with_delimiter, temp, '$')) {
				favorite_genres.push_back(temp);
				temp.clear();
			}

			getline(line, temp, ',');
			stringstream all_of_wants_with_delimiter(temp);
			temp.clear();
			while (getline(all_of_wants_with_delimiter, temp, '$')) {
				want_to_read.push_back(stoi(temp));
				temp.clear();
			}

			getline(line, temp, ',');
			stringstream all_of_currents_with_delimiter(temp);
			temp.clear();
			while (getline(all_of_currents_with_delimiter, temp, '$')) {
				currently_read.push_back(stoi(temp));
				temp.clear();
			}

			getline(line, temp, ',');
			stringstream all_of_reads_with_delimiter(temp);
			
			temp.clear();
			while (getline(all_of_reads_with_delimiter, temp, '$')) {
				
				read.push_back(stoi(temp));
				temp.clear();
			}
			

			users.push_back(user(id, name, place_of_birth, member_since, favorite_author, favorite_genres, want_to_read,
				currently_read, read));
			favorite_author.clear();
			want_to_read.clear();
			currently_read.clear();
			read.clear();
			favorite_genres.clear();

		}
	}